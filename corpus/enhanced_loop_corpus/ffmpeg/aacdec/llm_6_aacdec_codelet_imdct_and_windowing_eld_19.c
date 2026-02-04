#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *buf;
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT temp1, temp2;
    for (i = 0; i < n - 1; i += 2) {
        temp1 = buf[i];
        temp2 = buf[i + 1];
        buf[i] = -temp1;
        buf[i + 1] = -temp2;
    }
    if (i == n - 1) {
        buf[i] = -buf[i];
    }
}
