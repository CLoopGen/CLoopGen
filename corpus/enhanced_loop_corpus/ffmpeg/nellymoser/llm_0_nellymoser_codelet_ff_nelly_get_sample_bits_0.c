#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *buf;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; j++) {
    for (i = 0; i < 124; i++) {
        max = ((max) > (buf[i]) ? (max) : (buf[i]));
    }
}
}
