#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float band_score[21];
extern float max_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer_i;
for (outer_i = 0; outer_i < 21; outer_i += 7) {
    int limit = (outer_i + 7 < 21) ? outer_i + 7 : 21;
    for (i = outer_i; i < limit; i++) {
        if (band_score[i] > max_score)
            max_score = band_score[i];
    }
}
}
