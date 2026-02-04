#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int opt_order;
extern int allsteps;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_steps = allsteps;
    for (i = 0; i < opt_order; i++) {
        local_steps = local_steps * 3;
        allsteps = local_steps; // Introduce WAW and WAR dependency: write-after-write and write-after-read on allsteps
    }
}
