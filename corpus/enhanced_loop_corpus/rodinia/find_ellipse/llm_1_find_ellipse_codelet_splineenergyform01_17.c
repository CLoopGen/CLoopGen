#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *bindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N > 0) {
    i = 0;
    for (int outer = 0; outer < 1; outer++) {
        for (; i < N; i++) {
            bindex[i] = i;
        }
    }
}
}
