#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Char *ptr = &progNameReally[0];
    progName = ptr;
    for (; *ptr != '\x00'; ptr++) {
        if (*(ptr) == '/') {
            progName = ptr + 1;
        }
        // Introduce WAW dependency: multiple writes to progName without interference
        // This creates a loop-carried WAW dependence, though only the last write matters
        if (*(ptr) == '\\') {
            progName = ptr + 1;
        }
    }
}
