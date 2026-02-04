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
    for (x = 0; x < Alphabet_size; x++) {
        if (!Degenerate[(int)symidx][x]) 
            continue;
        counters[x] += wt / (float)DegenCount[(int)symidx];
    }
}
