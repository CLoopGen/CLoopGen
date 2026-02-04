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
    // Variant 2: Indirect and sorted access via an index array
    // Introduce an auxiliary index array that defines a new access order.
    // Here, we simulate accessing my_libs in reverse order (a form of indirect access),
    // which alters spatial locality and may help in scenarios where recent entries are more relevant.

    int idx;
    int index_array[241];

    // Initialize index array with reverse mapping
    for (k = 0; k < num_my_libs; k++) {
        index_array[k] = num_my_libs - 1 - k;
    }

    // Traverse my_libs using the index array (reverse order)
    for (idx = 0; idx < num_my_libs; idx++) {
        k = index_array[idx];  // indirect access through index map
        if (ml[my_libs[k]])
            continue;
        ml[my_libs[k]] = 1;
        if (do_add && (liberty_cap == 0 || num_my_libs <= liberty_cap)) {
            libs[*num_libs] = my_libs[k];
            (*num_libs)++;
            if (*num_libs == maxlibs)
                break;
        }
    }
}
