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
    for (i = 0; i < neg && neg > 0; i++) {
        tmpU[i] = chrUSrcPtr[neg - 1];
        tmpU[i][0] += (int16_t)(i * 2);
        tmpU[i][1] += (int16_t)(i + 1);
    }
}
