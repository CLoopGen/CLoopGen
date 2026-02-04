#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVIndexEntry {
    int64_t pos;
    int64_t timestamp;
    int flags : 2;
    int size : 30;
    int min_distance;
} AVIndexEntry;

AVIndexEntry *e_old;
int flag;
int64_t *_usr_index;
int64_t i;

#define index _usr_index

void init_vars() {
    const size_t data_size = 1 << 20; // 1M entries, ~40 MB of data (each entry is ~40 bytes)
    
    e_old = aligned_alloc(64, sizeof(AVIndexEntry) * (data_size + 1));
    if (!e_old) abort();

    for (size_t j = 0; j <= data_size; j++) {
        e_old[j].timestamp = (j < data_size - 100) ? 1000 : (int64_t)(data_size - j);
        e_old[j].pos = j * 1000;
        e_old[j].flags = (j % 3 == 0) ? 1 : 0;
        e_old[j].size = 1000;
        e_old[j].min_distance = 100;
    }

    flag = 4; 

    _usr_index = malloc(sizeof(int64_t));
    if (!_usr_index) abort();
    *_usr_index = data_size - 1;
}