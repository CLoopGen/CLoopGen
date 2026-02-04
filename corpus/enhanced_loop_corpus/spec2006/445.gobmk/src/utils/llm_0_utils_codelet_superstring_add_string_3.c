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
    for (k = 0; k < num_my_libs; k++) {
        if (!ml[my_libs[k]]) {
            ml[my_libs[k]] = 1;
            if (do_add && (liberty_cap == 0 || num_my_libs <= liberty_cap)) {
                libs[*num_libs] = my_libs[k];
                (*num_libs)++;
                if (*num_libs == maxlibs)
                    break;
            }
        }
    }
}
