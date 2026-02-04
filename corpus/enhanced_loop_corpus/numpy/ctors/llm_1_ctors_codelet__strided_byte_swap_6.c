#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern void *p;
extern npy_intp stride;
extern npy_intp n;
extern char *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective nesting (was already flat), now unrolled partially to simulate reduced loop control overhead
    // Assuming n can be even for simplicity in unrolling; behavior preserved using stride and pointer arithmetic
    char *local_a = (char *)p;
    npy_intp iter = n;
    for (; iter > 1; iter -= 2, local_a += 2 * stride) {
        a = local_a;          // Simulate original body
        a = local_a + stride; // Unrolled second iteration
    }
    if (iter == 1) {
        a = local_a;
    }
}
