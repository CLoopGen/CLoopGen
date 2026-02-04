#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern STRLEN i;
extern int accumulate;
extern int any_fatals;
extern char *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    STRLEN limit = len - (len % 2); // Ensure even length to avoid out-of-bounds
    for (i = 0; i < limit; i += 2) {
        accumulate |= ptr[i];
        any_fatals |= (ptr[i] & 170);
    }
    // Handle last element if original length was odd
    if (len % 2 == 1) {
        accumulate |= ptr[len - 1];
        any_fatals |= (ptr[len - 1] & 170);
    }
}
