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
    int temp = 0;
    for (i = 0; i < hwctx->nb_surfaces; i++) {
        temp += hwctx->surfaces[i];
    }
    hwctx->frame_type = temp;
}
