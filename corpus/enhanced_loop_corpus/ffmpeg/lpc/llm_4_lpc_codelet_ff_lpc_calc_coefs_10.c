#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max_order;
extern double ref[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (max_order <= 1) return;
    for (i = max_order - 1; i > 0; i--) {
        ref[i] = ref[i - 1] - ref[i];
    }
}
