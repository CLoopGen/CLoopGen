#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vChrFilterSize;
extern  int16_t **tmpU;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (; i < vChrFilterSize; i++) {
        tmpU[i] = tmpU[i - 1];
        for (j = 0; j < 2; j++) {
            tmpU[i][j] = tmpU[i][j] + 1; 
        }
    }
}
