#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern int i;
extern int j;
extern int len;
extern int unit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the loop order for better spatial locality
    int stride = unit;
    for (i = 0; i < len; i += unit) {
        int found_nonzero = 0;
        for (j = 0; j < stride; j++) {
            if (str[i + j] != '\x00') {
                found_nonzero = 1;
                break;
            }
        }
        if (!found_nonzero)
            break;
    }
}
