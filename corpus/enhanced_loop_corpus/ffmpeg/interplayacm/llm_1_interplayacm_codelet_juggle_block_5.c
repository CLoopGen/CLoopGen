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
    for (i = 0; i < sub_count * sub_len; i += sub_len) {
        block_p[i]++;
    }
}
