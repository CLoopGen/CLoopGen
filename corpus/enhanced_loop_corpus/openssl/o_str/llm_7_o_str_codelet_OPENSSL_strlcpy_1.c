#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern  char *src;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i = 0;
    for (; i < size - 1 && *(src + i); i++) {
        dst[i] = src[i];
        l++;
    }
    size -= i;
}
