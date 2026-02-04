#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern  char *src;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < size - 2 && src[i] != '\0'; i++) {
        dst[i] = src[i];
        l++;
    }
    size -= i;
}
