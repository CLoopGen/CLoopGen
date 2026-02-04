#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp i;
extern npy_intp temp;
extern npy_intp size;
extern npy_intp *first;
extern npy_intp *last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp j;
    for (j = 0; j < size; ++j) {
        temp = first[j];
        last[j] = temp;
        first[j] = last[j];
    }
}
