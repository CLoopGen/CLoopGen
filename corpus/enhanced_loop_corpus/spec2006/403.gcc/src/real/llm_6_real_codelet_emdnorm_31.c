#include <stdio.h>

#include <inttypes.h>

extern unsigned short s[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 2; i < (6 + 3) - 1; i++) {
        temp = s[i] + temp;  // Introduce RAW dependency: temp depends on previous iteration
        s[i] = temp;         // WAW: s[i] is written after prior write to same element in next iteration if any, but here each i is unique
    }
}
