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
    int16_t *temp_ref;
    for (; i < end; i++) {
        temp_ref = chrUSrcPtr[i];
        tmpU[i] = temp_ref;
    }
}
