#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *ftab;
Int32 i;
Int32 j;
Int32 runningOrder[256];
Int32 vv;
Int32 h;

void init_vars() {
    // Allocate ftab: needs to be large enough to support index ((255 + 1) << 8) + some offset safely
    // Max index accessed: ((vv)+1) << 8, vv up to 255 -> (256 << 8) = 65536, but we also access ftab[(runningOrder[j-h]+1)<<8]
    // So we need at least (256+1) << 8 = 65792 entries. Let's allocate 65792 + safety margin.
    const size_t ftab_size = 65792 + 1024;
    
    // To achieve ~0.01s runtime, we may need larger data to slow down the loop
    // The loop runs 256 - h iterations, and inner while depends on data ordering.
    // We'll set h=1 to maximize iterations (~255), and initialize ftab with values that cause moderate swapping.

    ftab = (UInt32*)calloc(ftab_size, sizeof(UInt32));
    if (!ftab) {
        exit(1);
    }

    // Initialize ftab with cumulative counts to simulate realistic suffix array data
    // Fill ftab with increasing values to represent bucket sizes
    for (size_t idx = 0; idx < ftab_size; idx++) {
        // Use pseudo-random but deterministic values scaled by index
        ftab[idx] = (idx * 131) % 1000;
    }

    // Build prefix sum so that ftab[i<<8] represents cumulative count
    for (size_t idx = 1; idx < ftab_size; idx++) {
        ftab[idx] += ftab[idx-1];
    }

    // Initialize runningOrder: start with shuffled indices 0..255
    for (int idx = 0; idx < 256; idx++) {
        runningOrder[idx] = (idx * 17) % 256;  // deterministic shuffle
    }

    // Set h to 1 to ensure many iterations and comparisons
    h = 1;

    // Initialize other scalars to safe values
    i = 0;
    j = 0;
    vv = 0;
}