#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t in_layout;
extern uint64_t out_layout;
extern int i;
extern double matrix[64][64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 2) {
    if (in_layout & out_layout & (1ULL << i))
        matrix[i][i] = 1.;
    if (i + 1 < 64 && (in_layout & out_layout & (1ULL << (i + 1))))
        matrix[i + 1][i + 1] = 1.;
}
}
