#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *item_str;
int *nb_items;
char *p;

static char item_str_buffer[131072]; // 128KB buffer
static int nb_items_storage;

void init_vars() {
    size_t i;
    
    // Initialize the string buffer with spaces and a pipe at the end
    for (i = 0; i < sizeof(item_str_buffer) - 1; i++) {
        item_str_buffer[i] = ' ';
    }
    item_str_buffer[sizeof(item_str_buffer) - 1] = '|';
    
    // Point item_str to the buffer
    item_str = item_str_buffer;
    
    // Initialize nb_items to point to storage
    nb_items = &nb_items_storage;
    *nb_items = 0;
    
    // Initialize p to NULL to avoid pre-loop access issues
    p = NULL;
}