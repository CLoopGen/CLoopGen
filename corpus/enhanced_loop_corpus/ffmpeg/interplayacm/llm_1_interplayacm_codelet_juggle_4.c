#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *wrap_p;
extern int *block_p;
extern unsigned int sub_len;
extern unsigned int sub_count;
extern unsigned int i;
extern unsigned int j;
extern int *p;
extern unsigned int r0;
extern unsigned int r1;
extern unsigned int r2;
extern unsigned int r3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sub_len; i++) {
        for (j = 0; j < sub_count / 2; j++) {
            p = block_p + i; // Adjust base pointer per outer index
            r0 = wrap_p[j * 2];     // Simulate staggered access pattern
            r1 = wrap_p[j * 2 + 1];
            r2 = *(p + j * 2 * sub_len);
            *(p + j * 2 * sub_len) = r1 * 2 + (r0 + r2);
            r3 = *(p + (j * 2 + 1) * sub_len);
            *(p + (j * 2 + 1) * sub_len) = r2 * 2 - (r1 + r3);
            wrap_p[j * 2] = r2;
            wrap_p[j * 2 + 1] = r3;
        }
    }
    // Final update of wrap_p and block_p as batch operation
    wrap_p += sub_count;
    block_p += sub_len;
}
