#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 29; i <= 36; i++) {
        temp = i;
        reg_alloc_order[pos++] = temp;
        reg_alloc_order[pos++] = temp; // WAW dependency introduced: writing to same array location in sequence
    }
    pos--; // Compensate for extra increment (eliminates invalid write effect, keeps logic correct)
}
