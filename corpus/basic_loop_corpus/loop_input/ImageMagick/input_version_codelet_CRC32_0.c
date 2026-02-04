#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned char *message;
size_t length;
ssize_t i;
unsigned int crc_xor[256];
unsigned int crc;

void init_vars() {
    const size_t data_size = 67108864; // 64 MB, tuned for ~0.01 sec on modern CPUs with optimization

    message = (unsigned char *)aligned_alloc(32, data_size);
    if (!message) {
        exit(1);
    }
    length = data_size;

    for (size_t idx = 0; idx < data_size; idx++) {
        message[idx] = (unsigned char)(idx ^ (idx >> 8));
    }

    for (int j = 0; j < 256; j++) {
        unsigned int c = j;
        for (int k = 0; k < 8; k++) {
            if (c & 1)
                c = 0xEDB88320U ^ (c >> 1);
            else
                c = c >> 1;
        }
        crc_xor[j] = c;
    }

    crc = 0xFFFFFFFFU;
    i = 0;
}