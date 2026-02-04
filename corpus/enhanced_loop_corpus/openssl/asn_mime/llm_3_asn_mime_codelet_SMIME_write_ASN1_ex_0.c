#include <stdio.h>

#include <inttypes.h>

extern char bound[33];
extern char c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate from end to start)
    int i;
    char c;
    for (i = 31; i >= 0; i--) {
        c = bound[i] & 15;
        if (c < 10)
            c += '0';
        else
            c += 'A' - 10;
        bound[i] = c;
    }
}
