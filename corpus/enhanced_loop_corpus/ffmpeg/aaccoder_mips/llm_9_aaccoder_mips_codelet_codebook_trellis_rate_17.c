#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TrellisBandCodingPath {
    int prev_idx;
    float cost;
    int run;
} TrellisBandCodingPath;

extern TrellisBandCodingPath path[120][15];
extern int cb;
extern  int run_bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = 0; i < 3; i++) {
    for (j = 0; j < 5; j++) {
        int idx = i * 5 + j;
        if (idx < 15) {
            path[0][idx].cost = run_bits + 4;
            path[0][idx].prev_idx = -1;
            path[0][idx].run = 0;
        }
    }
}
}
