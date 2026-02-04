#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *item_str;
int *nb_items;
char *p;

static char data_buffer[1 << 24]; // 16 MB buffer

void init_vars() {
    // Initialize nb_items to point to a valid int
    static int counter = 0;
    nb_items = &counter;

    // Initialize item_str to point to the data buffer
    item_str = data_buffer;

    // Fill the buffer with sample data: mix of spaces, pipes, and other characters
    size_t len = sizeof(data_buffer) - 1; // Leave space for null terminator
    for (size_t i = 0; i < len; ++i) {
        int r = rand() % 100;
        if (r < 5) {
            data_buffer[i] = ' ';
        } else if (r < 10) {
            data_buffer[i] = '|';
        } else {
            data_buffer[i] = 'a' + (r % 26);
        }
    }
    data_buffer[len] = '\0'; // Null terminate

    // Initialize p to NULL (will be set in loop)
    p = NULL;
}