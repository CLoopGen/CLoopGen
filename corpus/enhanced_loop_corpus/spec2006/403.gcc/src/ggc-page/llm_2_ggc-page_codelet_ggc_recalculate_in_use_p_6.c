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
    // Variant 1: Consecutive memory access with unrolled stride of 2
    unsigned int limit = (((((num_objects) + (8 * 8) - 1) / (8 * 8)) * sizeof(long)) + sizeof(*p->in_use_p) - 1) / sizeof(*p->in_use_p);
    for (i = 0; i < limit; i += 2) {
        // Process two elements consecutively to promote spatial locality
        if (i < limit) {
            unsigned long j1 = p->in_use_p[i];
            p->in_use_p[i] |= p->save_in_use_p[i];
            j1 = p->in_use_p[i];
            while (j1) {
                p->num_free_objects -= (j1 & 1);
                j1 >>= 1;
            }
        }
        if (i + 1 < limit) {
            unsigned long j2 = p->in_use_p[i + 1];
            p->in_use_p[i + 1] |= p->save_in_use_p[i + 1];
            j2 = p->in_use_p[i + 1];
            while (j2) {
                p->num_free_objects -= (j2 & 1);
                j2 >>= 1;
            }
        }
    }
}
