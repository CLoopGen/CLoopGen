#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float beta = alpha;
    for (i = 0; i < 10; i++) {
        beta *= beta;
        alpha = beta; // Introduce WAW dependency: alpha is written after beta
    }
}
