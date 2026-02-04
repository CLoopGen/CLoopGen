#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *indices;
extern ssize_t i;
extern size_t a;
extern size_t b;
extern unsigned char remapped[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        for (ssize_t j = 0; j < 4; j++) {
            ssize_t idx = i * 4 + j;
            if (a < b)
                remapped[idx] = (indices[idx] ^ 1) & 3;
            else if (a == b)
                remapped[idx] = 0;
            else
                remapped[idx] = indices[idx];
        }
    }
}
