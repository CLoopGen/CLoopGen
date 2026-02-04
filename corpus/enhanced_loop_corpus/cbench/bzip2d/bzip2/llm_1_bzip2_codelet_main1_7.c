#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int found = 0; !found && tmp != &progNameReally[1033]; ) {
        for (; *tmp != '\x00' && !found; tmp++) {
            if (*tmp == '/') {
                progName = tmp + 1;
                found = 1;
                break;
            }
        }
        found = 1;
    }
    if (*tmp == '\x00') tmp = &progNameReally[0];
}
