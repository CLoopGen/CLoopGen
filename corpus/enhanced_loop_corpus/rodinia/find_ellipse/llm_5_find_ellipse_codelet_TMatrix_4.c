#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *aindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < N; i++) {
        if (i % 2 == 0) {
            continue;
        }
        aindex[i] = i - 1;
    }
}
