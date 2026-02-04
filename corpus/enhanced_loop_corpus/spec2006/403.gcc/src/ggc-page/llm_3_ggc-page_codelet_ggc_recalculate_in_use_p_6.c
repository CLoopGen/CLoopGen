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
    // Variant 2: Strided memory access with reverse traversal and stride of 4
    unsigned int step = 4;
    unsigned int limit = (((((num_objects) + (8 * 8) - 1) / (8 * 8)) * sizeof(long)) + sizeof(*p->in_use_p) - 1) / sizeof(*p->in_use_p);
    
    // Align starting index to the largest multiple of step less than limit
    i = ((limit + step - 1) / step) * step;
    for (; i > 0; i -= step) {
        // Access indices in reverse order with fixed stride
        for (unsigned int offset = 0; offset < step && (i - offset - 1) < limit; ++offset) {
            unsigned int idx = i - offset - 1;
            unsigned long j = p->in_use_p[idx];
            p->in_use_p[idx] |= p->save_in_use_p[idx];
            j = p->in_use_p[idx]; // Re-read after modification
            for (; j; j >>= 1)
                p->num_free_objects -= (j & 1);
        }
    }
}
