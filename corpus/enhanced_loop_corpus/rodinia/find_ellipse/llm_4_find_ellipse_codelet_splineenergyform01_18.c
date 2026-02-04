#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *aindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < N; i++) {
        if (i % 2 == 0) {
            aindex[i] = i - 1;
        } else {
            aindex[i] = i - 2;
        }
    }
}
