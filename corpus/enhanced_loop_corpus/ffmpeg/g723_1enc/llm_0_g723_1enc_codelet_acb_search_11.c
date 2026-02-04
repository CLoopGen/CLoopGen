#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ccr_buf[80];
extern int iter;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < iter; j++)
        for (i = 0; i < 20; i++)
            max = ((max) > (((ccr_buf[i + j*20]) >= 0 ? (ccr_buf[i + j*20]) : (-(ccr_buf[i + j*20])))) ? (max) : (((ccr_buf[i + j*20]) >= 0 ? (ccr_buf[i + j*20]) : (-(ccr_buf[i + j*20])))));
}
