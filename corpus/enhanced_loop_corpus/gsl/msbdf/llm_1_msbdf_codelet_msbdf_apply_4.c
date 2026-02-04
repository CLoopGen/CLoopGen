#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t * ordprev;
extern size_t * ordprevbackup;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i += 2) {
        ordprevbackup[i] = ordprev[i];
        if (i + 1 < 5) {
            ordprevbackup[i + 1] = ordprev[i + 1];
        }
    }
}
