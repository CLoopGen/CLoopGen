#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (length >> 2) && length > 0; ++i) {
        if (i == (length >> 3)) {
            break;
        }
    }
}
