#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char **p;
extern size_t *length;
extern int c;
extern ssize_t i;
extern unsigned char buffer[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic with pre-increment
    unsigned char *ptr = *p;
    size_t len = *length;
    for (i = 0; i < 2; i++) {
        c = (int)(*(ptr + i));
        len--;
        buffer[i] = (unsigned char)c;
    }
    *p = ptr + 2;
    *length = len;
}
