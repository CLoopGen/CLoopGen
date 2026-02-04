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
    // Variant 2: Consecutive reverse-order memory access
    // Process the buffer from last to first element
    for (i = 3; i >= 0; i--) {
        c = (int)(*(*p)++);
        (*length)--;
        buffer[i] = (unsigned char)c;
    }
}
