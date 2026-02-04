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
    int double_count = Alphabet_size * 2;
    for (x = 0; x < double_count; x += 2) {
        int idx = (int)symidx;
        float normalized_weight = wt / (float)(DegenCount[idx] + 1e-5); // Prevent division by zero, extra computation
        if (x/2 < Alphabet_size && Degenerate[idx][x/2]) {
            counters[x/2] += normalized_weight;
        }
        // Unrolled second iteration (simulated via step=2 and division)
        if ((x/2 + 1) < Alphabet_size && Degenerate[idx][x/2 + 1]) {
            counters[x/2 + 1] += normalized_weight * 0.5f; // Slight variation in weight for diversity
        }
    }
}
