#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal with decrementing source pointer
    unsigned short *temp_x = x + ((6 + 3) - 1 - 2);  // Point to the end of the data segment
    for (i = 2; i < (6 + 3) - 1; i++)
        *p++ = *(--temp_x);
}
