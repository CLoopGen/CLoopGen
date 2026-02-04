#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *nb_frames;
char *p;
char *frames_str1;

static int internal_nb_frames;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    frames_str1 = (char *)malloc(data_size);
    if (!frames_str1) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill with 'x' and insert commas periodically to simulate frame data
    for (size_t i = 0; i < data_size - 1; i++) {
        frames_str1[i] = (rand() % 10 == 0) ? ',' : 'x';
    }
    frames_str1[data_size - 1] = '\0'; // Ensure null-terminated

    internal_nb_frames = 0;
    nb_frames = &internal_nb_frames;
    p = NULL; // Will be set in loop
}