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
        rnd_scratch[0][0][idx] = (rnd_scratch[0][0][idx] + rnd) ^ x;
        rnd_scratch[0][1][idx] = (rnd_scratch[0][1][idx] + rnd) ^ (x + 1);
    }
}
