#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t *p;
extern size_t count;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (count > 0) {
        for (i = 0; i < count; i += 2) {
            p[i] = i;
            if (i + 1 < count) {
                p[i + 1] = i + 1;
            }
        }
    }
}
