#include <stdio.h>

#include <inttypes.h>

typedef struct info_st {
    uint64_t seq_num;
    uint64_t sub_seq;
    size_t idx;
} INFO;

extern size_t i;
extern INFO infos[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        infos[i * 4 + 0].sub_seq = i * 4 + 0;
        infos[i * 4 + 1].sub_seq = i * 4 + 1;
        infos[i * 4 + 2].sub_seq = i * 4 + 2;
        infos[i * 4 + 3].sub_seq = i * 4 + 3;
    }
}
