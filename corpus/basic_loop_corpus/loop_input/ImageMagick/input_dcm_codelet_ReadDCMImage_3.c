#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _DCMStreamInfo {
    size_t remaining;
    size_t segment_count;
    ssize_t segments[15];
    size_t offset_count;
    ssize_t *offsets;
    ssize_t count;
    int byte;
} DCMStreamInfo;

typedef long long MagickOffsetType;

DCMStreamInfo *stream_info;
MagickOffsetType offset;
ssize_t i;

static ssize_t *g_offsets = NULL;

void init_vars() {
    const size_t data_size = 1 << 24; // ~16.7 million elements, aiming for ~0.01 sec on modern CPU
    stream_info = (DCMStreamInfo*)calloc(1, sizeof(DCMStreamInfo));
    g_offsets = (ssize_t*)malloc(data_size * sizeof(ssize_t));
    
    if (!stream_info || !g_offsets) {
        free(stream_info);
        free(g_offsets);
        exit(EXIT_FAILURE);
    }

    stream_info->offset_count = data_size;
    stream_info->offsets = g_offsets;
    stream_info->count = 0;
    stream_info->byte = 0;
    stream_info->remaining = 0;
    stream_info->segment_count = 0;

    for (size_t j = 0; j < 15; ++j) {
        stream_info->segments[j] = (ssize_t)(j * 100);
    }

    offset = 42;
    i = 0;
}