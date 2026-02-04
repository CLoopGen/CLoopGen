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
    for (n = 0; n < len; n++) {
        if (n % 2 == 0) {
            const float cre = c[2 * n];
            const float cim = c[2 * n + 1];
            const float tre = t[2 * n];
            const float tim = t[2 * n + 1];
            sum[2 * n] += tre * cre - tim * cim;
            sum[2 * n + 1] += tre * cim + tim * cre;
        } else {
            const float tre = t[2 * n];
            const float tim = t[2 * n + 1];
            sum[2 * n] += tre;
            sum[2 * n + 1] -= tim;
        }
    }
}
