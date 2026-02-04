#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *bindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        bindex[i] = i;
        if (i + 1 < N)
            bindex[i + 1] = i + 1;
    }
}
