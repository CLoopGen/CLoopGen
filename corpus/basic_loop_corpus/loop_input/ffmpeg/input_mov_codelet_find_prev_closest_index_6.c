#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct MOVStts {
    unsigned int count;
    int duration;
} MOVStts;

MOVStts *ctts_data;
int64_t ctts_count;
int64_t *_usr_index;
int64_t *ctts_index;
int64_t *ctts_sample;
int64_t index_ctts_count;

#define index _usr_index

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data (~1M elements)

    ctts_count = data_size;
    ctts_data = (MOVStts*)calloc(data_size, sizeof(MOVStts));
    for (size_t i = 0; i < data_size; i++) {
        ctts_data[i].count = 1 + (i % 10); // Ensure non-zero count
        ctts_data[i].duration = 100 + (i % 50);
    }

    _usr_index = (int64_t*)malloc(sizeof(int64_t));
    *index = data_size; // Set loop bound within valid range

    ctts_index = (int64_t*)malloc(sizeof(int64_t));
    *ctts_index = 0;

    ctts_sample = (int64_t*)malloc(sizeof(int64_t));
    *ctts_sample = 0;
}