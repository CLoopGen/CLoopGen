#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

Hash_data *target;
int i;

void init_vars() {
    const int num_elements = 64 / (8 * sizeof(long));
    const size_t data_size = 1 << 20; // 1MB of data
    const int total_structs = data_size / sizeof(Hash_data);

    Hash_data *ptr = (Hash_data*)calloc(total_structs, sizeof(Hash_data));
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    target = &ptr[0];

    for (int idx = 0; idx < num_elements && idx < total_structs; idx++) {
        target->hashval[idx] = 0;
    }
}