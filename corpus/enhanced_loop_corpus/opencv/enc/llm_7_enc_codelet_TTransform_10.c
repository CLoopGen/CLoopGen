#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_b3 = 0;
    for (i = 0; i < 4; i++) {
        const int a0 = tmp[0 + i] + tmp[8 + i] + prev_b3; // Introduce RAW: depends on previous iteration's b3
        const int a1 = tmp[4 + i] + tmp[12 + i];
        const int a2 = tmp[4 + i] - tmp[12 + i];
        const int a3 = tmp[0 + i] - tmp[8 + i];
        const int b0 = a0 + a1;
        const int b1 = a3 + a2;
        const int b2 = a3 - a2;
        const int b3 = a0 - a1;
        prev_b3 = b3; // Create loop-carried dependency (RAW) for next iteration
        tmp[15 - i] = b0 + b1 + b2 + b3; // WAR/WAW: write used in potential subsequent reads/writes
    }
}
