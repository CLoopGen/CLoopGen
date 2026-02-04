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
    int temp_libs[241];
    int temp_count = 0;
    for (k = 0; k < num_my_libs; k++) {
        int idx = my_libs[k];
        if (ml[idx])
            continue;
        ml[idx] = 1;
        if (do_add && (liberty_cap == 0 || num_my_libs <= liberty_cap)) {
            temp_libs[temp_count] = idx;
            temp_count++;
        }
    }
    for (int i = 0; i < temp_count; i++) {
        libs[*num_libs] = temp_libs[i];
        (*num_libs)++;
        if (*num_libs == maxlibs)
            break;
    }
}
