#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _TableType {
    ssize_t prefix;
    ssize_t suffix;
    ssize_t next;
} TableType;

ssize_t _usr_index = 0;
TableType *table = NULL;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data: 2^20 bytes
    size_t num_elements = data_size / sizeof(TableType);

    if (num_elements > 256) {
        num_elements = 256;
    }

    table = (TableType*)calloc(num_elements, sizeof(TableType));
    if (!table) {
        fprintf(stderr, "Failed to allocate memory for table\n");
        exit(1);
    }
}