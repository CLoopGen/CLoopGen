#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t * ordprev;
extern size_t * ordprevbackup;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ordprevbackup[0] = ordprev[0];
    for (i = 1; i < 5; i++) {
        ordprevbackup[i] = ordprev[i];
        ordprevbackup[i-1] += ordprev[i]; // Introduces WAW and RAW dependency, creates loop-carried dependence
    }
}
