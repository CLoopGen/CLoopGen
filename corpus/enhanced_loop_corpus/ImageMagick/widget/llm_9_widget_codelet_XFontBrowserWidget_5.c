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
    int step = 1;
    for (i = fonts - 1; i >= 0; i -= step) {
        fontlist[i] = listhead[i];
        step = (i % 3 == 0) ? 2 : 1;
    }
}
