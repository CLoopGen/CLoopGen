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
    for (; i < end; i++) {
        tmpU[i] = chrUSrcPtr[i];
        if (tmpU[i] == NULL) {
            i++;
            continue;
        }
    }
}
