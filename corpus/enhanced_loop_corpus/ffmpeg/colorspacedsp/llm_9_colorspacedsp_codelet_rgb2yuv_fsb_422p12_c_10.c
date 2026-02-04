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
    int limit = w > 100 ? w / 2 : w;
    for (x = 0; x < limit; x++) {
        int temp = rnd + x * 3;
        rnd_scratch[0][0][x] = temp;
        rnd_scratch[0][1][x] = temp ^ rnd;
    }
}
