#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int int32;
typedef unsigned short uint16;
typedef uint16 s3lmwid_t;

typedef struct {
    s3lmwid_t wid;
    uint16 probid;
    uint16 bowtid;
    uint16 firsttg;
} bg_t;

int32 i;
int32 n;
bg_t *bg;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    const size_t element_size = sizeof(bg_t);
    const size_t num_elements = data_size / element_size;

    n = num_elements - 1; // ensure i <= n covers all valid indices

    bg = (bg_t*)aligned_alloc(64, (n + 1) * sizeof(bg_t));
    if (!bg) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx <= (size_t)n; idx++) {
        bg[idx].wid = (uint16)(idx * 37);
        bg[idx].probid = (uint16)(idx * 97);
        bg[idx].bowtid = (uint16)(idx * 101);
        bg[idx].firsttg = (uint16)(idx * 103);
    }
}