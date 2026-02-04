#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *file;
size_t i;
size_t length;
size_t newline_count;

static char *generated_file_data = NULL;

void init_vars() {
    length = 512 * 1024; // 512 KB of data for ~0.01 sec runtime on modern CPU
    generated_file_data = (char*)malloc(length);
    if (!generated_file_data) {
        length = 0;
        file = NULL;
        return;
    }

    // Initialize with random printable characters and occasional newlines
    for (size_t idx = 0; idx < length; ++idx) {
        if (rand() % 64 == 0) {
            generated_file_data[idx] = '\n';
        } else {
            generated_file_data[idx] = ' ' + (rand() % 95); // Printable ASCII
        }
    }

    file = generated_file_data;
    i = 0;
    newline_count = 0;
}