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
    if (length <= 0) return;
    for (i = 0; i < length; i++) {
        buffer[i] = r;
    }
}
