#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char start_color[4096];
char *p;

static char data_pool[2097152] __attribute__((aligned(4096)));

void init_vars() {
    size_t i = 0;
    
    // Fill the data pool with a pattern that includes parentheses and hyphens
    while (i < sizeof(data_pool) - 32) {
        if (rand() % 100 < 15) {  // 15% chance to insert a group
            data_pool[i++] = '(';
            int group_len = rand() % 8 + 1;
            for (int j = 0; j < group_len && i < sizeof(data_pool) - 2; j++) {
                data_pool[i++] = 'a' + (rand() % 26);
            }
            if (i < sizeof(data_pool)) {
                data_pool[i++] = ')';
            }
        } else {
            // Regular characters, avoid '-' and '\0' until near end
            data_pool[i++] = 'a' + (rand() % 26);
        }
    }
    
    // Ensure we have a terminating '-' or '\0' within bounds
    if (i < sizeof(data_pool)) {
        data_pool[i++] = '-';
    }
    if (i < sizeof(data_pool)) {
        data_pool[i] = '\0';
    } else {
        data_pool[sizeof(data_pool)-1] = '\0';
    }
    
    // Copy a portion into start_color (simulate cache-hot initial segment)
    size_t copy_size = sizeof(start_color) - 64;
    memcpy(start_color, data_pool, copy_size);
    strcpy(start_color + copy_size, "(example)data-end-marker-");

    // Initialize p to point to start of start_color
    p = start_color;
}