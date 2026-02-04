#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *item_str;
int *nb_items;
char delimiter;
char *p;

static char *internal_item_str_buffer;
static int internal_nb_items_value;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime on modern CPU
    internal_item_str_buffer = (char *)malloc(data_size);
    if (!internal_item_str_buffer) {
        exit(1);
    }

    // Fill buffer with printable characters, occasionally inserting the delimiter
    for (size_t i = 0; i < data_size - 1; i++) {
        if ((rand() % 16) == 0) {
            internal_item_str_buffer[i] = delimiter;
        } else {
            internal_item_str_buffer[i] = 'a' + (i % 26);
        }
    }
    internal_item_str_buffer[data_size - 1] = '\0'; // Ensure null termination

    item_str = internal_item_str_buffer;
    nb_items = &internal_nb_items_value;
    delimiter = ','; // chosen delimiter
    p = NULL; // will be initialized in loop
    internal_nb_items_value = 0;
}