#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < size && dst[i] != '\0'; i++) {
        l++;
    }
    size -= i;
    dst += i;
}
