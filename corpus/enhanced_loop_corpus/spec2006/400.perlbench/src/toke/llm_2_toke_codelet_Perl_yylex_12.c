#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 steps
    // This variant checks two characters at a time if possible, reducing iterations
    char *ptr = d;
    STRLEN count = len;

    for (; count >= 2; count -= 2, ptr += 2) {
        char c1 = ptr[0];
        char c2 = ptr[1];
        if (!((c1 == ' ' || c1 == '\t' || c1 == '\n' || c1 == '\r' || c1 == '\f') &&
              (c2 == ' ' || c2 == '\t' || c2 == '\n' || c2 == '\r' || c2 == '\f'))) {
            break;
        }
    }

    // Handle remaining characters one by one
    for (; count > 0 && (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\f'); --count, ++ptr)
        ;

    // Update original variables
    d = ptr;
    len = count;
}
