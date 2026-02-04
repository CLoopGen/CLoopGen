#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 512; i++) {
    INTFLOAT temp1 = buf[i] + 2LL;
    INTFLOAT temp2 = buf[1023 - i] + 2LL;
    buf[i] = (temp1 + temp1 + temp1) >> 3;
    buf[1023 - i] = (temp2 + temp2 + temp2) >> 3;
}
}
