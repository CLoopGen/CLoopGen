#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *big;
char *little;
char *s;
char *x;
char *littleend;

static char *big_storage;
static char *little_storage;

void init_vars() {
    size_t big_size = 128 << 20; // 128 MB
    size_t little_size = 64 << 10; // 64 KB

    big_storage = (char*)malloc(big_size);
    little_storage = (char*)malloc(little_size);

    if (!big_storage || !little_storage) {
        exit(1);
    }

    memset(big_storage, 'a', big_size);
    memset(little_storage, 'a', little_size);

    big = big_storage;
    little = little_storage;
    s = little;
    x = big;
    littleend = little + little_size;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}

__attribute__((destructor))
static void destructor() {
    free(big_storage);
    free(little_storage);
}