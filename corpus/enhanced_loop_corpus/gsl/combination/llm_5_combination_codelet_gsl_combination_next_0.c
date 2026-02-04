#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < k - 1 && data != NULL; i++) {
        size_t temp = data[i];
        if (temp % 2 == 0) {
            data[i + 1] = temp + 1;
        } else {
            data[i + 1] = temp + 2;
        }
    }
}
