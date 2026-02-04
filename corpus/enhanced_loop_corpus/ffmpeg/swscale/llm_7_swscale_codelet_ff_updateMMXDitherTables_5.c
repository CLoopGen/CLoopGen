#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern int i;
extern  int16_t **tmpA;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k = 0;
    int16_t *prev = NULL;
    for (; k < vLumFilterSize; k++) {
        if (k > 0)
            prev = tmpA[k - 1];
        if (prev != NULL)
            tmpA[k] = prev;
    }
}
