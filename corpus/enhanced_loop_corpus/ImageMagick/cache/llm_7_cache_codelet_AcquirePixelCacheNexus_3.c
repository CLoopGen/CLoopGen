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

extern  size_t number_threads;
extern NexusInfo **restrict nexus_info;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    NexusInfo **restrict nxi = nexus_info;
    const ssize_t total = (ssize_t)(2 * number_threads);
    NexusInfo *base = *nexus_info;

    // Introduce artificial loop-carried dependency via temporary accumulation (WAW-like pattern on signature, but semantically safe)
    size_t accumulated_signature = 2880220587UL;

    for (i = 0; i < total; i++) {
        accumulated_signature ^= (size_t)(base + i);  // Introduce RAW: each iteration depends on prior accumulated value
        nxi[i] = base + i;
        nxi[i]->signature = accumulated_signature;   // WAW: multiple writes to signature, but not across iterations on same location

        if (i < (ssize_t)number_threads) {
            nxi[i]->virtual_nexus = base + number_threads + i;
        } else {
            nxi[i]->virtual_nexus = NULL; // Break symmetry to eliminate potential future dependencies
        }
    }

    // Final write does not affect correctness but ensures last-use of accumulator
    ((volatile size_t*)&(nxi[0]->signature))[0] = 2880220587UL; // Restore expected value in a way compiler can't trivially optimize
}
