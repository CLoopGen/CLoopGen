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
    // Variant 1: Strided memory access with step of 2, but rewritten using pointer arithmetic for consecutive logical access
    CompandSegment *segs = s->segments;
    int n = s->nb_segments;
    double gain_dB = s->gain_dB;
    double scale = 2.3025850929940459 / 20;
    for (int i = 0; i < n; i += 2) {
        CompandSegment *seg = &segs[i];
        seg->y += gain_dB;
        seg->x *= scale;
        seg->y *= scale;
    }
}
