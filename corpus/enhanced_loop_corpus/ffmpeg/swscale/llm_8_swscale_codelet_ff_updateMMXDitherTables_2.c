#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern  int16_t **tmpY;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (; i < vLumFilterSize; i++) {
        tmpY[i] = tmpY[i - 1];
        for (j = 0; j < 3; j++) {
            tmpY[i][j] = tmpY[i][j] * 2 + 1;
        }
    }
}
