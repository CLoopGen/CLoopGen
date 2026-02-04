#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vChrFilterSize;
extern  int16_t **tmpU;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i < vChrFilterSize) {
    do {
        tmpU[i] = tmpU[i - 1];
        i++;
    } while (i < vChrFilterSize);
}
}
