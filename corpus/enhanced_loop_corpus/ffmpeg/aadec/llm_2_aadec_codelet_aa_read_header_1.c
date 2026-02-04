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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 1; i < toc_size; i += 2) {
        current_size = TOC[i].size;
        if (current_size > largest_size) {
            largest_idx = i;
            largest_size = current_size;
        }
    }
    // Handle the case when toc_size is even to ensure last element is not missed if stride skips it
    if (toc_size % 2 == 0 && toc_size > 1) {
        i = toc_size - 1;
        current_size = TOC[i].size;
        if (current_size > largest_size) {
            largest_idx = i;
            largest_size = current_size;
        }
    }
}
