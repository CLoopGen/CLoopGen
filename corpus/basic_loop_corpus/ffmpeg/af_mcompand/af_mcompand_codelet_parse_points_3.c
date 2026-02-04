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
for (i = 0; i < s->nb_segments; i += 2) {
    s->segments[i].y += s->gain_dB;
    s->segments[i].x *= 2.3025850929940459 / 20;
    s->segments[i].y *= 2.3025850929940459 / 20;
}

}
