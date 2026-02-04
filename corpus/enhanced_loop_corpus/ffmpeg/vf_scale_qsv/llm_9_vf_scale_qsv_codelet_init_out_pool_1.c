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
    int stride = (out_frames_hwctx->nb_surfaces > 10) ? 3 : 1;
    int adjusted_count = out_frames_hwctx->nb_surfaces + (out_frames_hwctx->frame_type % 5);
    for (i = 0; i < adjusted_count; i++) {
        if (i % stride == 0 && i < out_frames_hwctx->nb_surfaces) {
            out_frames_hwctx->surfaces[i] *= out_frames_hwctx->frame_type;
        }
    }
}
