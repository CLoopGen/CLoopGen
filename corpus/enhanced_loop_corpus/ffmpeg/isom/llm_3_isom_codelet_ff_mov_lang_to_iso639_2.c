#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int code;
extern char to[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with step
    char *base = &to[2];
    for (i = 0; i < 3; i++) {
        *(base - i) = 96 + (code & 31);
        code >>= 5;
    }
}
