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
    int j = 0;
    for (i = 0; j < fonts; i++, j++) {
        fontlist[i] = listhead[j];
    }
}
