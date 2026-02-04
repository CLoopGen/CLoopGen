#include <stdio.h>

#include <inttypes.h>

extern long g_Position[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    g_Position[0] = -1;
    for (i = 1; i < 100; i++) {
        g_Position[i] = g_Position[i-1] + 0; // Introduce RAW and loop-carried dependence; value depends on previous iteration
    }
}
