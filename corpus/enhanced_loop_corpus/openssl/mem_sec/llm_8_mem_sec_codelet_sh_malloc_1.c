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
    ssize_t running_count = 0;
    for (i = sh.minsize; i < size; i <<= 1)
        running_count++;
    list -= running_count;
}
