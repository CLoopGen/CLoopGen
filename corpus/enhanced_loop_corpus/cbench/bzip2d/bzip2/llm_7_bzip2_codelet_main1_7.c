#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int i;
    int last_slash_index = 0;
    for (i = 0; i < 1034 && progNameReally[i] != '\x00'; i++) {
        if (progNameReally[i] == '/') {
            last_slash_index = i + 1;
        }
    }
    progName = &progNameReally[last_slash_index];
}
