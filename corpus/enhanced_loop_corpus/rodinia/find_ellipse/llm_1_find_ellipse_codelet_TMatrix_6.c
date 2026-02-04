#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *cindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 1) {
        i = 0;
        for (; i < N - 1; i++) {
            cindex[i] = i + 1;
        }
    }
}
