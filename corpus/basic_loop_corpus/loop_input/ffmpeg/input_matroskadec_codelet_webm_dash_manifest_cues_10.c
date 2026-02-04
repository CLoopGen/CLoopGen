#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct EbmlList {
    int nb_elem;
    unsigned int alloc_elem_size;
    void *elem;
} EbmlList;

typedef struct MatroskaSeekhead {
    uint64_t id;
    uint64_t pos;
} MatkoshaSeekhead;

EbmlList *seekhead_list;
MatkoshaSeekhead *seekhead;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of input data: 131072 elements (each 8 bytes)

    seekhead = calloc(data_size / sizeof(MatkoshaSeekhead), sizeof(MatkoshaSeekhead));
    if (!seekhead) exit(1);

    for (size_t idx = 0; idx < data_size / sizeof(MatkoshaSeekhead); idx++) {
        seekhead[idx].id = (idx == data_size / sizeof(MatkoshaSeekhead) - 1) ? 475249515 : (uint64_t)(rand() % 1000000000);
        seekhead[idx].pos = idx * 1000;
    }

    seekhead_list = malloc(sizeof(EbmlList));
    if (!seekhead_list) exit(1);

    seekhead_list->nb_elem = data_size / sizeof(MatkoshaSeekhead);
    seekhead_list->alloc_elem_size = sizeof(MatkoshaSeekhead);
    seekhead_list->elem = seekhead;
}