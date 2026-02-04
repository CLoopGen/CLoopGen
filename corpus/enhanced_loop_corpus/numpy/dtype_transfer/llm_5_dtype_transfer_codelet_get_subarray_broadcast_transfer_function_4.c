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
    for (loop_index = 1; loop_index < dst_size; ++loop_index) {
        npy_intp current_offset = offsetruns[loop_index].offset;

        if (offsetruns[run].offset == -1) {
            if (current_offset != -1) {
                offsetruns[run].count = run_size;
                run = run + 1;
                run_size = 1;
                offsetruns[run].offset = current_offset;
            }
            run_size += (current_offset == -1) ? 1 : 0;
        } else {
            npy_intp expected_offset = offsetruns[loop_index - 1].offset + 1;
            int is_consecutive = (current_offset == expected_offset);

            if (!is_consecutive || current_offset == -1) {
                offsetruns[run].count = run_size;
                run++;
                run_size = 1;
                offsetruns[run].offset = current_offset;
            } else {
                run_size++;
            }
        }
    }
}
