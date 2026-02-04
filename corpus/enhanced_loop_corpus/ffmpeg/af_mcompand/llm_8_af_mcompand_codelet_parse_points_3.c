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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < s->nb_segments - 1; i += 2) {
        double x_val = s->segments[i].x;
        double y_val = s->segments[i].y;
        double a_val = s->segments[i+1].a;
        double b_val = s->segments[i+1].b;

        s->segments[i].y = y_val + s->gain_dB;
        s->segments[i].x = x_val * 0.1151292546497023;  // 2.3025850929940459 / 20
        s->segments[i].y = s->segments[i].y * 0.1151292546497023;

        s->segments[i+1].a = a_val * x_val;
        s->segments[i+1].b = b_val + y_val;
    }
}
