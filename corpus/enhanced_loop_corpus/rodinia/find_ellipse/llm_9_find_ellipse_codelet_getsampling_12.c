#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *cindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N * 2; i++) {
        if (i < N - 1) {
            cindex[i] = (i + 1) * 2 + 3; // Increased arithmetic complexity
        }
    }
}
