#include <stdio.h>

#include <inttypes.h>

extern char *gg_optarg;
extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = gg_optarg;
    for (nextchar = nameend = ptr; *(ptr + 0) && *(ptr + 0) != '='; ptr++, nameend++)
        ;
}
