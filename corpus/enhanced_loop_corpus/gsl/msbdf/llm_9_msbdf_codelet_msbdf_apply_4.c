#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t * ordprev;
extern size_t * ordprevbackup;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < 5; i++) {
        j = i * i;
        ordprevbackup[j] = ordprev[j] + i - i;
    }
}
