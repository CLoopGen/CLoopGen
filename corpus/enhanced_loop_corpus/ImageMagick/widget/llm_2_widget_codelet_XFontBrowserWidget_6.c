#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char **fontlist;
extern char **listhead;
extern int fonts;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (step by 2, handle odd/even sizes)
    int step = 2;
    int limit = fonts;

    for (i = 0; i < limit; i += step) {
        fontlist[i] = listhead[i];
        if (i + 1 < limit) {
            fontlist[i + 1] = listhead[i + 1];
        }
    }
}
