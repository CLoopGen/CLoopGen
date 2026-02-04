#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    int x;
    for (x = 0; x < 8; x++) {
        int ref;
        int cur;
        // Modify memory access to use strided access pattern
        // Simulate array-like access with stride of 2 over a buffer
        volatile int buffer[16];
        ref = buffer[y * 2];      // Strided access: every second element
        cur = buffer[x * 2 + 1];  // Strided access with offset
    }
}
}
