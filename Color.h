#ifndef __COLOR_H__
#define __COLOR_H__
#include "Tokens.h"
#include <map>
#include <string>

enum ColorScheme
{
    Dracula,
    Rainbow

};

// Dracula Color Scheme Colors
const std::string background = "#282a36";
const std::string currentLine = "#44475a";
const std::string foreground = "#f8f8f2";
const std::string comment = "#6272a4";
const std::string cyan = "#8be9fd";
const std::string green = "#50fa7b";
const std::string orange = "#ffb86c";
const std::string pink = "#ff79c6";
const std::string purple = "#bd93f9";
const std::string red = "#ff5555";
const std::string yellow = "#f1fa8c";

typedef std::map<ColorScheme, std::map<Tokens, std::string> > ColorMap;

ColorMap colors{
    {{Dracula, {
                   {RESERVED, pink},
                   {IDENTIFIER, foreground},
                   {STRING, yellow},
                   {NUMBER, purple},
                   {OPERATOR, pink},
                   {COMMENT, comment},
                   {MULTICOMMENT, comment},
                   {CLASS, cyan},
                   {PREPROCESOR, pink},
                   {BOOLEAN, purple},
                   {GROUPING, orange},
                   {FUNCTIONS, green},
                   {PACKAGES, yellow},
                   {TYPES, pink},
                   {DEFAULT, foreground},

               }},
     {Rainbow, {

                   {RESERVED, "#feb300"},
                   {IDENTIFIER, "#ba00ff"},
                   {STRING, "#00aeae"},
                   {NUMBER, "#007900"},
                   {OPERATOR, "#00ff00"},
                   {COMMENT, "#ffff00"},
                   {MULTICOMMENT, "#81800c"},
                   {CLASS, "#e4f4df"},
                   {PREPROCESOR, "#00e9b0"},
                   {BOOLEAN, "#18b646"},
                   {GROUPING, "#e8002e"},
                   {FUNCTIONS, "#65ecb1"},
                   {PACKAGES, "#903a47"},
                   {TYPES, "#306cc9"},
                   {DEFAULT, "#be90ad"},

               }}

    }

};

#endif // __COLOR_H__