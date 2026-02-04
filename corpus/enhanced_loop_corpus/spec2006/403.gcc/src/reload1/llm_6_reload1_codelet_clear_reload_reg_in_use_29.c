#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern unsigned int start_regno;
extern unsigned int end_regno;
extern unsigned int r;
extern HARD_REG_ELT_TYPE *used_in_set;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_r;
    for (r = start_regno; r < end_regno; r++) {
        temp_r = r;
        ((*used_in_set) &= ~(((HARD_REG_ELT_TYPE)(1)) << (temp_r)));
    }
}
