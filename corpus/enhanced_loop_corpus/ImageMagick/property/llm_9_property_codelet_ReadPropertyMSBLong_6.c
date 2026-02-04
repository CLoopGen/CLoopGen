#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char **p;
extern size_t *length;
extern int c;
extern ssize_t i;
extern unsigned char buffer[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        if (i % 2 == 0 && (*length) > 0) {
            c = (int)(*(*p)++);
            (*length)--;
        }
        buffer[i % 4] ^= (unsigned char)(c * (i % 3 + 1)); // Increased arithmetic intensity
    }
}
