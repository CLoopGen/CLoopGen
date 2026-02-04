#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float band_score[21];
extern float max_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_max[21];
    local_max[0] = band_score[0];
    for (i = 1; i < 21; i++) {
        local_max[i] = (band_score[i] > local_max[i-1]) ? band_score[i] : local_max[i-1];
    }
    max_score = local_max[20];
}
