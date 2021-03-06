#include "Tokens.h"
#include "Color.h"
#include <FlexLexer.h>
#include <fstream>
#include <string>
#include <chrono>
#include <filesystem>
#include <thread>
#include <vector>

#define NUM_THREADS 8

using namespace std;
namespace fs = std::filesystem;

// Función que nos permite encodear caracteres especiales de HTML
// Autor: Giovanni Funchal
// Referencia: https://stackoverflow.com/a/5665377
void encode(std::string &data)
{
    std::string buffer;
    buffer.reserve(data.size());
    for (size_t pos = 0; pos != data.size(); ++pos)
    {
        switch (data[pos])
        {
        case '&':
            buffer.append("&amp;");
            break;
        case '\"':
            buffer.append("&quot;");
            break;
        case '\'':
            buffer.append("&apos;");
            break;
        case '<':
            buffer.append("&lt;");
            break;
        case '>':
            buffer.append("&gt;");
            break;
        default:
            buffer.append(&data[pos], 1);
            break;
        }
    }
    data.swap(buffer);
}

void outputFile(fs::path fileName)
{
    // Iniciamos con el reloj
    auto start = std::chrono::high_resolution_clock::now();
    yyFlexLexer *lexer;
    ifstream *input;
    ofstream output;
    ColorScheme scheme = Dracula;
    input = new ifstream(fileName);

    fs::create_directories("output/" + fileName.parent_path().string());

    string outputFileName = "output/" + fileName.string() + ".html";

    // Creamos el archivo al cual escribir
    output.open(outputFileName);
    // Inicializamos Lexer
    lexer = new yyFlexLexer(input);

    // Agregamos header al archivo html
    output << "<!DOCTYPE html>\n<html>\n  <head>\n\t<link rel=\"preconnect\" href=\"https://fonts.googleapis.com\" />\n\t<link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin />\n\t<link\n\t  href=\"https://fonts.googleapis.com/css2?family=Source+Code+Pro&display=swap\"\n\t  rel=\"stylesheet\"\n\t/>\n\t<meta charset=\"UTF-8\" />\n\t<title>" << fileName << "</title>\n\t<style>\n\t  html {\n\t\tbackground-color: #181920;\n\t\tfont-family: \"Source Code Pro\", monospace;\n\t\tcolor: #f8f8f2;\n\t  }\n\t</style>\n  </head>\n  <body style=\"margin-top: 3rem; margin-left: 3rem\">\n\t<div>\n\t  <img\n\t\tsrc=\"https://javier.rodriguez.org.mx/itesm/2014/tecnologico-de-monterrey-blue.png\"\n\t\talt=\"Logo-Tec\"\n\t\twidth=\"20%\"\n\t  />\n\t  <p>José Carlos Martínez Núñez</p>\n\t  <p>A01639664</p>\n\t</div>\n\t<div\n\t  style=\"\n\t\tmargin: 5rem;\n\t\tpadding: 3rem;\n\t\tbackground-color: #282a36;\n\t\tborder-radius: 25px;\n\t  \"\n\t>";

    int token;
    token = lexer->yylex();

    while (token)
    {
        string currentString = lexer->YYText();
        encode(currentString);
        switch (token)
        {
        case RESERVED:
            output << "\t<span style=\"color: " << colors[scheme][RESERVED] << ";\">" << currentString << "</span>\n";
            break;

        case IDENTIFIER:
            output << "\t<span style=\"color: " << colors[scheme][IDENTIFIER] << ";\">" << currentString << "</span>\n";

            break;

        case STRING:
            output << "\t<span style=\"color: " << colors[scheme][STRING] << ";\">" << currentString << "</span>\n";
            break;

        case NUMBER:
            output << "\t<span style=\"color: " << colors[scheme][NUMBER] << ";\">" << currentString << "</span>\n";

            break;

        case OPERATOR:
            output << "\t<span style=\"color: " << colors[scheme][OPERATOR] << ";\">" << currentString << "</span>\n";

            break;

        case COMMENT:
            output << "\t<span style=\"color: " << colors[scheme][COMMENT] << ";\">" << currentString << "</span>\n";

            break;

        case MULTICOMMENT:
            output << "\t<span style=\"color: " << colors[scheme][MULTICOMMENT] << ";\">" << currentString << "</span>\n";

            break;

        case CLASS:
            output << "\t<span style=\"color: " << colors[scheme][CLASS] << ";\">" << currentString << "</span>\n";

            break;
        case PREPROCESOR:
            output << "\t<span style=\"color: " << colors[scheme][PREPROCESOR] << ";\">" << currentString << "</span>\n";
            break;
        case BOOLEAN:
            output << "\t<span style=\"color: " << colors[scheme][BOOLEAN] << ";\">" << currentString << "</span>\n";
            break;
        case GROUPING:
            output << "\t<span style=\"color: " << colors[scheme][GROUPING] << ";\">" << currentString << "</span>\n";
            break;
        case FUNCTIONS:
            output << "\t<span style=\"color: " << colors[scheme][FUNCTIONS] << ";\">" << currentString << "</span>\n";
            break;
        case PACKAGES:
            output << "\t<span style=\"color: " << colors[scheme][PACKAGES] << ";\">" << currentString << "</span>\n";
            break;
        case TYPES:
            output << "\t<span style=\"color: " << colors[scheme][TYPES] << ";\">" << currentString << "</span>\n";
            break;
        case NEWLINE:
            output << "\t<br/>\n";
            break;

        case TAB:
            output << "\t<span>&nbsp;&nbsp;&nbsp;&nbsp;</span>\n";
            break;

        default:
            output << "\t<span style=\"color: " << colors[scheme][DEFAULT] << ";\">" << currentString << "</span>\n";
            break;
        }

        token = lexer->yylex();
    }

    // Cerramos archivos de entrada y de salida.

    input->close();
    output.close();

    // Paramos el reloj y terminamos el programa

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "File: " << fileName << endl
         << "Finished processing in " << duration.count() << " microseconds." << endl;
}

