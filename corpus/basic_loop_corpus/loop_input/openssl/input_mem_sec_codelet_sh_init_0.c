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
size_t i;

void init_vars() {
    // Allocate bittable with size ~512KB to ensure loop runs for sufficient iterations
    sh.bittable_size = 524288;  // 512KB
    sh.bittable = (unsigned char *)calloc(sh.bittable_size, sizeof(unsigned char));
    if (!sh.bittable) {
        exit(1);
    }

    // Initialize other fields to valid states
    sh.map_result = NULL;
    sh.map_size = 0;
    sh.arena = NULL;
    sh.arena_size = 0;
    sh.freelist = NULL;
    sh.freelist_size = 0;
    sh.minsize = 8;
    sh.bitmalloc = NULL;

    // Ensure freelist is a valid pointer even if not used in loop
    sh.freelist = (char **)calloc(1024, sizeof(char *));
    if (!sh.freelist) {
        free(sh.bittable);
        exit(1);
    }
}

// Definition of loop function from external source
extern void loop();