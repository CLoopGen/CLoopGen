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
    int *locals = (int*)alloca(hwctx->nb_surfaces * sizeof(int));
    for (i = 0; i < hwctx->nb_surfaces; i++) {
        locals[i] = hwctx->surfaces[i] * 2;
        hwctx->surfaces[i] = locals[i] + i;
    }
}
