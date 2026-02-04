#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef size_t npy_uintp;

extern  char *c;
extern npy_uintp i;
extern npy_uintp count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal with unrolled pair access
    count = 0;
    for (i = 47; i < 48 && i >= 0; i--) {
        count += (c[i] != 0);
    }
}
