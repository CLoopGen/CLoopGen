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

extern int i;
extern FFFramePool *pool;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4 && pool->linesize[i]; i++) {
        for (int inner = 0; inner < 1; inner++) {
            pool->linesize[i] = (((pool->linesize[i]) + (pool->align) - 1) & ~((pool->align) - 1));
        }
    }
}
