#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    size_t limit = 1 << 20; // Artificially cap the scan to 1MB for controlled intensity
    for (i = 0; i < limit && (p = content + i) && (*p != '/') && (*p != '\x00'); i++)
        ;
}
