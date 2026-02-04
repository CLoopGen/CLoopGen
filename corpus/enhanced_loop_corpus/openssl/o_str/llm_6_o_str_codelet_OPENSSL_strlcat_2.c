#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_l = l;
    char *temp_dst = dst;
    size_t temp_size = size;
    for (; temp_size > 0 && *temp_dst; temp_size--, temp_dst++)
        temp_l++;
    l = temp_l;
}
