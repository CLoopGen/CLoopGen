#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int sub_count;
extern unsigned int sub_len;
extern unsigned int i;
extern int *block_p;
extern int *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0, p = block_p; i < sub_count; i++) {
        temp += 2;         // Remove loop-carried dependency on memory; use local accumulator
        p[0] = temp;       // WAW hazard eliminated by writing independent values in each iteration
        p += sub_len;
    }
    // Final write-back not needed since each element is written independently
}
