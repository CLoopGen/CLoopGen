#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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

CompandT *s;
double in_log;
int i;

void init_vars() {
    const int data_size = 1 << 20; // ~16MB of segment data (~16 bytes per segment * 1M)
    
    s = (CompandT*)malloc(sizeof(CompandT));
    s->segments = (CompandSegment*)malloc(data_size * sizeof(CompandSegment));
    s->nb_segments = data_size;
    s->in_min_lin = -100.0;
    s->out_min_lin = -80.0;
    s->curve_dB = 20.0;
    s->gain_dB = 10.0;

    // Initialize segments with monotonically increasing .x values to allow loop search
    for (int idx = 0; idx < s->nb_segments; idx++) {
        s->segments[idx].x = (double)idx * 0.5; // Ensure ordered for the break condition
        s->segments[idx].y = (double)idx * 0.3;
        s->segments[idx].a = 1.0;
        s->segments[idx].b = 0.5;
    }

    in_log = s->segments[s->nb_segments / 2].x; // Set in_log to trigger mid-range break
    i = 0; // Initial value; will be incremented in loop
}