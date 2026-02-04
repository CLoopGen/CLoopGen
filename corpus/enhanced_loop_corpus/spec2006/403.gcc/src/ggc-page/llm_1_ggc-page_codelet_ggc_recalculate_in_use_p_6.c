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
    for (i = 0; i < ((((((((num_objects)) + ((8 * 8)) - 1) / ((8 * 8))) * sizeof(long))) + (sizeof (*p->in_use_p)) - 1) / (sizeof (*p->in_use_p))); ++i) {
        unsigned long j;
        p->in_use_p[i] |= p->save_in_use_p[i];
        unsigned long temp = p->in_use_p[i];
        for (j = 0; j < sizeof(unsigned long) * 8; ++j) {
            p->num_free_objects -= (temp >> j) & 1;
            if (((temp >> j) == 0) && (j > 0)) break;
        }
    }
}
