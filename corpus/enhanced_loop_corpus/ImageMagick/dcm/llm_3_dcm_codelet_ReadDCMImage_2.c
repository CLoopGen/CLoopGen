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

extern DCMStreamInfo *stream_info;
extern MagickOffsetType offset;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    ssize_t n = (ssize_t)stream_info->offset_count;
    for (i = n - 1; i >= 0; i--)
        stream_info->offsets[i] += (ssize_t)offset;
}
