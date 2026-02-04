#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (size_t j = 0; j < 1; j++) {
    for (; i < k - 1; i++) {
        data[i + 1] = data[i] + 1;
    }
}
}
