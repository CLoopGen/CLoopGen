#include <stdio.h>

#include <inttypes.h>

extern long g_Position[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = 99; i >= 0; i--) {
        g_Position[i] = -1;
    }
}
