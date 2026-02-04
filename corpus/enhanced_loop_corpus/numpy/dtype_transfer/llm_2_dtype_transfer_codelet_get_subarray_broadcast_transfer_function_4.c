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
    // Variant 1: Consecutive Memory Access with Prefetching Pattern
    // Instead of random access, we traverse offsetruns in a forward sequential manner
    // and simulate prefetching by accessing elements ahead in a strided fashion.
    npy_intp stride = 1;
    for (loop_index = 1; loop_index < dst_size; loop_index += stride) {
        npy_intp current_offset = offsetruns[loop_index].offset;
        npy_intp prev_offset = offsetruns[loop_index - 1].offset;

        if (offsetruns[run].offset == -1) {
            if (current_offset != -1) {
                offsetruns[run].count = run_size;
                run++;
                run_size = 1;
                offsetruns[run].offset = current_offset;
            } else {
                run_size++;
            }
        } else {
            if (current_offset != prev_offset + 1) {
                offsetruns[run].count = run_size;
                run++;
                run_size = 1;
                offsetruns[run].offset = current_offset;
            } else {
                run_size++;
            }
        }

        // Prefetch next few entries to simulate optimized memory access
        // (Compiler may optimize this into actual prefetch instructions)
        __builtin_prefetch(&offsetruns[loop_index + 4], 0, 1);
        __builtin_prefetch(&offsetruns[loop_index + 8], 0, 1);
    }
}
