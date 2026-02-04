#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < 1; i++) {
        for (count = 0; fmts[count] != -1; count++)
            ;
    }
}
