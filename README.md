<img src="./images/Logo_Tec_README.png" title="" alt="Logo" data-style="font-weight:bold;">

---

# Syntax Highlighter (C++, C, JS)

This is a syntax-highlighter was made for the class Implementation of
Computational Methods, using FLEX (fast lexical analyzer generator) and
C++.

**Author:** [José Carlos Martínez Núñez | A01639664](https://github.com/josecarlosmemo)

## Table of Contents

- [Syntax Highlighter (C++, C, JS)](#syntax-highlighter-c-c-js)
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
  - [Ethical Implications that this type of technology could have on society](#ethical-implications-that-this-type-of-technology-could-have-on-society)
  - [References](#references)

---

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

---

## Color Schemes

The syntax-highlighter supports two color schemes for each lexical
category:

### Dracula

| Token                 | Color                                                             |
| --------------------- | ----------------------------------------------------------------- |
| Preprocessor Keywords | ![#ff79c6](https://via.placeholder.com/10/ff79c6?text=+) \#ff79c6 |
| Reserved Words        | ![#ff79c6](https://via.placeholder.com/10/ff79c6?text=+) \#ff79c6 |
| Types                 | ![#ff79c6](https://via.placeholder.com/10/ff79c6?text=+) \#ff79c6 |
| Operators             | ![#ff79c6](https://via.placeholder.com/10/ff79c6?text=+) \#ff79c6 |
| Booleans              | ![#bd93f9](https://via.placeholder.com/10/bd93f9?text=+) \#bd93f9 |
| Grouping Characters   | ![#ffb86c](https://via.placeholder.com/10/ffb86c?text=+) \#ffb86c |
| Multi Line Comments   | ![#6272a4](https://via.placeholder.com/10/6272a4?text=+) \#6272a4 |
| Single Line Comments  | ![#6272a4](https://via.placeholder.com/10/6272a4?text=+) \#6272a4 |
| Strings               | ![#f1fa8c](https://via.placeholder.com/10/f1fa8c?text=+) \#f1fa8c |
| Function Names        | ![#50fa7b](https://via.placeholder.com/10/50fa7b?text=+) \#50fa7b |
| Class Identifiers     | ![#8be9fd](https://via.placeholder.com/10/8be9fd?text=+) \#8be9fd |
| Identifiers           | ![#f8f8f2](https://via.placeholder.com/10/f8f8f2?text=+) \#f8f8f2 |
| Package Names         | ![#f1fa8c](https://via.placeholder.com/10/f1fa8c?text=+) \#f1fa8c |

### Rainbow

| Token                 | Color                                                             |
| --------------------- | :---------------------------------------------------------------- |
| Preprocessor Keywords | ![#00e9b0](https://via.placeholder.com/10/00e9b0?text=+) \#00e9b0 |
| Reserved Words        | ![#feb300](https://via.placeholder.com/10/feb300?text=+) \#feb300 |
| Types                 | ![#306cc9](https://via.placeholder.com/10/306cc9?text=+) \#306cc9 |
| Operators             | ![#00ff00](https://via.placeholder.com/10/00ff00?text=+) \#00ff00 |
| Booleans              | ![#18b646](https://via.placeholder.com/10/18b646?text=+) \#18b646 |
| Grouping Characters   | ![#e8002e](https://via.placeholder.com/10/e8002e?text=+) \#e8002e |
| Multi Line Comments   | ![#81800c](https://via.placeholder.com/10/81800c?text=+) \#81800c |
| Single Line Comments  | ![#ffff00](https://via.placeholder.com/10/ffff00?text=+) \#ffff00 |
| Strings               | ![#00aeae](https://via.placeholder.com/10/00aeae?text=+) \#00aeae |
| Function Names        | ![#65ecb1](https://via.placeholder.com/10/65ecb1?text=+) \#65ecb1 |
| Class Identifiers     | ![#e4f4df](https://via.placeholder.com/10/e4f4df?text=+) \#e4f4df |
| Identifiers           | ![#ba00ff](https://via.placeholder.com/10/ba00ff?text=+) \#ba00ff |
| Package Names         | ![#903a47](https://via.placeholder.com/10/903a47?text=+) \#903a47 |

---

## Installation

```bash
  # Generate Lexical Analyzer
  flex Lexer.l
  # Compile Generated Analyzer with the main.cpp
  g++ -std=c++17 Lexer.cpp main.cpp -o "syntax-highlighter"
```

## Usage/Examples

```bash
./syntax-highlighter FILE
```

**The output file will be saved in FILE.html.**

---

## The implemented algorithms and their execution time

Once the program opens a file, the lexical analyzer will loop through
each character, once a match is found the resulting string will be HTML
encoded, once again looping through each matched character and replacing
every HTML specific symbol (&lt;, &gt;, >, etc.) with their respective
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
| ---------------------------------- | ---------------------------------- |

**<p align="center">“example.js” Execution Time 2 milliseconds</p>**

| ![](images/dracula_example_cpp.png) | ![](images/rainbow_example_cpp.png) |
| ----------------------------------- | ----------------------------------- |

**<p align="center">“example.cpp” Execution Time 1 milliseconds</p>**

| ![](images/dracula_example_c.png) | ![](images/rainbow_example_c.png) |
| --------------------------------- | --------------------------------- |

**<p align="center">“example.c” Execution Time 1 milliseconds</p>**

## Time Complexity

### How does FLEX work?

Flex (fast lexical analyzer generator) is a free and open-source
software alternative to lex. It is a computer program that generates
lexical analyzers (also known as “scanners” or “lexers”).

A Flex lexical analyzer usually has time complexity _O_(_n_) in the
length of the input. That is, it performs a constant number of
operations for each input symbol.

### Other Algorithms

Apart from the code generated by the lexical analyzer once a token is
matched we run another _O_(_n_) algorithm to remove any HTML special
characters.

**This means that the total time complexity of the whole program is
_O_(_n_<sup>2</sup>).**

Nevertheless, as seen in the last section the program runs fairly fast.

## Ethical Implications that this type of technology could have on society

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

## References

- Funchal, G. (2011, April 14). Most efficient way to escape XML/HTML
  in C++ string?. Stack Overflow.
  <a href="https://stackoverflow.com/a/5665377" class="uri">https://stackoverflow.com/a/5665377</a>

- Levine, John R.; Mason, Tony; Brown, Doug (1992). lex & yacc (2nd
  ed.). O’Reilly. p. 279. ISBN 1-56592-000-7. A freely available
  version of lex is flex.
