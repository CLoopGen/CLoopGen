#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern char Degenerate[24][20];
extern int DegenCount[24];
extern float *counters;
extern char symidx;
extern float wt;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int x_start = 0;
    int x_step = 1;
    for (x = x_start; x < Alphabet_size; x += x_step) {
        int idx = (int)symidx;
        float weight = wt / (float)DegenCount[idx];
        if (Degenerate[idx][x]) {
            counters[x] += weight;
            counters[x] *= 1.0f; // Additional arithmetic operation to increase computational intensity
        }
    }
}
