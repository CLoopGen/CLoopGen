#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

SH sh;
ssize_t list;
ssize_t slist;

void init_vars() {
    const size_t data_size = 1024 * 128; // 128KB

    sh.arena_size = data_size;
    sh.arena = calloc(1, sh.arena_size);

    sh.minsize = 16;
    sh.map_size = 4096;
    sh.map_result = calloc(1, sh.map_size);

    sh.bittable_size = data_size / 8;
    sh.bittable = calloc(1, sh.bittable_size);
    sh.bitmalloc = calloc(1, sh.bittable_size);

    sh.freelist_size = (data_size / 64) + 1;
    sh.freelist = malloc(sizeof(char*) * sh.freelist_size);

    // Initialize freelist with valid pointers in the arena
    for (ssize_t i = 0; i < sh.freelist_size - 1; i++) {
        size_t offset = i * 64;
        if (offset + 32 < sh.arena_size) {
            sh.freelist[i] = &sh.arena[offset];
        } else {
            sh.freelist[i] = NULL;
        }
    }
    // Set last element to non-NULL to ensure loop terminates properly
    sh.freelist[sh.freelist_size - 1] = &sh.arena[sh.arena_size / 2];

    list = sh.freelist_size - 1;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}