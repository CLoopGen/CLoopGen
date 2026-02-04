#include <stdint.h>
#include <stdlib.h>

char *row[6];
char **irow;
int i;

void init_vars() {
    // Allocate 6 char pointers for row, each pointing to a 256KB block to ensure sufficient data size
    const size_t block_size = 262144; // 256 * 1024 = 262144 bytes
    for (int idx = 0; idx < 6; idx++) {
        row[idx] = (char *)calloc(block_size, sizeof(char));
    }

    // Allocate irow as an array of 6 char pointers
    irow = (char **)calloc(6, sizeof(char *));
}