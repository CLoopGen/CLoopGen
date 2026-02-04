#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **alpSrcPtr;
extern int i;
extern int end;
extern  int16_t **tmpA;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; i < end; i++)
    tmpA[i] = alpSrcPtr[i];

}
