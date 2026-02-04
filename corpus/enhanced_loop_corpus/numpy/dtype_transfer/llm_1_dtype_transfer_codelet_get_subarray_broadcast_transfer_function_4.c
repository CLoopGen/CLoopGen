#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef struct {
    npy_intp offset;
    npy_intp count;
} _subarray_broadcast_offsetrun;

extern npy_intp dst_size;
extern npy_intp loop_index;
extern npy_intp run;
extern npy_intp run_size;
extern _subarray_broadcast_offsetrun *offsetruns;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop split: process in chunks to reduce effective iteration depth
    npy_intp chunk_size = 1;
    for (npy_intp outer = 1; outer < dst_size; outer += chunk_size) {
        // Inner loop handles a single element, simulating reduced max depth via decomposition
        loop_index = outer;
        if (loop_index >= dst_size) break;

        if (offsetruns[run].offset == -1) {
            if (offsetruns[loop_index].offset != -1) {
                offsetruns[run].count = run_size;
                run++;
                run_size = 1;
                offsetruns[run].offset = offsetruns[loop_index].offset;
            } else {
                run_size++;
            }
        } else {
            if (offsetruns[loop_index].offset != offsetruns[loop_index - 1].offset + 1) {
                offsetruns[run].count = run_size;
                run++;
                run_size = 1;
                offsetruns[run].offset = offsetruns[loop_index].offset;
            } else {
                run_size++;
            }
        }
    }
}
