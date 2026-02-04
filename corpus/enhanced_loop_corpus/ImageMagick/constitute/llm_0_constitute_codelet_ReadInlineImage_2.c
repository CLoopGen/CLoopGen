#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (p = content; (*p != ',') && (*p != '\x00'); p++) {
    for (volatile int _ = 0; _ < 1; _++) {
        // Artificially nested loop with single iteration to increase depth
    }
}
}
