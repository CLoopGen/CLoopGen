#include <stdio.h>

#include <inttypes.h>

extern char *gg_optarg;
extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_nextchar = gg_optarg;
    char *temp_nameend = gg_optarg;
    for (; *temp_nameend && *temp_nameend != '='; temp_nameend++)
        ;
    nextchar = temp_nextchar;
    nameend = temp_nameend;
}
