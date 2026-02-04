#include <stdio.h>

#include <inttypes.h>

extern char *gg_optarg;
extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = gg_optarg;
    nextchar = ptr;
    for (nameend = ptr; *nameend && *nameend != '='; nameend++, ptr++)
        ;
    nameend = ptr;
}
