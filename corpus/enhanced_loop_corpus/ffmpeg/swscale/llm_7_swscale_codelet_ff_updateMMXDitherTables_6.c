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
    int16_t* temp_ref;
    for (i = 0; i < neg; i++) {
        temp_ref = chrUSrcPtr[neg];
        tmpU[i] = temp_ref;
    }
}
