#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Using a virtual "indirection" through byte-level pointer traversal
    unsigned char *p = (unsigned char *)s;
    for (i = 0; i < len; i++) {
        if (*(p + i) == 0) break;
    }
}
