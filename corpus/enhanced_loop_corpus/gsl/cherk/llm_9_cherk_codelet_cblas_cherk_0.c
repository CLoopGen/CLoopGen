#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    if (i + 1 < N) {
        for (j = i; j < N; j++) {
            int index1 = 2 * (ldc * i + j);
            int index2 = 2 * (ldc * (i + 1) + j);
            float *c_ptr = (float *)C;
            c_ptr[index1] = 0.;
            c_ptr[index1 + 1] = 0.;
            if (j >= i + 1) {
                c_ptr[index2] = 0.;
                c_ptr[index2 + 1] = 0.;
            }
        }
    } else {
        for (j = i; j < N; j++) {
            int index = 2 * (ldc * i + j);
            float *c_ptr = (float *)C;
            c_ptr[index] = 0.;
            c_ptr[index + 1] = 0.;
        }
    }
}
}
