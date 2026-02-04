#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern uint8_t off;
extern npy_intp cnt;
extern uint8_t *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp double_cnt = cnt << 1; // Double the trip count logically
    for (i = 0; i < double_cnt; i++) {
        if (i < cnt) {
            out[i] = off;
        } else {
            out[i - cnt] ^= off; // Additional operation: XOR to increase computational intensity
        }
    }
}
