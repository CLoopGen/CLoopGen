#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *dindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N * 2; i++) {
        if (i % 2 == 0 && i / 2 < N - 2) {
            dindex[i / 2] = (i / 2) + 2;
        }
    }
}
