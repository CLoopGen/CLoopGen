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



void loop(){
    // Variant 1: Increased computational intensity with redundant bounds check unrolling simulation
    // Trip count effectively reduced by processing two elements per iteration when possible
    int i;
    for (k = 0; k < num_my_libs; k += 2) {
        // Process element k
        if (!ml[my_libs[k]]) {
            ml[my_libs[k]] = 1;
            if (do_add && (liberty_cap == 0 || num_my_libs <= liberty_cap)) {
                libs[*num_libs] = my_libs[k];
                (*num_libs)++;
                if (*num_libs == maxlibs)
                    break;
            }
        }

        // Process element k+1 if within bounds
        if (k + 1 < num_my_libs) {
            if (!ml[my_libs[k + 1]]) {
                ml[my_libs[k + 1]] = 1;
                if (do_add && (liberty_cap == 0 || num_my_libs <= liberty_cap)) {
                    libs[*num_libs] = my_libs[k + 1];
                    (*num_libs)++;
                    if (*num_libs == maxlibs)
                        break;
                }
            }
        }
    }
}
