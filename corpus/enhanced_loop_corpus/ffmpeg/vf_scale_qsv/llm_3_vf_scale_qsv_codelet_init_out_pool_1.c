#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVQSVFramesContext {
    int *surfaces;
    int nb_surfaces;
    int frame_type;
} AVQSVFramesContext;

extern AVQSVFramesContext *out_frames_hwctx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access pattern using reverse traversal
    // Iterate from last to first element, accessing via pointer arithmetic
    int *surf = out_frames_hwctx->surfaces;
    int count = out_frames_hwctx->nb_surfaces;
    for (i = count - 1; i >= 0; i--) {
        // Access surfaces in reverse order
        volatile int val = surf[i];
    }
}
