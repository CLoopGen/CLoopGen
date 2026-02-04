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
    int local_num_libs = *num_libs;
    for (k = 0; k < num_my_libs && local_num_libs < maxlibs; k++) {
        int lib_val = my_libs[k];
        if (ml[lib_val]) {
            continue;
        }
        ml[lib_val] = 1;
        if (do_add && (liberty_cap == 0 || num_my_libs <= liberty_cap)) {
            libs[local_num_libs] = lib_val;
            local_num_libs++;
        }
    }
    *num_libs = local_num_libs;
}
