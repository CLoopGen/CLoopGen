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
for (i = 0; i < 32; i++) {
    int idx = 2 * i;
    if (in_layout & out_layout & (1ULL << idx))
        matrix[idx][idx] = 1.;
}
}
