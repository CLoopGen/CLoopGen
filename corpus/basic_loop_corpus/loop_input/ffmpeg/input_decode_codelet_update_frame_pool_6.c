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

FramePool *pool;
int i;
int linesize[4];
int unaligned;

void init_vars() {
    pool = (FramePool *)calloc(1, sizeof(FramePool));
    if (!pool) exit(1);

    pool->format = 0;
    pool->width = 1920;
    pool->height = 1080;
    for (int j = 0; j < 8; j++) {
        pool->stride_align[j] = (j < 4) ? 32 : 16;
    }
    for (int j = 0; j < 4; j++) {
        pool->linesize[j] = 1920 + (j * 16);
        linesize[j] = pool->linesize[j] + 8;
    }
    pool->planes = 3;
    pool->channels = 2;
    pool->samples = 1024;

    i = 0;
    unaligned = 0;
}