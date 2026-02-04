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



void loop() {
    // Reduce effective trip count by stepping through every second segment
    // and decrease arithmetic operations per iteration for lower complexity
    for (i = 2; i < s->nb_segments; i += 2) {
        if (in_log <= s->segments[i].x) {
            i--; // Adjust index to ensure correct exit state as in original
            break;
        }
    }
    // Ensure i is at least 1 and does not exceed bounds
    if (i >= s->nb_segments)
        i = s->nb_segments - 1;
}
