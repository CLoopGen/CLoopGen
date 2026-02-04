#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern int i;
extern  int16_t **tmpA;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j = i;
    for (; j < vLumFilterSize; j++) {
        if (j > 0) {
            tmpA[j] = tmpA[j - 1];
        } else {
            tmpA[j] = NULL;
        }
    }
    i = j;
}
