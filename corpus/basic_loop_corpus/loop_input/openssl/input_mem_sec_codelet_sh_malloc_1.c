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
size_t size;
ssize_t list;
size_t i;

void init_vars() {
    // Allocate arena of 512KB to ensure loop runs long enough (~0.01 sec target)
    const size_t arena_sz = 512 * 1024;
    sh.arena = (char*)calloc(arena_sz, sizeof(char));
    sh.arena_size = arena_sz;

    // Set minsize to a small power of two, e.g., 32 bytes
    sh.minsize = 32;

    // Set size to half the arena size to allow several doublings in loop
    size = arena_sz / 2;

    // Initialize list to a reasonable value to avoid underflow; use positive value
    list = 100;

    // Allocate and initialize other pointers to valid memory
    sh.map_result = (char*)calloc(1, 64);
    sh.map_size = 64;

    sh.freelist_size = 10;
    sh.freelist = (char**)calloc(sh.freelist_size, sizeof(char*));
    for (int j = 0; j < sh.freelist_size; j++) {
        sh.freelist[j] = (char*)calloc(1, 16);
    }

    sh.bittable_size = 1024;
    sh.bittable = (unsigned char*)calloc(sh.bittable_size, sizeof(unsigned char));
    sh.bitmalloc = (unsigned char*)calloc(sh.bittable_size, sizeof(unsigned char));
}