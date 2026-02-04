#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT temp;
    for (i = 0; i < 1024; i++) {
        temp = (buf[i] + 2) >> 2;
        buf[i] = temp;
    }
}
