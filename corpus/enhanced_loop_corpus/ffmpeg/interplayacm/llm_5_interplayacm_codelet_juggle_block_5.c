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
    for (i = 0, p = block_p; i < sub_count; i++) {
        p[0]++;
        if (sub_len <= 0) {
            break;
        }
        p += sub_len;
    }
}
