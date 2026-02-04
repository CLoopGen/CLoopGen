#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *aindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = i;
    for (i = 1; i < N; i++) {
        aindex[temp] = i - 1;
        temp = i;
    }
}
