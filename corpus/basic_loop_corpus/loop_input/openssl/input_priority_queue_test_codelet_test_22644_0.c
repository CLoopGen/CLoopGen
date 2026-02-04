#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct info_st {
    uint64_t seq_num;
    uint64_t sub_seq;
    size_t idx;
} INFO;

size_t i;
INFO infos[32];

void init_vars() {
    for (size_t j = 0; j < 32; ++j) {
        infos[j].seq_num = j * 2;
        infos[j].sub_seq = 0;
        infos[j].idx = j;
    }
}