#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;

static JLONG *rgb_y_tab_storage;
JLONG i;

void init_vars() {
    size_t array_size = 256;
    size_t total_size = 3 * array_size;
    rgb_y_tab_storage = (JLONG*)calloc(total_size, sizeof(JLONG));
    if (!rgb_y_tab_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

JLONG *rgb_y_tab = NULL;

__attribute__((constructor))
static void constructor_init() {
    init_vars();
    rgb_y_tab = rgb_y_tab_storage;
}

__attribute__((destructor))
static void destructor_free() {
    if (rgb_y_tab_storage) {
        free(rgb_y_tab_storage);
        rgb_y_tab_storage = NULL;
        rgb_y_tab = NULL;
    }
}