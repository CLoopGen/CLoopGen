#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t* access_pattern = (size_t*)malloc(sizeof(size_t) * (length > 8 ? length : 9));
    if (!access_pattern) return;
    for (size_t i = 0; i < (length > 8 ? length : 9); i++) {
        access_pattern[i] = 2 + i;
    }
    size_t i = 0;
    for (level = 2; ((access_pattern[i] * access_pattern[i] * access_pattern[i]) < length); level++, i++)
        ;
    free(access_pattern);
}
