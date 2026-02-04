#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum AVMediaType {
    AVMEDIA_TYPE_UNKNOWN = -1,
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA,
    AVMEDIA_TYPE_SUBTITLE,
    AVMEDIA_TYPE_ATTACHMENT,
    AVMEDIA_TYPE_NB
};

struct AVBufferPool {
    int dummy;
};

typedef struct AVBufferPool AVBufferPool;

struct FFFramePool {
    enum AVMediaType type;
    int width;
    int height;
    int planes;
    int channels;
    int nb_samples;
    int format;
    int align;
    int linesize[4];
    AVBufferPool *pools[4];
};

typedef struct FFFramePool FFFramePool;

int i;
FFFramePool *pool;

void init_vars() {
    static AVBufferPool buffer_pools[4];
    static FFFramePool frame_pool;

    pool = &frame_pool;
    pool->type = AVMEDIA_TYPE_VIDEO;
    pool->width = 1920;
    pool->height = 1080;
    pool->planes = 3;
    pool->channels = 2;
    pool->nb_samples = 1024;
    pool->format = 0;
    pool->align = 32;
    
    // Set up linesize values so that loop runs exactly 3 iterations
    pool->linesize[0] = 1920;
    pool->linesize[1] = 960;
    pool->linesize[2] = 960;
    pool->linesize[3] = 0;  // Terminate loop at i=3
    
    for (int j = 0; j < 4; j++) {
        pool->pools[j] = &buffer_pools[j];
    }
}