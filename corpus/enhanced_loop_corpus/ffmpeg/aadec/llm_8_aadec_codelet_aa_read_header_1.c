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
for (i = 0; i < toc_size; i += 2) {
    if (i + 1 < toc_size) {
        int64_t size1 = TOC[i].size;
        int64_t size2 = TOC[i + 1].size;
        if (size1 > largest_size) {
            largest_idx = i;
            largest_size = size1;
        }
        if (size2 > largest_size) {
            largest_idx = i + 1;
            largest_size = size2;
        }
    } else {
        current_size = TOC[i].size;
        if (current_size > largest_size) {
            largest_idx = i;
            largest_size = current_size;
        }
    }
}
}
