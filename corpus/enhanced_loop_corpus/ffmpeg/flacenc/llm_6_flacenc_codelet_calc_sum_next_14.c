#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t sums[32][256];
extern int kmax;
extern int i;
extern int k;
extern int parts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < parts; i++) {
    for (k = 0; k <= kmax; k++) {
        uint64_t temp = sums[k][2 * i] + sums[k][2 * i + 1];
        sums[k][i] = temp;
    }
}
}
