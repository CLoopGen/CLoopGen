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
max_score = -__FLT_MAX__;
for (i = 0; i < 42; i += 2) {
    int idx = i / 2;
    float current = band_score[idx];
    float next = (idx + 1 < 21) ? band_score[idx + 1] : -__FLT_MAX__;
    if (current > max_score) max_score = current;
    if (next > max_score) max_score = next;
}
}
