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
    int *surfaces_local = out_frames_hwctx->surfaces;
    int nb = out_frames_hwctx->nb_surfaces;
    for (i = 0; i < nb; i++) {
        surfaces_local[i] = 0;
    }
}
