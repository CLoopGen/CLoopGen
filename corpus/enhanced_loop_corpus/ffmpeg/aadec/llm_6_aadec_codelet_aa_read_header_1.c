#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct toc_entry {
    uint32_t offset;
    uint32_t size;
};


extern int i;
extern int largest_idx;
extern uint32_t toc_size;
extern int64_t largest_size;
extern int64_t current_size;
extern struct toc_entry TOC[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_largest_idx = largest_idx;
    int64_t temp_largest_size = largest_size;
    for (i = 1; i < toc_size; i++) {
        current_size = TOC[i].size;
        if (current_size > temp_largest_size) {
            temp_largest_idx = i;
            temp_largest_size = current_size;
        }
    }
    largest_idx = temp_largest_idx;
    largest_size = temp_largest_size;
}
