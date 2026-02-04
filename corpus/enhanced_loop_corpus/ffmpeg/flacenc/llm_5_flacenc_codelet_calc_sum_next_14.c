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
for (i = 0; i < parts && parts <= 128; i++) {
    for (k = 0; k <= kmax; k++) {
        if (i < 128) {
            sums[k][i] = sums[k][2 * i] + sums[k][2 * i + 1];
        }
    }
}
}
