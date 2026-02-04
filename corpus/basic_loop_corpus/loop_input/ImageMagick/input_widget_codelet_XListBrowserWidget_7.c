#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char **list;
unsigned int entries;

static char *data_block;
static size_t data_size = 1 << 20; // 1MB of data

void init_vars() {
    data_block = (char *)calloc(data_size, sizeof(char));
    if (!data_block) exit(1);

    size_t num_entries = (data_size / sizeof(char *)) - 1;
    list = (char **)calloc(num_entries + 1, sizeof(char *));
    if (!list) exit(1);

    for (size_t i = 0; i < num_entries; i++) {
        list[i] = &data_block[i * sizeof(char *)];
    }
    list[num_entries] = (char *)((void *)0);
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}