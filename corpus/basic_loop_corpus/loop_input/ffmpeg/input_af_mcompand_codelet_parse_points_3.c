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

CompandT *s;
int i;

void init_vars() {
    s = (CompandT*)malloc(sizeof(CompandT));
    if (!s) exit(1);

    const size_t data_size = 64 * 1024 * 1024; // ~64MB of segment data
    const size_t num_segments = data_size / sizeof(CompandSegment);
    s->nb_segments = (int)num_segments;
    s->segments = (CompandSegment*)calloc(num_segments, sizeof(CompandSegment));
    if (!s->segments) exit(1);

    for (size_t j = 0; j < num_segments; ++j) {
        s->segments[j].x = 1.0;
        s->segments[j].y = 2.0;
        s->segments[j].a = 3.0;
        s->segments[j].b = 4.0;
    }

    s->in_min_lin = 0.0;
    s->out_min_lin = 0.0;
    s->curve_dB = 1.0;
    s->gain_dB = 5.0;
}