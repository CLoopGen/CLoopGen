#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern  int16_t **tmpY;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; i < vLumFilterSize; i++)
    tmpY[i] = tmpY[i - 1];

}
