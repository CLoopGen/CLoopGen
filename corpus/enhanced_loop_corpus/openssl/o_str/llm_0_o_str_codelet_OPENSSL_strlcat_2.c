#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; size > 0 && *dst; size--, dst++) {
        for (size_t i = 0; i < 1; i++) {
            l++;
        }
    }
}
