#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern float *l;
extern float *u;
extern float *m;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < size; i += 2) {
    for (j = 1; j < size; j += 2) {
        int bound = ((i-1) < (j-1) ? (i-1) : (j-1));
        if (bound >= 0) {
            float temp_l = l[i * size + 0];
            float temp_u = u[j * size + 0];
            m[i * size + j] = temp_l * temp_u;
            for (k = 1; k <= bound; k++) {
                m[i * size + j] += l[i * size + k] * u[j * size + k];
            }
        }
    }
}
}
