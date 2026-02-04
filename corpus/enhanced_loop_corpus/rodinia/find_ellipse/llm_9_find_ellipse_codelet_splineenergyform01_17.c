#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *bindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp;
for (i = 0; i < N; i++) {
    temp = i * i - i + 1;
    bindex[i] = temp + i;
}
}
