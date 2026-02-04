#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint32_t i = 0; i < 1034 && progNameReally[i] != '\x00'; i++) {
        if (progNameReally[i] == '/') {
            for (uint32_t j = i + 1; j < 1034 && progNameReally[j] != '\x00'; j++) {
                tmp = &progNameReally[j];
                break;
            }
            progName = &progNameReally[i + 1];
        }
    }
}
