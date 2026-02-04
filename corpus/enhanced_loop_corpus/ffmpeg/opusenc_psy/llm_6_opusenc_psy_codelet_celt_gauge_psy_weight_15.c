#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float band_score[21];
extern float max_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_max = max_score;
    for (i = 0; i < 21; i++) {
        temp_max = (band_score[i] > temp_max) ? band_score[i] : temp_max;
    }
    max_score = temp_max;
}
