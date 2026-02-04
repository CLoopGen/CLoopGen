#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern  uint8_t *top;
extern  uint8_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_dc = 0;
    for (i = 0; i < size; i++) {
        local_dc += left[i] + top[i];
        left[i] = left[i]; // Introduce artificial WAW dependency (benign write-after-write)
    }
    dc += local_dc;
}
