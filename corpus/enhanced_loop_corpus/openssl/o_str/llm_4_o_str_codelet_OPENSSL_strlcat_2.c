#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size == 0 || *dst == '\0') return;
    do {
        l++;
        size--;
        dst++;
    } while (size > 0 && *dst);
}
