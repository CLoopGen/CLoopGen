#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float beta = alpha;
    for (i = 0; i < 10; i += 2) {
        if (i + 1 < 10) {
            beta *= beta;
            alpha = beta;  // Write after write: WAW dependency introduced
            beta *= beta;
        } else {
            beta *= beta;
        }
    }
    alpha = beta;
}
