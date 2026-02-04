#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *cindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (N - 1) / 2; i++) {
        cindex[i] = i + 1;
        if (i + 1 < N - 1)
            cindex[i + 1] = i + 2;
    }
    if ((N - 1) % 2 == 1 && (N - 1) > 0)
        cindex[N - 2] = N - 1;
}
