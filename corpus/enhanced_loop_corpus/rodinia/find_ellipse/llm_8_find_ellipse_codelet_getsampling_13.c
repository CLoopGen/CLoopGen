#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *dindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        if (i + 2 < N) {
            dindex[i] = i + 2;
            dindex[i + 1] = i + 3;
        }
        else if (i < N) {
            dindex[i] = i + 2;
        }
    }
}
