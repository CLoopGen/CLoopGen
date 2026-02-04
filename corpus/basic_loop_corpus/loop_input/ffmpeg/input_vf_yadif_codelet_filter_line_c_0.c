#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w;
int prefs;
int mrefs;
int mode;
uint8_t *dst;
uint8_t *prev;
uint8_t *cur;
uint8_t *next;
int x;
uint8_t *prev2;
uint8_t *next2;

static uint8_t *alloc_aligned(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        exit(1);
    }
    return (uint8_t*)ptr;
}

void init_vars() {
    const int data_size = 16 * 1024 * 1024; // ~16MB total data to target ~0.01s runtime

    w = data_size;
    prefs = 1;
    mrefs = -1;
    mode = 0; // ensures both branches of mode&2 are tested, but initialize conservatively

    // Allocate buffers with padding to prevent out-of-bounds access
    // Maximum offset in cur: mrefs + 1 + 2 = -1 + 1 + 2 = 2 (positive), and mrefs-1+(-2) = -1-1-2 = -4
    // So we need at least 4 extra on left and 2 on right -> total extra 6
    const int pad_left = 8;
    const int pad_right = 8;
    const int total_size = data_size + pad_left + pad_right;

    dst = alloc_aligned(total_size);
    cur = alloc_aligned(total_size);
    prev = alloc_aligned(total_size);
    next = alloc_aligned(total_size);
    prev2 = alloc_aligned(total_size * 2); // accessed at 2*mrefs, so needs larger stride
    next2 = alloc_aligned(total_size * 2);

    // Initialize with pseudo-random data for realistic testing
    srand(time(NULL));
    for (int i = 0; i < total_size; i++) {
        cur[pad_left + i] = rand() & 0xFF;
        prev[pad_left + i] = rand() & 0xFF;
        next[pad_left + i] = rand() & 0xFF;
        if (i < total_size * 2) {
            ((uint8_t*)prev2)[i] = rand() & 0xFF;
            ((uint8_t*)next2)[i] = rand() & 0xFF;
        }
    }

    // Adjust pointers so that logical start is after padding
    dst += pad_left;
    cur += pad_left;
    prev += pad_left;
    next += pad_left;

    // For prev2 and next2, since they're indexed with 2*mrefs, we need even more offset
    // Max negative index used: 2 * mrefs -> 2*(-1) = -2, but also base pointer accesses [0]
    // So shift by at least 4 to be safe
    const int extra_offset_2x = 8;
    prev2 += extra_offset_2x;
    next2 += extra_offset_2x;

    // Ensure no out-of-bounds: the loop runs for 'w' iterations and accesses:
    //   cur[mrefs-1 + (-2)] = cur[-1-1-2] = cur[-4] -> minimum offset -4
    //   cur[mrefs+1 + (2)]  = cur[-1+1+2] = cur[2]  -> maximum offset +2
    // So our padding of 8 on each side is sufficient.
}