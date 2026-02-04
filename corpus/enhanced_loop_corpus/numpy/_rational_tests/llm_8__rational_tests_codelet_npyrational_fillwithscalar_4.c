#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef struct {
    int n;
    int dmm;
} rational;

extern npy_intp length;
extern rational r;
extern rational *buffer;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    // Trip count halved, but each iteration performs two writes and a simple arithmetic update on r
    rational temp = r;
    for (i = 0; i < length / 2; i++) {
        temp.n += i % 7;
        temp.dmm ^= (i & 3);
        buffer[2 * i] = temp;
        if (2 * i + 1 < length) {
            buffer[2 * i + 1] = temp;
        }
    }
}
