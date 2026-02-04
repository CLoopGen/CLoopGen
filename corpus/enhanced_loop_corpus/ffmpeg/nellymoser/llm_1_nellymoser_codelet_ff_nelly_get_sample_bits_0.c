#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *buf;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 124; i += 4) {
    max = ((max) > (buf[i]) ? (max) : (buf[i]));
    if (i + 1 < 124) max = ((max) > (buf[i+1]) ? (max) : (buf[i+1]));
    if (i + 2 < 124) max = ((max) > (buf[i+2]) ? (max) : (buf[i+2]));
    if (i + 3 < 124) max = ((max) > (buf[i+3]) ? (max) : (buf[i+3]));
}
}
