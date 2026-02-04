#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *item_str;
int *nb_items;
char *p;

static char data_buffer[1 << 24]; // 16 MB buffer

void init_vars() {
    // Initialize nb_items to point to an integer in static storage
    static int counter = 0;
    nb_items = &counter;

    // Fill the buffer with mostly alphanumeric characters and some '|' delimiters
    size_t len = sizeof(data_buffer) - 1; // Leave space for null terminator
    for (size_t i = 0; i < len; ++i) {
        if (rand() % 32 == 0)
            data_buffer[i] = '|';
        else
            data_buffer[i] = 'a' + (rand() % 26);
    }
    data_buffer[len] = '\0';

    // Assign item_str to point to the buffer
    item_str = data_buffer;
}