#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (size_t outer = 0; outer < k - 1; outer++) {
    if (i < k - 1) {
        data[i + 1] = data[i] + 1;
        i++;
    }
}
}
