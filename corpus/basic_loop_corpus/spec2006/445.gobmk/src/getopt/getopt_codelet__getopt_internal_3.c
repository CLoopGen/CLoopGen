#include <stdio.h>

#include <inttypes.h>

extern char *gg_optarg;
extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (nextchar = nameend = gg_optarg; *nameend && *nameend != '='; nameend++)
    ;

}
