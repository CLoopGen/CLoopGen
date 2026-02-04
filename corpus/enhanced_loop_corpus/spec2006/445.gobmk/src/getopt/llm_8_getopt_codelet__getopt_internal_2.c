#include <stdio.h>

#include <inttypes.h>

extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (nameend = nextchar; *nameend && (*nameend != '=') && (nameend - nextchar < 1024); nameend++)
        ;
}
