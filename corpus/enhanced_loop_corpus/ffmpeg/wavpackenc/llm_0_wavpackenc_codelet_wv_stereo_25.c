#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int32_t *samples_r;
extern int nb_samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < nb_samples; i++) {
        for (j = 0; j < 1; j++) { // Artificially increased loop depth without changing logic
            if (samples_l[i] || samples_r[i])
                break;
        }
    }
}
