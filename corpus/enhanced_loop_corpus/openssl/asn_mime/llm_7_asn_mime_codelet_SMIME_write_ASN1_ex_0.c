#include <stdio.h>

#include <inttypes.h>

extern char bound[33];
extern char c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev = 0;
    for (i = 0; i < 32; i++) {
        c = (bound[i] & 15) ^ prev; // Introduce RAW dependency: current c depends on previous iteration's prev
        if (c < 10)
            c += '0';
        else
            c += 'A' - 10;
        bound[i] = c;
        prev = c; // Create loop-carried WAW and WAR dependency via `prev`
    }
}
