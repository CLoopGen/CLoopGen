#include <stdio.h>

#include <inttypes.h>

struct page_group {
    struct page_group *next;
    char *allocation;
    size_t alloc_size;
    unsigned int in_use;
};


typedef struct page_entry {
    struct page_entry *next;
    size_t bytes;
    char *page;
    struct page_group *group;
    unsigned long *save_in_use_p;
    unsigned short context_depth;
    unsigned short num_free_objects;
    unsigned short next_bit_hint;
    unsigned char order;
    unsigned long in_use_p[1];
} page_entry;

extern page_entry *p;
extern unsigned int i;
extern size_t num_objects;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with coarser granularity and batched operations
    size_t step = 2; // Process two elements at once to reduce loop iterations
    size_t limit = (((num_objects + 63) / 64) * sizeof(unsigned long) + sizeof(unsigned long) - 1) / sizeof(unsigned long);
    
    // Handle even number of iterations by adjusting limit
    size_t adjusted_limit = (limit / step) * step;

    for (i = 0; i < adjusted_limit; i += step) {
        // Combine operations on two consecutive in_use_p entries
        unsigned long combined_diff = 0;
        
        p->in_use_p[i] |= p->save_in_use_p[i];
        unsigned long j1 = p->in_use_p[i];
        while (j1) {
            combined_diff += (j1 & 1);
            j1 >>= 1;
        }

        if (i + 1 < limit) {
            p->in_use_p[i + 1] |= p->save_in_use_p[i + 1];
            unsigned long j2 = p->in_use_p[i + 1];
            while (j2) {
                combined_diff += (j2 & 1);
                j2 >>= 1;
            }
        }

        p->num_free_objects -= combined_diff;
    }

    // Handle remaining element if limit is not divisible by step
    if (adjusted_limit < limit) {
        i = adjusted_limit;
        p->in_use_p[i] |= p->save_in_use_p[i];
        unsigned long j = p->in_use_p[i];
        while (j) {
            p->num_free_objects -= (j & 1);
            j >>= 1;
        }
    }
}
