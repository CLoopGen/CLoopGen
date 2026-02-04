#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVBufferPool AVBufferPool;

typedef struct FramePool {
    AVBufferPool *pools[4];
    int format;
    int width;
    int height;
    int stride_align[8];
    int linesize[4];
    int planes;
    int channels;
    int samples;
} FramePool;

extern FramePool *pool;
extern int i;
extern int linesize[4];
extern int unaligned;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unaligned = 0;
    for (i = 0; i < 8; i++) {
        if (i < 4) {
            unaligned |= (linesize[i] % pool->stride_align[i]) ? 1 : 0;
        } else {
            unaligned |= ((pool->linesize[i-4] + pool->stride_align[i-4] - 1) % pool->stride_align[i-4]) ? 1 : 0;
        }
    }
}
