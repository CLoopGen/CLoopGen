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
for (int i = 0; i < w; i++) {
    for (x = 0; x < 1; x++) {
        rnd_scratch[0][0][i] = rnd_scratch[0][1][i] = rnd;
    }
}
}
