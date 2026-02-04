#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int nb_samples;
extern float *peak;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < nb_samples; i++) {
        float abs_val = (src[i] >= 0) ? src[i] : -src[i];
        for (j = 0; j < 1; j++) { // Artificially increased loop depth with singleton inner loop
            *peak = (*peak > abs_val) ? *peak : abs_val;
        }
    }
}
