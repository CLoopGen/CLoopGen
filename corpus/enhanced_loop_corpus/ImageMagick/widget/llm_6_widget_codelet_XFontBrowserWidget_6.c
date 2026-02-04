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
    char *temp;
    for (i = 0; i < fonts; i++) {
        temp = listhead[i];
        fontlist[i] = temp;
    }
}
