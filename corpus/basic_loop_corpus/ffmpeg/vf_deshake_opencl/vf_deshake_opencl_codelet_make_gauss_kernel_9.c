#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *gauss_kernel;
extern float length;
extern float gauss_sum;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < length; ++i) {
    gauss_kernel[i] /= gauss_sum;
}

}
