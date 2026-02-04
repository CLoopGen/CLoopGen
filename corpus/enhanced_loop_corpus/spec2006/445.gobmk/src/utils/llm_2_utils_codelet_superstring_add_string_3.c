#include <stdio.h>

#include <inttypes.h>

extern int *num_libs;
extern int *libs;
extern int maxlibs;
extern int liberty_cap;
extern char ml[400];
extern int do_add;
extern int num_my_libs;
extern int my_libs[241];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern
    // Instead of iterating sequentially over my_libs, we access elements with a stride of 2,
    // processing even indices first, then odd indices in a second pass if needed.
    // This changes the memory access pattern to strided, potentially improving cache behavior
    // for certain data layouts or enabling better prefetching.

    int stride = 2;
    int start;

    for (start = 0; start < stride; start++) {
        for (k = start; k < num_my_libs; k += stride) {
            if (ml[my_libs[k]])
                continue;
            ml[my_libs[k]] = 1;
            if (do_add && (liberty_cap == 0 || num_my_libs <= liberty_cap)) {
                libs[*num_libs] = my_libs[k];
                (*num_libs)++;
                if (*num_libs == maxlibs)
                    goto exit_loop;
            }
        }
    }
exit_loop:;
}
