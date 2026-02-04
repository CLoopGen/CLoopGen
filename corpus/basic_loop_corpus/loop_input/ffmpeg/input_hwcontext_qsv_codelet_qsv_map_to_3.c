#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVQSVFramesContext {
    int *surfaces;
    int nb_surfaces;
    int frame_type;
} AVQSVFramesContext;

AVQSVFramesContext *hwctx;
int i;

void init_vars() {
    hwctx = (AVQSVFramesContext *)malloc(sizeof(AVQSVFramesContext));
    hwctx->nb_surfaces = 10000000; // Adjust to achieve ~0.01s runtime
    hwctx->frame_type = 0;
    hwctx->surfaces = (int *)malloc(hwctx->nb_surfaces * sizeof(int));
    for (int j = 0; j < hwctx->nb_surfaces; j++) {
        hwctx->surfaces[j] = j;
    }
    i = 0;
}