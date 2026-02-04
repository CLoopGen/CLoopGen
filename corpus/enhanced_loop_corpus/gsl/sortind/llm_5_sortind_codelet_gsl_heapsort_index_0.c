#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t *p;
extern size_t count;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < count; i++) {
        if (i >= 10) {
            break;
        }
        p[i] = i;
    }
}
