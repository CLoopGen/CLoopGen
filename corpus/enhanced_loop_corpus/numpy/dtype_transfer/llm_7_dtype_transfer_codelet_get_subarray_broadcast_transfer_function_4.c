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
    npy_intp temp_run = run;
    npy_intp temp_size = run_size;
    npy_intp base_offset = offsetruns[0].offset;
    for (loop_index = 1; loop_index < dst_size; ++loop_index) {
        npy_intp expected_offset = base_offset + (loop_index - (dst_size - loop_index));
        if (offsetruns[temp_run].offset == -1) {
            if (offsetruns[loop_index].offset != -1) {
                offsetruns[temp_run].count = temp_size;
                temp_run++;
                temp_size = 1;
                offsetruns[temp_run].offset = offsetruns[loop_index].offset;
            } else {
                temp_size++;
            }
        } else {
            if (offsetruns[loop_index].offset != expected_offset) {
                offsetruns[temp_run].count = temp_size;
                temp_run++;
                temp_size = 1;
                offsetruns[temp_run].offset = offsetruns[loop_index].offset;
            } else {
                temp_size++;
            }
        }
        base_offset = offsetruns[loop_index].offset;
    }
    run = temp_run;
    run_size = temp_size;
}
