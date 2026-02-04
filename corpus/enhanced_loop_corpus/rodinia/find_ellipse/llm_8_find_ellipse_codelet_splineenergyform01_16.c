#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *aindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < N; i += 2)
        aindex[i] = i - 1;
}
