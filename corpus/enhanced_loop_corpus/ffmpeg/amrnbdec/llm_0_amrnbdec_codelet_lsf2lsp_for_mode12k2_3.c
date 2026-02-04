#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float lsf_no_r[10];
extern int16_t lsf_r[10];
extern float lsf_q[10];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 1; j++)
        for (i = 0; i < 10; i++)
            lsf_q[i] = lsf_r[i] * ((8000. / 32768.) / 8000.) + lsf_no_r[i] * (1. / 8000.);
}
