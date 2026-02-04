#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *pn_bytes;
unsigned char mask[5] = {0x01, 0x02, 0x03, 0x04, 0x05};
unsigned char pn_len;
unsigned char i;

void init_vars() {
    const size_t data_size = 512 * 1024; // 512 KB for ~0.01 sec runtime estimate

    pn_len = 4; // Ensures mask[i + 1] accesses mask[1..4], valid for i in [0,3]

    pn_bytes = (unsigned char *)malloc(data_size);
    if (!pn_bytes) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    memset(pn_bytes, 0xAA, data_size); // Initialize with non-zero pattern
}