#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using array indexing instead of pointer dereference
    for (size_t i = 0; i < size && dst[i] != '\0'; i++) {
        l++;
    }
}
