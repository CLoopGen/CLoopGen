#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT temp;
    for (i = 0; i < n; i += 2) {
        temp = buf[i];
        buf[i] = -temp;
    }
}
