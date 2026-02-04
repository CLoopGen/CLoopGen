#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **chrUSrcPtr;
extern  int16_t **tmpU;
extern int neg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < neg; i += step) {
        if (i + 1 < neg) {
            tmpU[i] = chrUSrcPtr[neg - i];
            tmpU[i + 1] = chrUSrcPtr[neg - i - 1];
        } else {
            tmpU[i] = chrUSrcPtr[0];
        }
    }
}
