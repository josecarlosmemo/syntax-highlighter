#ifndef __TOKENS_H__
#define __TOKENS_H__
enum Tokens
{
    RESERVED = 1, // Palabras reservadas: def, enum, define, etc.

    IDENTIFIER, // Nombres de variables, etc.

    STRING, // Strings

    NUMBER, // Números, enteros y flotantes.

    OPERATOR, // Operadores

    COMMENT, // Comentarios

    MULTICOMMENT, // Comentario de Varias Lineas /*  */

    CLASS, // Clases

    PREPROCESOR, // Palabras reservadas que comienzan con #: #define, #elif, etc.

    BOOLEAN, // Valores Booleanos: True, False.

    GROUPING, // Caracteres Agrupadores: (), {}, [].

    FUNCTIONS, // Nombres de funciones

    PACKAGES, // Nombre de paquetes en C y C++: <string>

    TYPES, // Tipos de datos

    DEFAULT, // Texto Normal


    /* Tokens Auxiliares */

    NEWLINE,

    TAB, // Tabs o 4 Espacios juntos



};

#endif // __TOKENS_H__