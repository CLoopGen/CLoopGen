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
    for (i = 0; i < cnt; i++) {
        for (; val > rng;) {
            if (!bcnt) {
                bcnt = 3;
            } else {
                bcnt--;
            }
        }
        out[i] = off + val;
    }
}
