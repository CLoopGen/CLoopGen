#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern int i;
extern int j;
extern int len;
extern int unit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — iterate over each unit-th element first, then offset
    int complete_blocks = len / unit;
    for (j = 0; j < unit; j++) {
        int zero_block = 1;
        for (i = 0; i < complete_blocks; i++) {
            if (str[i * unit + j] != '\x00') {
                zero_block = 0;
                break;
            }
        }
        if (zero_block)
            break;
    }
    // Adjust final state of i and j to reflect original semantics:
    // If j < unit, then a full zero block was found at position i_start = 0
    // We set i to 0 to reflect start of the detected block
    if (j < unit)
        i = 0;
    else
        i = len; // No zero block found, so i ends past valid range
}
