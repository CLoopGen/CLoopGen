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
    int *indices = (int*)malloc((sub_count / 2) * sizeof(int));
    for (unsigned int idx = 0; idx < sub_count / 2; idx++) {
        indices[idx] = idx * 2 * sub_len;
    }
    for (i = 0; i < sub_len; i++) {
        p = block_p;
        r0 = wrap_p[0];
        r1 = wrap_p[1];
        for (j = 0; j < sub_count / 2; j++) {
            unsigned int offset = indices[j];
            r2 = *(p + offset);
            *(p + offset) = r1 * 2 + (r0 + r2);
            r3 = *(p + offset + sub_len);
            *(p + offset + sub_len) = r2 * 2 - (r1 + r3);
            r0 = r2;
            r1 = r3;
        }
        *wrap_p++ = r0;
        *wrap_p++ = r1;
        block_p++;
    }
    free(indices);
}
