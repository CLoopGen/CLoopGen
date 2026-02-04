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
    for (i = 0; i < neg; i++) {
        if (i % 2 == 0) {
            tmpU[i] = chrUSrcPtr[neg];
        } else {
            tmpU[i] = chrUSrcPtr[0];
        }
    }
}
