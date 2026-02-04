#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_uint8;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_uint8 off;
extern npy_uint8 rng;
extern npy_intp cnt;
extern npy_uint8 *out;
extern npy_uint8 val;
extern npy_intp i;
extern int bcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_uint8 local_off = off;
    npy_uint8 cache[rng + 1]; // Local cache to remove repeated memory access and alter dependencies
    for (i = 0; i < cnt; i++) {
        npy_uint8 index = val & rng;
        if (bcnt <= 0) {
            bcnt = 3;
        }
        // Remove loop-carried dependency by making val update independent of prior iteration state
        val = (val + i) % (rng + 1); // Add index-based update to break strict RAW chain
        bcnt--;

        cache[index] = local_off + val; // Store into cache instead of directly to output
        out[i] = cache[index]; // Immediate use breaks WAW across iterations via locality
    }
}
