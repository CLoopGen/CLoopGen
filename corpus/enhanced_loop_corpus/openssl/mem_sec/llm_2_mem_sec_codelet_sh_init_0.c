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
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t idx = 0;
    for (i = sh.bittable_size; i; i >>= 1)
        sh.freelist[idx++] = &sh.arena[sh.freelist_size++];
}
