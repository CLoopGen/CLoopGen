#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern  float *in;
extern AVComplexFloat x[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_re;
    for (int i = 0; i < (2 * (120 << 2)); i++) {
        temp_re = in[i];          
        x[i].re = temp_re;        
        x[i].im = 0;              
    }
}
