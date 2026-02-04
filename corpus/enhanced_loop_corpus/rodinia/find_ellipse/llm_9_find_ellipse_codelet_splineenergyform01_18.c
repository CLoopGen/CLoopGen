#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *aindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < N * 2; i++) {
        if (i < N) {
            aindex[i] = (i - 1) * 2 + 1;
        } else {
            aindex[i - N] = (i - N) * (i - N);
        }
    }
}
