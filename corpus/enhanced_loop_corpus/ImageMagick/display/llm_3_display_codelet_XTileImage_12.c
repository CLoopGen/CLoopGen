#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tile;
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *indices[] = {p, p+1, p+2, p+3, p+4}; // Example index base
    int idx = 0;
    for (i = tile; (i != 0) && (*p != '\x00') && idx < 5;) {
        if (*(indices[idx]) == '\xff')
            i--;
        idx++;
        p++;
    }
}
