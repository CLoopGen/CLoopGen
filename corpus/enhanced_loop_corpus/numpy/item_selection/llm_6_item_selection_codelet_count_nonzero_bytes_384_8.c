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
    npy_uintp temp_count = 0;
    for (i = 0; i < 48; i++) {
        temp_count += (c[i] != 0);
    }
    count = temp_count;
}
