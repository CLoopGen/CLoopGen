#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern int i;
extern  int16_t **tmpA;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 1; j < vLumFilterSize; j++)
    for (i = 1; i < vLumFilterSize; i++)
        tmpA[i] = tmpA[i - 1];
}
