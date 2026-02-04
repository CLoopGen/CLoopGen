#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVQSVFramesContext {
    int *surfaces;
    int nb_surfaces;
    int frame_type;
} AVQSVFramesContext;

extern AVQSVFramesContext *hwctx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Access every second surface in a strided manner, forward traversal
    for (i = 0; i < hwctx->nb_surfaces; i += 2) {
        // Artificially touch the surface to simulate usage
        volatile int tmp = hwctx->surfaces[i];
    }
}
