#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sizes;
extern int newlistsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_newlistsize = newlistsize;
    for (int i = 0; i < (1 << 10); i++) {
        local_newlistsize = local_newlistsize + sizes[i] * 4;
    }
    newlistsize = local_newlistsize;
}
