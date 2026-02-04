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
extern ssize_t list;
extern ssize_t slist;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then adjust to reach exact boundary)
    slist = list;
    for (; slist >= 0; slist -= 2) {
        if (sh.freelist[slist] != ((void *)0))
            break;
    }
    // Handle odd start index if needed
    if ((list % 2 == 1) && (slist + 2 == list) && (slist + 1 >= 0)) {
        if (sh.freelist[slist + 1] != ((void *)0))
            slist = slist + 1;
    }
}
