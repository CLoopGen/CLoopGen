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
    int limit = w * 4;
    for (x = 0; x < limit; x++) {
        int idx = x >> 2; // divide by 4 to get array index
        int offset = x & 3; // mod 4 to determine which assignment
        switch (offset) {
            case 0:
                rnd_scratch[1][0][idx] = rnd;
                break;
            case 1:
                rnd_scratch[1][1][idx] = rnd;
                break;
            case 2:
                rnd_scratch[2][0][idx] = rnd;
                break;
            case 3:
                rnd_scratch[2][1][idx] = rnd;
                break;
        }
    }
}
