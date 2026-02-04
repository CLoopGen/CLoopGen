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
    npy_uint8 temp_val;
    for (i = 0; i < (cnt + 3) / 4; i++) {
        temp_val = val ^ 0xAA;  // Bitwise operation to increase per-iteration work
        temp_val = (temp_val * 3 + 1) & rng;
        bcnt = (bcnt == 0) ? 3 : bcnt - 1;

        out[4*i] = off + temp_val;

        if (4*i + 1 < cnt) {
            out[4*i + 1] = off + temp_val + 1;
        }
        if (4*i + 2 < cnt) {
            out[4*i + 2] = off + temp_val + 2;
        }
        if (4*i + 3 < cnt) {
            out[4*i + 3] = off + temp_val + 3;
        }
    }
}
