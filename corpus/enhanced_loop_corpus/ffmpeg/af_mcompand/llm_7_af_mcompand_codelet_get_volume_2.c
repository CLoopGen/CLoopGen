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
    int found = 0;
    for (i = 1; !found && i < s->nb_segments; i++) {
        found = (in_log <= s->segments[i].x);
        if (found) {
            i--; // Adjust to keep the found index in `i` after increment
        }
    }
    if (!found) {
        i = s->nb_segments;
    } else {
        i++; // Compensate for the adjustment and post-increment effect
    }
}
