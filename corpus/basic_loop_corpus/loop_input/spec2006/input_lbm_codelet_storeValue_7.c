#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char buffer[4];
int i;

static char *vPtr_storage;
char *vPtr;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    vPtr_storage = (char *)malloc(data_size);
    if (!vPtr_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    vPtr = vPtr_storage;

    // Initialize vPtr with some data (e.g., ascending byte values)
    for (size_t j = 0; j < data_size; j++) {
        vPtr[j] = (char)(j & 0xFF);
    }

    // Ensure i is initialized to a safe value before loop use
    i = 0;

    // Initialize buffer to prevent undefined behavior
    memset(buffer, 0, sizeof(buffer));
}