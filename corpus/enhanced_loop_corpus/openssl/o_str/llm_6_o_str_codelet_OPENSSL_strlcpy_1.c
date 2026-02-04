#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern  char *src;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_size = size;
    for (; temp_size > 1 && *src; temp_size--) {
        char val = *src++;
        *dst++ = val;
        l++;
    }
}
