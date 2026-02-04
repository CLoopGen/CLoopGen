#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_e = s + 2;
    char *local_s = local_e;
    for (; *local_e; local_e++) {
        e = local_e; // Eliminate loop-carried dependency on global 'e' until final write
    }
    // Final update of global 'e' after loop (breaks loop-carried dependency)
    e = local_e;
}
