#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *sum;
extern  float *t;
extern  float *c;
extern ptrdiff_t len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *sum_local = sum;
    float *t_local = t;
    float *c_local = c;
    ptrdiff_t len_local = len;
    for (n = 0; n < len; n++) {
        const float cre = c_local[2 * n];
        const float cim = c_local[2 * n + 1];
        const float tre = t_local[2 * n];
        const float tim = t_local[2 * n + 1];
        float temp_re = tre * cre - tim * cim;
        float temp_im = tre * cim + tim * cre;
        sum_local[2 * n] += temp_re;
        sum_local[2 * n + 1] += temp_im;
    }
}
