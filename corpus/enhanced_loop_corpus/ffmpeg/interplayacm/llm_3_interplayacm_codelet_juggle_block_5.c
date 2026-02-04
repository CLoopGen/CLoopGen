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
    int *indices = (int*)malloc(sub_count * sizeof(int));
    for (i = 0; i < sub_count; i++) {
        indices[i] = i * sub_len;
    }
    for (i = 0; i < sub_count; i++) {
        block_p[indices[i]]++;
    }
    free(indices);
}
