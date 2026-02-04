#include <inttypes.h>
#include <stdlib.h>

extern int16_t *_usr_index;
extern int k;

#define index _usr_index

static int16_t *index_data;
static int16_t **index_ptr;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB
    index_data = (int16_t *)calloc(data_size, sizeof(int16_t));
    if (!index_data) exit(1);

    for (size_t i = 0; i < data_size; i++) {
        index_data[i] = rand() % 256 - 128; 
    }

    index_ptr = &_usr_index;
    *index_ptr = index_data;
    k = 0;
}

int16_t *_usr_index = NULL;
int k = 0;

__attribute__((constructor))
static void constructor() {
    init_vars();
}