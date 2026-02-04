#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_len = len;
    for (i = 0; i < temp_len; i++) {
        if (!s[i]) break;
        // Move the length check into a local copy (breaking potential aliasing-based dependencies)
        // Introduce a conditional break instead of combining in loop condition
        // Eliminates combined condition evaluation, isolating the array access dependency (RAW on s[i])
        // Loop-carried dependency on 'i' remains, but memory dependency on 's[i]' is now separated from bound check
    }
    // Semantics preserved: loop stops at first null or when i reaches len
}
