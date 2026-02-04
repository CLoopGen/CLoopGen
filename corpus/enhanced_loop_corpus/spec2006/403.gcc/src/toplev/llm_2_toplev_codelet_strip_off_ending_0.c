#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second character backwards)
    for (i = 2; i < 6 && len > i; i += 2) {
        if (len - i >= 0 && name[len - i] == '.') {
            name[len - i] = '\x00';
            break;
        }
    }
}
