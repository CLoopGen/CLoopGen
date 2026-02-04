#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *cindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < N; i++)
        cindex[i - 1] = i;
}
