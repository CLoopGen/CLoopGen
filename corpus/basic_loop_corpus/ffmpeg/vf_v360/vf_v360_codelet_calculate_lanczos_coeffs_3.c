#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < 4; i++) {
    coeffs[i] /= sum;
}

}
