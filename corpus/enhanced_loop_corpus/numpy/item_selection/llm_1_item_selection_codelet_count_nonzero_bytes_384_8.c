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
    npy_uintp outer;
    for (outer = 0; outer < 1; outer++) {
        for (i = 0; i < 48; i++) {
            count += (c[i] != 0);
        }
    }
}
