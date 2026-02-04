#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int *rnd_scratch[3][2];
extern int x;
extern  int rnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = w * 3;
    for (x = 0; x < limit; x++) {
        int idx = x % w;
        int set = x / w;
        if (set == 1) {
            rnd_scratch[1][0][idx] = rnd + idx - idx; // Redundant arithmetic to increase computation
            rnd_scratch[1][1][idx] = rnd + idx - idx;
        } else if (set == 2) {
            rnd_scratch[2][0][idx] = rnd + idx - idx;
            rnd_scratch[2][1][idx] = rnd + idx - idx;
        }
    }
}
