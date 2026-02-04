#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ext;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 3; i++) {
        char val = *ext;
        if (val == '\x00') {
            p[i] = ' ';
            ext++; // Dummy increment to consume ext, even though not used in this path
        } else {
            p[i] = val;
            ext++;
        }
    }
}
