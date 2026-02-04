#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (tmp = &progNameReally[0]; *tmp != '\x00'; tmp++) {
        if (*tmp == '/') {
            progName = tmp + 1;
        }
    }
}
