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
        int temp = rnd + (x % 5);
        rnd_scratch[0][0][idx] = temp;
        rnd_scratch[0][1][idx] = temp ^ x;
    }
}
