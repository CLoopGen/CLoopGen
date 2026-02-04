#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct CompandSegment {
    double x;
    double y;
    double a;
    double b;
} CompandSegment;

typedef struct CompandT {
    CompandSegment *segments;
    int nb_segments;
    double in_min_lin;
    double out_min_lin;
    double curve_dB;
    double gain_dB;
} CompandT;

extern CompandT *s;
extern double in_log;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_index = 0;
    for (i = 1; i < s->nb_segments; i++) {
        if (in_log <= s->segments[i].x && temp_index == 0) {
            temp_index = i;
        }
    }
    i = temp_index;
}
