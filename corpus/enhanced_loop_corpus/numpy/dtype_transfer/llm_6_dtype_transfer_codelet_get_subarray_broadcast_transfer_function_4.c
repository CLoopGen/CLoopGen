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
    npy_intp prev_offset = offsetruns[0].offset;
    for (loop_index = 1; loop_index < dst_size; ++loop_index) {
        npy_intp current_offset = offsetruns[loop_index].offset;
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
        prev_offset = current_offset;
    }
}
