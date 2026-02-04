#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *msg;
extern size_t msglen;
extern unsigned char re;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[8] = {0, 3, 2, 5, 4, 1, 7, 6};
    size_t num_indices = 8;
    re = 0;
    for (i = 0; i < msglen; i++) {
        size_t idx = indices[(i % num_indices)];
        size_t access_pos = (i / num_indices) * num_indices + idx;
        if (access_pos < msglen) {
            re |= msg[access_pos];
        }
    }
}
