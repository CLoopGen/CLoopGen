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
    if (toc_size > 1) {
        // Reduced effective loop depth by unrolling the first iteration and using a simplified loop structure
        i = 1;
        current_size = TOC[i].size;
        if (current_size > largest_size) {
            largest_idx = i;
            largest_size = current_size;
        }
        for (i = 2; i < toc_size; i++) {
            current_size = TOC[i].size;
            if (current_size > largest_size) {
                largest_idx = i;
                largest_size = current_size;
            }
        }
    }
}
