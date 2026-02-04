#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

page_entry *p;
unsigned int i;
size_t num_objects;

static unsigned long *allocated_save_in_use_p;
static size_t allocated_size;

void init_vars() {
    // Choose num_objects to target ~0.01 seconds runtime
    // The inner loop runs over bits in p->in_use_p[i], and the outer loop iterates over array elements.
    // Each element is unsigned long, so 64 bits on typical systems.
    // To get reasonable performance, set num_objects such that total bits is around 1M-10M.

    num_objects = 1 << 20;  // 1 million objects

    // Compute number of unsigned longs needed: ceil(num_objects / (8 * sizeof(long)))
    size_t num_longs = (((num_objects) + (8 * sizeof(long)) - 1) / (8 * sizeof(long)));

    // Total allocation size for flexible array in page_entry
    allocated_size = sizeof(page_entry) + (num_longs - 1) * sizeof(unsigned long);

    p = (page_entry*)calloc(1, allocated_size);
    if (!p) exit(1);

    allocated_save_in_use_p = (unsigned long*)calloc(num_longs, sizeof(unsigned long));
    if (!allocated_save_in_use_p) exit(1);

    // Initialize p fields
    p->next = NULL;
    p->bytes = 0;
    p->page = NULL;
    p->group = NULL;
    p->save_in_use_p = allocated_save_in_use_p;
    p->context_depth = 0;
    p->num_free_objects = (unsigned short)num_objects; // will be reduced in loop
    p->next_bit_hint = 0;
    p->order = 0;

    // Initialize in_use_p and save_in_use_p with random bit patterns to ensure non-trivial computation
    for (size_t idx = 0; idx < num_longs; ++idx) {
        p->in_use_p[idx] = 0;
        p->save_in_use_p[idx] = rand() % 256; // Sparse bits for realistic workload
    }

    i = 0; // Loop index initialized to 0
}