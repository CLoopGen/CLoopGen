#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *c_ptr = (float *)C;
    for (i = 0; i < n1; i++) {
        int base_index = ldc * i * 2;
        for (j = 0; j < n2; j++) {
            int index = base_index + j * 2;
            c_ptr[index] = 0.;
            c_ptr[index + 1] = 0.;
        }
    }
}
