#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *cp;

static char data[1 << 24]; // 16MB buffer

void init_vars() {
    const char sample[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 0123456789";
    size_t sample_len = strlen(sample);
    size_t total_size = sizeof(data) - 1; // Leave space for null terminator

    // Fill the data with repeating sample text
    for (size_t i = 0; i < total_size; i++) {
        data[i] = sample[i % sample_len];
    }
    data[total_size] = '\0';

    // Initialize cp to point to the beginning of data
    cp = data;
}