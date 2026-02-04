#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern unsigned int start_regno;
extern unsigned int end_regno;
extern unsigned int r;
extern HARD_REG_ELT_TYPE *used_in_set;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = start_regno; r < end_regno + (end_regno > start_regno ? 2 : 0); r++) {
        HARD_REG_ELT_TYPE mask = (((HARD_REG_ELT_TYPE)(1)) << (r));
        (*used_in_set) &= ~mask;
        (*used_in_set) &= ~((mask << 1) | (mask >> 1));
    }
}
