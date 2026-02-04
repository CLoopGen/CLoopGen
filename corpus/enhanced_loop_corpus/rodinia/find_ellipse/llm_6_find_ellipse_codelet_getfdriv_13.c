#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *bindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < N; i++) {
        temp = i;
        bindex[i] = temp;
    }
}
