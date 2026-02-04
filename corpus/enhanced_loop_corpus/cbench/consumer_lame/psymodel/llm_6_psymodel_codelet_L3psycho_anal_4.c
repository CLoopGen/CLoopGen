#include <stdio.h>

#include <inttypes.h>

extern int numlines_s[63];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; numlines_s[i] >= 0; i++) {
        temp += numlines_s[i];
    }
    numlines_s[0] = temp; // Introduce WAW and RAW dependencies: write after prior reads, and write after write on numlines_s[0]
}
