#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer array (simulated with offset indexing)
    char *ptr;
    for (i = 0; i < len; i++) {
        ptr = &s[i];  // Indirect access through pointer
        if (*ptr == '\0') break;
    }
}
