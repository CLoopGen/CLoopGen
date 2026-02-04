#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

Hashvalue (*black_hash)[1] = NULL;
Hash_data *hd = NULL;
int pos = 0;
int k = 0;

void init_vars() {
    const int num_entries = 400;
    const int hash_size_per_entry = 1;
    const int total_elements = num_entries * hash_size_per_entry;

    black_hash = (Hashvalue(*)[1])calloc(total_elements, sizeof(Hashvalue));
    if (!black_hash) {
        fprintf(stderr, "Failed to allocate black_hash\n");
        exit(1);
    }

    hd = (Hash_data*)malloc(sizeof(Hash_data));
    if (!hd) {
        fprintf(stderr, "Failed to allocate hd\n");
        exit(1);
    }

    size_t hd_array_size = 64 / (8 * sizeof(long));
    Hashvalue* extended_hashval = (Hashvalue*)calloc(hd_array_size, sizeof(Hashvalue));
    if (!extended_hashval) {
        fprintf(stderr, "Failed to allocate hd->hashval extension\n");
        free(hd);
        exit(1);
    }

    memcpy(hd, &extended_hashval, sizeof(Hash_data));
    
    pos = 0;

    for (int i = 0; i < total_elements; i++) {
        black_hash[i][0] = (Hashvalue)(i * 31 + 17);
    }

    for (size_t i = 0; i < hd_array_size; i++) {
        extended_hashval[i] = (Hashvalue)(i + 1);
    }
}