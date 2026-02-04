#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *aindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = i - 1;
    for (i = 1; i < N; i++) {
        aindex[i] = temp;
        temp = i;
    }
}
