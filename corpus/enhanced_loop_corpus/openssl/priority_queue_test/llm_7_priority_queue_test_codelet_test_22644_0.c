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
    uint64_t temp_sub_seq[32];
    for (i = 0; i < 32; ++i)
        temp_sub_seq[i] = i;
    for (i = 0; i < 32; ++i)
        infos[i].sub_seq = temp_sub_seq[i];
}
