#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tile;
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = tile; (i != 0) && (*p != '\x00'); p++) {
    i -= (*p == '\xff');
}
}
