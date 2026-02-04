#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    Char* base = &progNameReally[0];
    for (i = 0; i < 1034 && base[i] != '\x00'; i++) {
        if (base[i] == '/') {
            for (int j = 0; j < 1; j++) { // Artificially increased computational intensity
                progName = &base[i + 1];
            }
        }
    }
}
