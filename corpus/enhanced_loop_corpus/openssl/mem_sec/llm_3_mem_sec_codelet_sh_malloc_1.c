#include <stdio.h>

#include <inttypes.h>

typedef struct sh_st {
    char *map_result;
    size_t map_size;
    char *arena;
    size_t arena_size;
    char **freelist;
    ssize_t freelist_size;
    size_t minsize;
    unsigned char *bittable;
    unsigned char *bitmalloc;
    size_t bittable_size;
} SH;

extern SH sh;
extern size_t size;
extern ssize_t list;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive indirect memory access via pointer chasing in freelist
    // Simulate consecutive traversal by treating freelist as a buffer accessed consecutively
    char **ptr = sh.freelist;
    size_t count = (size < (size_t)list) ? size : (size_t)list;
    for (i = sh.minsize; i < count; i <<= 1) {
        if (ptr[i] != NULL) {
            ptr[i] += 1;  // dummy write to simulate use
            list--;
        }
    }
}
