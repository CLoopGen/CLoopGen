#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
} RectangleInfo;

typedef unsigned long long MagickSizeType;

typedef float MagickFloatType;

typedef MagickFloatType Quantum;

typedef struct _NexusInfo {
    MagickBooleanType mapped;
    RectangleInfo region;
    MagickSizeType length;
    Quantum *cache;
    Quantum *pixels;
    MagickBooleanType authentic_pixel_cache;
    void *metacontent;
    size_t signature;
    struct _NexusInfo *virtual_nexus;
} NexusInfo;

size_t number_threads = 64;
NexusInfo *nexus_info_storage = NULL;
NexusInfo **restrict nexus_info = NULL;
ssize_t i;

void init_vars() {
    const size_t total_nexuses = 2 * number_threads;

    nexus_info_storage = (NexusInfo*)calloc(total_nexuses, sizeof(NexusInfo));
    nexus_info = (NexusInfo**)malloc(total_nexuses * sizeof(NexusInfo*));
    
    if (!nexus_info_storage || !nexus_info) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_nexuses; idx++) {
        nexus_info[idx] = &nexus_info_storage[idx];
        nexus_info[idx]->mapped = MagickFalse;
        nexus_info[idx]->region.width = 100;
        nexus_info[idx]->region.height = 100;
        nexus_info[idx]->region.x = 0;
        nexus_info[idx]->region.y = 0;
        nexus_info[idx]->length = 100;
        nexus_info[idx]->cache = (Quantum*)calloc(100, sizeof(Quantum));
        nexus_info[idx]->pixels = (Quantum*)calloc(100, sizeof(Quantum));
        nexus_info[idx]->authentic_pixel_cache = MagickFalse;
        nexus_info[idx]->metacontent = NULL;
        nexus_info[idx]->signature = 0;
        nexus_info[idx]->virtual_nexus = NULL;
    }
}