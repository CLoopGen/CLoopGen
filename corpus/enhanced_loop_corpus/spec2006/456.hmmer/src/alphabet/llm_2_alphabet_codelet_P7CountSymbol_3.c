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
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    float *counter_ptr = counters;
    char *degen_row = Degenerate[(int)symidx];
    int degen_count = DegenCount[(int)symidx];
    float weight = wt / (float)degen_count;
    
    for (x = 0; x < Alphabet_size; x++) {
        if (degen_row[x])
            counter_ptr[x] += weight;
    }
}
