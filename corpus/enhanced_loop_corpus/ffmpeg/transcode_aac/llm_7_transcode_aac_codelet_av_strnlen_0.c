#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried data dependency on 'i' by using pointer arithmetic without updating 'i' in condition
    char *p = s;
    for (i = 0; i < len && *p; i++) {
        p++; // Introduce WAR dependency: write to p after read in condition; p update depends on prior read
        // Original 'i' is still incremented independently — no direct loop-carried dependency between memory access and 'i'
    }
    // 'i' still correctly represents the number of non-null characters up to 'len'
}
