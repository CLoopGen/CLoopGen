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
        if (i % 2 == 0)
            beta *= alpha;
        else
            beta *= beta;
    }
    alpha = beta;
}
