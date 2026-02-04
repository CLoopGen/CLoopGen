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
    if (hwctx->nb_surfaces > 0) {
        i = 0;
        for (; i < hwctx->nb_surfaces; ) {
            i++;
        }
    }
}
