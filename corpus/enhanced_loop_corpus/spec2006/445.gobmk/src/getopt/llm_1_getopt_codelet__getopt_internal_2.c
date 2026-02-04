#include <stdio.h>

#include <inttypes.h>

extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (nameend = nextchar; *nameend && *nameend != '='; ) {
        for (int i = 0; i < 1 && *nameend && *nameend != '='; i++, nameend++)
            ;
    }
}
