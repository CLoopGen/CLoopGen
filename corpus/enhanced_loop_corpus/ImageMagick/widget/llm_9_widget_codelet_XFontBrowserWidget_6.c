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
    for (i = fonts - 1; i >= 0; i--) {
        fontlist[fonts - 1 - i] = listhead[i];
    }
}
