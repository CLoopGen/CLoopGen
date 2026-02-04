#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vChrFilterSize;
extern  int16_t **tmpU;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    int16_t* prev = NULL;
    for (k = 0; k < vChrFilterSize; k++) {
        if (k > 0) {
            tmpU[k] = prev;
        }
        prev = tmpU[k];
    }
}
