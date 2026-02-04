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
    // Allocate stream_info structure
    stream_info = (DCMStreamInfo *)calloc(1, sizeof(DCMStreamInfo));
    
    // Set a reasonable offset_count to achieve desired runtime
    // Aim for ~100 million iterations to last ~0.01 seconds on modern CPUs
    stream_info->offset_count = 100000000 / 4;  // Adjust multiplier as needed
    
    // Allocate offsets array
    g_offsets = (ssize_t *)malloc(stream_info->offset_count * sizeof(ssize_t));
    
    // Initialize offsets with non-zero values to make the += meaningful
    for (size_t j = 0; j < stream_info->offset_count; j++) {
        g_offsets[j] = (ssize_t)(j % 1000) - 500;
    }
    
    // Point stream_info to the allocated offsets
    stream_info->offsets = g_offsets;
    
    // Initialize other fields
    stream_info->remaining = 0;
    stream_info->segment_count = 0;
    for (int j = 0; j < 15; j++) {
        stream_info->segments[j] = 0;
    }
    stream_info->count = (ssize_t)stream_info->offset_count;
    stream_info->byte = 1;
    
    // Set offset value for addition
    offset = 123456789LL;
}