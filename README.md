<div id="top"></div>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
![Languages][languages-shield]

<br />
<div align="center">
  <a href="https://github.com/josecarlosmemo/syntax-highlighter">
    <img src="https://upload.wikimedia.org/wikipedia/commons/4/47/Logo_del_ITESM.svg" alt="Logo" width="80" height="80">
  </a>
<h3 align="center">Syntax Highlighter (C++, C, JS)</h3>
This is a syntax-highlighter was made for the class Implementation of
Computational Methods, using FLEX (fast lexical analyzer generator) and
C++.
  <p align="center">
    <br />
            <a href="https://github.com/josecarlosmemo/syntax-highlighter"><strong>Explore the docs »</strong></a>
            <br />
    <br />
    <a href="https://github.com/josecarlosmemo/syntax-highlighter/issues">Report Bug</a>
    ·
    <a href="https://github.com/josecarlosmemo/syntax-highlighter/issues">Request Feature</a>
          </p>
</div>

### Built With

<div>
<img src="https://skillicons.dev/icons?i=cpp"/>
</div>

<p align="right">(<a href="#top">back to top</a>)</p>

**Author:** [José Carlos Martínez Núñez \|
A01639664](https://github.com/josecarlosmemo)

## Table of Contents

- [Table of Contents](#table-of-contents)
- [Lexical Categories](#lexical-categories)
- [Color Schemes](#color-schemes)
  - [Dracula](#dracula)
  - [Rainbow](#rainbow)
- [Installation](#installation)
- [Usage/Examples](#usageexamples)
- [The implemented algorithms and their execution time](#the-implemented-algorithms-and-their-execution-time)
- [Screenshots](#screenshots)
- [Time Complexity](#time-complexity)
  - [How does FLEX work?](#how-does-flex-work)
  - [Other Algorithms](#other-algorithms)
- [The SpeedUp by using multiple threads](#the-speedup-by-using-multiple-threads)
  - [Using One Thread](#using-one-thread)
  - [Using 8 Threads](#using-8-threads)
  - [Calculating the SpeedUp](#calculating-the-speedup)
- [Ethical Implications that this type of technology could have on society](#ethical-implications-that-this-type-of-technology-could-have-on-society)
  - [Lexical Analysis](#lexical-analysis)
  - [Multiproccessing / Parallel Programming](#multiproccessing--parallel-programming)
- [Acknowledgments](#acknowledgments)
- [References](#references)
- [Contributing](#contributing)

## Lexical Categories

The Lexical Categories supported by this program are:

- Preprocessor Keywords
- Reserved Words
- Types
- Operators
- Booleans
- Grouping Characters
- Multi Line Comments
- Single Line Comments
- Strings
- Function Names
- Class Identifiers
- Identifiers
- Package Names

These are all matched with their respective regular expressions in the
**Lexer.l** file.

## Color Schemes

The syntax-highlighter supports two color schemes for each lexical
category:

### Dracula

| Token                 | Color                                                                                         |
|-----------------------|-----------------------------------------------------------------------------------------------|
| Preprocessor Keywords | ![\#ff79c6](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=ff79c6) \#ff79c6 |
| Reserved Words        | ![\#ff79c6](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=ff79c6) \#ff79c6 |
| Types                 | ![\#ff79c6](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=ff79c6) \#ff79c6 |
| Operators             | ![\#ff79c6](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=ff79c6) \#ff79c6 |
| Booleans              | ![\#bd93f9](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=bd93f9) \#bd93f9 |
| Grouping Characters   | ![\#ffb86c](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=ffb86c) \#ffb86c |
| Multi Line Comments   | ![\#6272a4](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=6272a4) \#6272a4 |
| Single Line Comments  | ![\#6272a4](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=6272a4) \#6272a4 |
| Strings               | ![\#f1fa8c](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=f1fa8c) \#f1fa8c |
| Function Names        | ![\#50fa7b](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=50fa7b) \#50fa7b |
| Class Identifiers     | ![\#8be9fd](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=8be9fd) \#8be9fd |
| Identifiers           | ![\#f8f8f2](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=f8f8f2) \#f8f8f2 |
| Package Names         | ![\#f1fa8c](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=f1fa8c) \#f1fa8c |

### Rainbow

| Token                 | Color                                                                                         |
|-----------------------|:----------------------------------------------------------------------------------------------|
| Preprocessor Keywords | ![\#00e9b0](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=00e9b0) \#00e9b0 |
| Reserved Words        | ![\#feb300](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=feb300) \#feb300 |
| Types                 | ![\#306cc9](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=306cc9) \#306cc9 |
| Operators             | ![\#00ff00](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=00ff00) \#00ff00 |
| Booleans              | ![\#18b646](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=18b646) \#18b646 |
| Grouping Characters   | ![\#e8002e](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=e8002e) \#e8002e |
| Multi Line Comments   | ![\#81800c](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=81800c) \#81800c |
| Single Line Comments  | ![\#ffff00](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=ffff00) \#ffff00 |
| Strings               | ![\#00aeae](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=00aeae) \#00aeae |
| Function Names        | ![\#65ecb1](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=65ecb1) \#65ecb1 |
| Class Identifiers     | ![\#e4f4df](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=e4f4df) \#e4f4df |
| Identifiers           | ![\#ba00ff](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=ba00ff) \#ba00ff |
| Package Names         | ![\#903a47](https://www.colorbook.io/imagecreator.php?width=10&height=10&hex=903a47) \#903a47 |

## Installation

``` sh
  # Generate Lexical Analyzer
  flex Lexer.l
  # Compile Generated Analyzer with the main.cpp
  g++ -pthread -std=c++17 Lexer.cpp main.cpp -o "syntax-highlighter"
```

## Usage/Examples

``` sh
./syntax-highlighter [FILE | DIRECTORY]
```

**The output file will be saved in output/\[FILE \| DIRECTORY\].html.**

## The implemented algorithms and their execution time

Once the program opens a file, the lexical analyzer will loop through
each character, once a match is found the resulting string will be HTML
encoded, once again looping through each matched character and replacing
every HTML specific symbol (\<, \>, etc.) with their respective
alternatives. Then depending on the selected color scheme it’ll assign a
color to the specific matched string and write it to the output file.

The output of the program is an html document with the lexical
categories in their respective colors. The console output will be the
execution time of the program measured in milliseconds.

**Note:** The execution time of the program will vary depending on your
computer specs.

## Screenshots

The following example files are located in the **examples** folder.

| ![](images/dracula_example_js.png) | ![](images/rainbow_example_js.png) |
|------------------------------------|------------------------------------|

<p align="center">
**“example.js” Execution Time 2 milliseconds**
</p>

| ![](images/dracula_example_cpp.png) | ![](images/rainbow_example_cpp.png) |
|-------------------------------------|-------------------------------------|

<p align="center">
**“example.cpp” Execution Time 1 milliseconds**
</p>

| ![](images/dracula_example_c.png) | ![](images/rainbow_example_c.png) |
|-----------------------------------|-----------------------------------|

<p align="center">
**“example.c” Execution Time 1 milliseconds**
</p>

## Time Complexity

### How does FLEX work?

Flex (fast lexical analyzer generator) is a free and open-source
software alternative to lex. It is a computer program that generates
lexical analyzers (also known as “scanners” or “lexers”).

A Flex lexical analyzer usually has time complexity *O*(*n*) in the
length of the input. That is, it performs a constant number of
operations for each input symbol.

### Other Algorithms

Apart from the code generated by the lexical analyzer once a token is
matched we run another *O*(*n*) algorithm to remove any HTML special
characters.

**This means that the total time complexity of the whole program is
*O*(*n*<sup>2</sup>).**

Nevertheless, as seen in the last section the program runs fairly fast.

## The SpeedUp by using multiple threads

For these tests a total of **898 files** were used (located at
`/examples` folder) with a total of **320 different subfolders** divided
among the three languages JavaScript, C and C++.

### Using One Thread

![Converting all files located in `/examples` using one
thread](images/one_thread.png)

As seen in the image the total time taken to convert all files was
**9313 milliseconds.**

### Using 8 Threads

![Converting all files located in `/examples` using eight
thread](images/8_threads.png)

As seen in the image the total time taken to convert all files was
**4634 milliseconds.**

### Calculating the SpeedUp

The SpeedUp of a program is calculated by the following formula:

![S_p = \frac{T_1}{T_p}](https://latex.codecogs.com/png.latex?\bg{white}\dpi{200}S_p%20%3D%20%5Cfrac%7BT_1%7D%7BT_p%7D "S_p = \frac{T_1}{T_p}")

Where:

- ![p](https://latex.codecogs.com/png.latex?\bg{white}\dpi{200}p "p")
    is the number of processors (or cores)
- ![T_1](https://latex.codecogs.com/png.latex?\bg{white}\dpi{200}T_1 "T_1")
    is the time taken to execute the single processor version of the
    program
- ![T_p](https://latex.codecogs.com/png.latex?\bg{white}\dpi{200}T_p "T_p")
    is the time taken to execute the multi-processor version of the
    program using
    ![p](https://latex.codecogs.com/png.latex?\bg{white}\dpi{200}p "p")
    processors
- Lastly,
    ![S_p](https://latex.codecogs.com/png.latex?\bg{white}\dpi{200}S_p "S_p")
    is the SpeedUp obtained by using
    ![p](https://latex.codecogs.com/png.latex?\bg{white}\dpi{200}p "p")
    processors.

Using the above formula we can calculate the **SpeedUp** using a total
of *8 threads*.

![S_p = \frac{9313 \text{ms}}{4634 \text{ms}}\approx 2](https://latex.codecogs.com/png.latex?\bg{white}\dpi{200}S_p%20%3D%20%5Cfrac%7B9313%20%5Ctext%7Bms%7D%7D%7B4634%20%5Ctext%7Bms%7D%7D%5Capprox%202 "S_p = \frac{9313 \text{ms}}{4634 \text{ms}}\approx 2")

We can conclude that by using *8 threads* we practically **doubled** the
speed of our program.

## Ethical Implications that this type of technology could have on society

### Lexical Analysis

This type of technology has many uses apart from creating syntax
highlighters, technologies like Flex allow us to create lexical
analyzers that can be used for all types of purposes from creating our
own interpreters for other programming languages to automating lots of
processes that require identification of tokens. One example of how
these technologies can help society is analyzing laws to fix ambiguous
wording or in the research field to analyze dead languages from our past
so that understand more about other civilizations. Performing all these
tasks with the help of computers will greatly improve the amount of time
it’ll take to do this manually. It is incredibly important that
technologies like these are used for good and not personal gain.

### Multiproccessing / Parallel Programming

This technology has incredible implications on society as it can
basically speed up most actions that take a long time in all programming
aplications. Using the example stated above this type of technology can
seriously speed up the process of analyzing languages, making it so that
we can perform the advances stated above orders of magnitude faster,
taking advantage of all the computer power at our disposal.

## Acknowledgments

The following GitHub repos were used as example code for this program:

- [@mandliya/algorithms_and_data_structures](https://github.com/mandliya/algorithms_and_data_structures)
- [@TheAlgorithms/C](https://github.com/TheAlgorithms/C)
- [@trekhleb/javascript-algorithms](https://github.com/trekhleb/javascript-algorithms)

## References

- Funchal, G. (2011, April 14). Most efficient way to escape XML/HTML
    in C++ string?. Stack Overflow.
    <a href="https://stackoverflow.com/a/5665377" class="uri">https://stackoverflow.com/a/5665377</a>

- Levine, John R.; Mason, Tony; Brown, Doug (1992). lex & yacc (2nd
    ed.). O’Reilly. p. 279. ISBN 1-56592-000-7. A freely available
    version of lex is flex.

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>

[contributors-shield]: https://img.shields.io/github/contributors/josecarlosmemo/syntax-highlighter.svg?style=for-the-badge
[contributors-url]: https://github.com/josecarlosmemo/syntax-highlighter/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/josecarlosmemo/syntax-highlighter.svg?style=for-the-badge
[forks-url]: https://github.com/josecarlosmemo/syntax-highlighter/network/members
[stars-shield]: https://img.shields.io/github/stars/josecarlosmemo/syntax-highlighter.svg?style=for-the-badge
[stars-url]: https://github.com/josecarlosmemo/syntax-highlighter/stargazers
[issues-shield]: https://img.shields.io/github/issues/josecarlosmemo/syntax-highlighter.svg?style=for-the-badge
[issues-url]: https://github.com/josecarlosmemo/syntax-highlighter/issues
[languages-shield]: https://img.shields.io/github/languages/count/josecarlosmemo/syntax-highlighter.svg?style=for-the-badge
