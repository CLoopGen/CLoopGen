#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a WAW (Write-After-Write) loop-carried dependency by writing to the same location multiple times
    // Also introduces an artificial RAW dependency by using a temporary variable that depends on prior computation
    unsigned short temp;
    for (i = 2; i < (6 + 3) - 1; i++) {
        temp = *(--x);
        *(--p) = temp;
        *(p) += *(p); // Additional write creates WAW on *p
    }
}
