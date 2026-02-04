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
    int limit = out_frames_hwctx->nb_surfaces * 2;
    for (i = 0; i < limit; i += 2) {
        out_frames_hwctx->surfaces[i / 2] += i * out_frames_hwctx->frame_type;
    }
}
