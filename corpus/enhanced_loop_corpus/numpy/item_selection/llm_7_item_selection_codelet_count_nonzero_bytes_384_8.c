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
    npy_uintp local_c[48];
    npy_uintp sum = 0;
    for (i = 0; i < 48; i++) {
        local_c[i] = (c[i] != 0);
    }
    for (i = 0; i < 48; i++) {
        sum += local_c[i];
    }
    count = sum;
}
