#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate pointer array
    char **access_order = (char**)malloc(len * sizeof(char*));
    if (!access_order) return;
    for (size_t idx = 0; idx < len; idx++) {
        access_order[idx] = &s[idx];
    }
    for (i = 0; i < len; i++) {
        if (*(access_order[i]) == '\0') break;
    }
    free(access_order);
}
