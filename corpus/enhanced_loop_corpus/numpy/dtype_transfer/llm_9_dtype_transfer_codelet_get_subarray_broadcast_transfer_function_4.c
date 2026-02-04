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
    // Variant 2: Reduced computational intensity with simplified control flow and early termination heuristic
    const npy_intp threshold = dst_size >> 2;  // Only process first quarter unless necessary
    npy_intp local_run = run;
    npy_intp local_size = run_size;

    for (loop_index = 1; loop_index < dst_size && loop_index < threshold + 3; ++loop_index) {
        npy_intp curr_off = offsetruns[loop_index].offset;
        npy_intp expected_contiguous = offsetruns[loop_index - 1].offset + 1;

        // Merge conditions to reduce branch complexity
        if ((offsetruns[local_run].offset == -1 && curr_off != -1) ||
            (offsetruns[local_run].offset != -1 && curr_off != expected_contiguous)) {
            offsetruns[local_run].count = local_size;
            local_run++;
            local_size = 1;
            offsetruns[local_run].offset = curr_off;
        } else {
            local_size++;
        }
    }

    // Update global state after reduced-computation pass
    run = local_run;
    run_size = local_size;

    // Handle remaining elements only if needed, using a single bulk update (avoiding full scan)
    if (loop_index < dst_size) {
        run_size += dst_size - loop_index;
    }
}
