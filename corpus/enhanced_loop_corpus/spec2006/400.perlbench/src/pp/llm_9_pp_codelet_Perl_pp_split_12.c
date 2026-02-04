#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with minimal operations and modified trip condition using pointer arithmetic
    // Uses a stride of 4 for lower trip count but includes early exit via conditional break simulation using for-loop control
    char *temp;
    for (m = s, temp = s; m < strend && *m != c; m++, temp++)
        if (temp == m && *(m) == c) break;
}
