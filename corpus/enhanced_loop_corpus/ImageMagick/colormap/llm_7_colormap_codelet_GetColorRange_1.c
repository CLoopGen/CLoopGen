#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char **ptr_ref = &p;
    char *local_p = start_color;

    // Eliminate loop-carried dependency on global 'p' by using local copy until the end
    for (; (*local_p != '-') && (*local_p != '\x00'); local_p++) {
        if (*local_p == '(') {
            for (local_p++; (*local_p != ')') && (*local_p != '\x00'); local_p++)
                ;
            if (*local_p == '\x00') {
                *ptr_ref = local_p; // Write final value only once at exit
                return;
            }
        }
    }
    *ptr_ref = local_p; // Update global 'p' only at the end — removes per-iteration WAW on 'p'
}
