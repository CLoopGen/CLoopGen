#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    for (x = -128; x < 128; x++) {
        // Inner loop performs a fixed iteration space derived from original bounds
    }
}
}
