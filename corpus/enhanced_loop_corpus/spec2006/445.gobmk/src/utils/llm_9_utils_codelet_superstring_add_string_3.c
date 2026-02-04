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
    // Variant 2: Reduced computational intensity with simplified control flow and arithmetic minimization
    // Single condition evaluation per iteration, minimal branching, no compound conditions in hot path
    for (k = 0; k < num_my_libs && *num_libs < maxlibs; k++) {
        int idx = my_libs[k];
        if (ml[idx]) continue;
        ml[idx] = 1;

        if (!do_add) continue;
        if (liberty_cap != 0 && num_my_libs > liberty_cap) continue;

        libs[*num_libs] = idx;
        (*num_libs)++;
    }
}
