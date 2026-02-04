#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 << 20) // 128 MB

char *PL_bufend;
char *t;
char win32_open;

static char *buffer = NULL;

void init_vars() {
    if (buffer != NULL) {
        return; // Already initialized
    }

    buffer = (char*)malloc(DATA_SIZE);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with random printable characters
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&buffer));
    for (size_t i = 0; i < DATA_SIZE; i++) {
        buffer[i] = ' ' + (rand() % 95); // Printable ASCII
    }

    // Ensure '\\' appears frequently enough
    for (size_t i = 100; i < DATA_SIZE; i += 1000) {
        buffer[i] = '\\';
    }

    // Place win32_open character near the end to ensure loop terminates
    win32_open = '"';
    size_t open_pos = DATA_SIZE - (rand() % (DATA_SIZE / 4)) - 1;
    buffer[open_pos] = win32_open;

    // Set pointers
    t = buffer;
    PL_bufend = buffer + DATA_SIZE;
}

// Cleanup function to avoid memory leaks (not required but good practice)
void cleanup_vars() {
    if (buffer) {
        free(buffer);
        buffer = NULL;
    }
}