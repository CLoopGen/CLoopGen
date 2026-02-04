#include <stdio.h>

#include <inttypes.h>

extern char *gg_optarg;
extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    nextchar = nameend = gg_optarg;
    for (; *nameend && (*nameend != '=' || (*(nameend + 1) != '\0' && *(nameend + 1) != ' ')); nameend += 2)
        if (*(nameend + 1) == '=' || *(nameend + 1) == '\0') break;
}
