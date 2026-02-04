#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float period;
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int len;
extern int i;
extern int j;
extern int center;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int limit = ((len) >= 0 ? (len) + ((width) >> 1) : (len) - ((width) >> 1)) / (width);
    for (i = 1; i < limit; i++) {
        center = (int)(i * period + 0.5);
        int start = center - width / 2;
        int end = center + (width + 1) / 2;
        for (j = start; j < end; j++) {
            if (j >= 0 && j < len && shape != NULL) {
                speech[j] += ppc_gain * (*shape++);
            } else if (j < 0 || j >= len) {
                continue;
            }
        }
    }
}
