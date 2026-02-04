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
    // Variant 2: Indirect memory access pattern using an index remapping
    // Simulate indirect access via reverse order indexing (reverse traversal without changing loop bound logic)
    for (i = 0; i < hwctx->nb_surfaces; i++) {
        int idx = hwctx->nb_surfaces - 1 - i; // Reverse mapping
        volatile int tmp = hwctx->surfaces[idx];
    }
}
