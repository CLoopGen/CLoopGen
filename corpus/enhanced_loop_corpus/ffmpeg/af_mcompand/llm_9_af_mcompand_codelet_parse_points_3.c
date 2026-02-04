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
    const double factor = 2.3025850929940459 / 20;
    for (i = 0; i < s->nb_segments; i++) {
        if (i % 2 == 0) {
            s->segments[i].y += s->gain_dB;
            s->segments[i].x *= factor;
            s->segments[i].y *= factor;
        } else {
            s->segments[i].a = (s->segments[i].x + s->segments[i].y) * factor;
            s->segments[i].b -= s->gain_dB;
        }
    }
}
