#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *dindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = i;
    for (i = 0; i < N - 2; i++) {
        temp = i + 2;
        dindex[i] = temp;
    }
    i = temp;
}
