#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern uint64_t off;
extern npy_intp cnt;
extern uint64_t *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_off = off;
    for (i = 0; i < cnt; i++) {
        out[i] = local_off + i; // Remove loop-carried dependency; each iteration independent
        local_off = off; // WAR: Write-after-read on local_off, but no actual loop-carried dependency
    }
}
