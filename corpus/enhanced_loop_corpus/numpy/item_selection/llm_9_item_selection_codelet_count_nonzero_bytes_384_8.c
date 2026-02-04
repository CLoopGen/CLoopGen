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
    npy_uintp factor = 3;
    npy_uintp trip_count = 48 * factor;
    for (i = 0; i < trip_count; i++) {
        npy_uintp idx = i % 48;
        count += (c[idx] != 0) * (i / 48 + 1);
    }
}
