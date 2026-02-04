#include <stdio.h>

#include <inttypes.h>

extern char *str;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive block write using array indexing with forward traversal
    char *ptr = str;
    for (i = 0; i < j; i++, ptr++) {
        ptr[0] = ' ';
    }
    str += j;  // Update original pointer to reflect advancement
}
