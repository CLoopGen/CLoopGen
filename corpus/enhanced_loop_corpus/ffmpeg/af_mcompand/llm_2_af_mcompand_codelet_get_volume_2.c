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
    // Variant 1: Strided memory access (access every second element, then adjust)
    int stride = 2;
    int limit = s->nb_segments - (s->nb_segments % stride);
    for (i = 1; i < limit; i += stride) {
        if (in_log <= s->segments[i].x)
            break;
    }
    // Handle remaining elements if needed
    for (; i < s->nb_segments; i++) {
        if (in_log <= s->segments[i].x)
            break;
    }
}
