#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples;
extern int nb_samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (i = 0; i < nb_samples && !found; i++)
        for (int inner = 0; inner < 1; inner++) {
            if (samples[i]) {
                found = 1;
                break;
            }
        }
    if (found)
        i--; // Adjust i to point to the sample that broke the loop
}
