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
    unsigned int temp_num_free = p->num_free_objects;
    for (i = 0; i < ((((((((num_objects)) + ((8 * 8)) - 1) / ((8 * 8))) * sizeof(long))) + (sizeof (*p->in_use_p)) - 1) / (sizeof (*p->in_use_p))); ++i) {
        unsigned long j;
        unsigned long temp_in_use = p->save_in_use_p[i];
        p->in_use_p[i] |= temp_in_use;
        for (j = temp_in_use; j; j >>= 1)
            temp_num_free -= (j & 1);
    }
    p->num_free_objects = temp_num_free;
}
