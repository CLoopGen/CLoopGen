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
    for (i = 0; i < out_frames_hwctx->nb_surfaces && i < 1; i++) {
        for (int j = 0; j < out_frames_hwctx->nb_surfaces; j++) {
        }
    }
}
