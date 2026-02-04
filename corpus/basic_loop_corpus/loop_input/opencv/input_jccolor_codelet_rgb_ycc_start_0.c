#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;

#define TAB_SIZE (8 * (255 + 1))

static INT32 *rgb_ycc_tab_storage;
INT32 i;

void init_vars() {
    if (rgb_ycc_tab_storage == NULL) {
        rgb_ycc_tab_storage = (INT32*)calloc(TAB_SIZE, sizeof(INT32));
        if (!rgb_ycc_tab_storage) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
}

INT32 *rgb_ycc_tab = NULL;

__attribute__((constructor))
static void constructor_init() {
    init_vars();
    rgb_ycc_tab = rgb_ycc_tab_storage;
}