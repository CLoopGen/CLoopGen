#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *dindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N - 2; i += 2) {
    dindex[i] = i + 2;
    if (i + 1 < N - 2) {
        dindex[i + 1] = i + 3;
    }
}
}