vector<vector<fs::path>> divideEvenly(vector<fs::path> lst, size_t n)
{
    vector<vector<fs::path>> results;
    size_t chunk_size = lst.size() / n;
    size_t remainder = lst.size() % n;

    size_t begin = 0;
    size_t end = 0;

    for (size_t i = 0; i < min(n, lst.size()); i++)
    {
        end += (remainder > 0) ? (chunk_size + !!(remainder--)) : chunk_size;
        results.push_back(vector<fs::path>(lst.begin() + begin, lst.begin() + end));
        begin = end;
    }

    return results;
}

bool validateFile(const char *fileName)
{

    if (FILE *file = fopen(fileName, "r"))
    {
        fclose(file);

        return true;
    }
    else
    {

        return false;
    }
}

void outputChunk(vector<fs::path> files)
{
    if (files.size() >= 1)
    {

        for (fs::path file : files)
        {
            outputFile(file);
        }
    }
}

vector<fs::path> getListOfFiles(const fs::path &path)
{
    vector<fs::path> lst;
    for (const auto &p : fs::recursive_directory_iterator(path))
    {
        if (!fs::is_directory(p))
        {

            if (validateFile(p.path().c_str()))
            {
                lst.push_back(p.path());
            }
            else
            {
                cout << endl
                     << "Could not open file: " << p.path() << endl;
            }
        }
    }
    return lst;
}

int main(int argc, char const *argv[])
{
    argv[1] = "examples/";
    argc = 2;
    auto start = std::chrono::high_resolution_clock::now();

    // Revisamos input como argumento de main si no se ingresa, se marca el error y terminamos ejecución.

    ++argv, --argc;
    if (argc > 0)
    {
        cout << "Processing using " << NUM_THREADS << " thread(s): ";

        // Si no es una carpeta

        if (!fs::is_directory(argv[0]))
        {

            if (!validateFile(argv[0]))
            {

                cout << endl
                     << "Unable to find file " << argv[0] << endl
                     << "Terminating..." << endl;
                return 1;
            }

            cout << argv[0] << endl
                 << endl;

            outputFile(argv[0]);
        }
        else
        {
            vector<thread> threads;

            cout << argv[0] << endl
                 << endl;

            for (vector<fs::path> &chunk : divideEvenly(getListOfFiles(argv[0]), NUM_THREADS))
            {
                threads.push_back(thread(outputChunk, chunk));
            }

            for (auto &th : threads)
            {
                th.join();
            }
        }
    }
    else
    {
        cout << "Missing File Argument" << endl
             << "Terminating..." << endl;
        return 1;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout << "Done!" << endl
         << "Finished in " << duration.count() << " milliseconds." << endl;
}
