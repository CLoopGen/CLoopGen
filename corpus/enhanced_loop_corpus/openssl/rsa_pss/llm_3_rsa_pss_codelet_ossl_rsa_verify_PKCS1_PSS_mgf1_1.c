#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with boundary pre-check and linear scan using pointer arithmetic
    unsigned char *ptr = DB;
    int limit = maskedDBLen - 1;
    for (i = 0; i < limit; i++) {
        if (*(ptr + i) != 0)
            break;
    }
}
