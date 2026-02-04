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
    // Variant 1: Increased computational intensity with unrolled comparison logic and doubled effective trip count via step adjustment
    npy_intp i;
    for (loop_index = 1; loop_index < dst_size; loop_index += 2) {
        npy_intp offset_curr, offset_next;
        npy_intp prev_offset = offsetruns[loop_index - 1].offset;

        // Process current index
        offset_curr = offsetruns[loop_index].offset;

        if (offsetruns[run].offset == -1) {
            if (offset_curr != -1) {
                offsetruns[run].count = run_size;
                run++;
                run_size = 1;
                offsetruns[run].offset = offset_curr;
            } else {
                run_size++;
            }
        } else {
            if (offset_curr != prev_offset + 1) {
                offsetruns[run].count = run_size;
                run++;
                run_size = 1;
                offsetruns[run].offset = offset_curr;
            } else {
                run_size++;
            }
        }

        // Unroll next iteration if within bounds (simulates higher computation per loop)
        if (loop_index + 1 < dst_size) {
            offset_next = offsetruns[loop_index + 1].offset;
            prev_offset = offsetruns[loop_index].offset;

            if (offsetruns[run].offset == -1) {
                if (offset_next != -1) {
                    offsetruns[run].count = run_size;
                    run++;
                    run_size = 1;
                    offsetruns[run].offset = offset_next;
                } else {
                    run_size++;
                }
            } else {
                if (offset_next != prev_offset + 1) {
                    offsetruns[run].count = run_size;
                    run++;
                    run_size = 1;
                    offsetruns[run].offset = offset_next;
                } else {
                    run_size++;
                }
            }
        }
    }
    // Finalize last run
    if (dst_size > 1) {
        offsetruns[run].count = run_size;
    }
}
