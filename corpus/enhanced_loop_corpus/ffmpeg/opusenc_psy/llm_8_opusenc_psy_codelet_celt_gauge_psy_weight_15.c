#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float band_score[21];
extern float max_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
float temp_max = band_score[0];
for (i = 1; i < 21; i += 2) {
    if (i + 1 < 21) {
        float val1 = band_score[i];
        float val2 = band_score[i + 1];
        if (val1 > temp_max) temp_max = val1;
        if (val2 > temp_max) temp_max = val2;
    } else {
        if (band_score[i] > temp_max) temp_max = band_score[i];
    }
}
max_score = temp_max;
}
