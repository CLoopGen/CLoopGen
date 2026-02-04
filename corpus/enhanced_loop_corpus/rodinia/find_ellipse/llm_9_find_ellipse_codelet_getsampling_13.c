#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *dindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N - 4; i++) {
        dindex[i] = i * 4 + 8;
        dindex[i + 1] = (i + 1) * 4 + 8;
        i++;
    }
}
