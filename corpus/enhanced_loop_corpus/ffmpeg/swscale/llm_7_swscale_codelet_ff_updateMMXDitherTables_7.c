#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **chrUSrcPtr;
extern  int16_t **tmpU;
extern int i;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = (i > 0) ? i - 1 : i;
    for (; i < end; i++) {
        if (i > 0) {
            tmpU[i] = tmpU[prev]; // Introduce WAW and loop-carried dependency
        } else {
            tmpU[i] = chrUSrcPtr[i];
        }
        prev = i;
    }
}
