#include <stdio.h>

#include <inttypes.h>

extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp;
    for (nameend = nextchar, temp = nextchar; *nameend && *temp && (*nameend == *temp) && *nameend != '='; nameend++, temp += 2)
        if (*temp == '=') break;
}
