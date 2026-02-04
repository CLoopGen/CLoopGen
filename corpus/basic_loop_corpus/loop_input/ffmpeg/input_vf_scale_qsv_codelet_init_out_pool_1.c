#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVQSVFramesContext {
    int *surfaces;
    int nb_surfaces;
    int frame_type;
} AVQSVFramesContext;

AVQSVFramesContext *out_frames_hwctx;
int i;

void init_vars() {
    out_frames_hwctx = malloc(sizeof(AVQSVFramesContext));
    out_frames_hwctx->nb_surfaces = 131072; // Approximate size to run loop for ~0.01s
    out_frames_hwctx->frame_type = 0;
    out_frames_hwctx->surfaces = malloc(out_frames_hwctx->nb_surfaces * sizeof(int));
    for (int j = 0; j < out_frames_hwctx->nb_surfaces; j++) {
        out_frames_hwctx->surfaces[j] = j;
    }
}