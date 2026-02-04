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
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (size_t stride = 1; stride <= 2; stride *= 2) {
        for (i = 0; i < 32; i += stride) {
            if (i < 32) {
                infos[i].sub_seq = i;
            }
        }
    }
}
