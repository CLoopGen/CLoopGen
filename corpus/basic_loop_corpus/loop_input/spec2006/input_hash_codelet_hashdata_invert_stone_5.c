#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

Hashvalue white_hash[400][1];

Hash_data *hd;
int pos = 0;
int k = 0;

void init_vars() {
    const size_t data_size = 1 << 20; // Approximately 1MB of input data
    hd = (Hash_data*)malloc(sizeof(Hash_data) + sizeof(Hashvalue) * (data_size / sizeof(Hashvalue) - 1));
    
    for (size_t i = 0; i < data_size / sizeof(Hashvalue); i++) {
        if (i < 64 / (8 * sizeof(long)))
            ((Hashvalue*)hd->hashval)[i] = i * 31 + 1;
        else
            break;
    }

    for (int i = 0; i < 400; i++) {
        white_hash[i][0] = i * 97 + 1;
    }

    pos = rand() % 400;
}