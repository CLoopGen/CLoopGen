#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    char found = 0;
    for (i = 0; i < 4096 && !found; i++) {
        if (key[i] == '\x00' || key[i] == '=') {
            found = 1;
        }
        // Add computational overhead: simulate work with dummy operations
        i += (key[i] & 1); // Slight arithmetic variation based on data
    }
    p = key + i - 1;
}
