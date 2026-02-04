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
    for (i = 0; i < fonts; i += 2) {
        fontlist[i] = listhead[i];
        if (i + 1 < fonts) {
            fontlist[i + 1] = listhead[i + 1];
        }
    }
}
