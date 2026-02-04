#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; n < 8; n += sizeof(size_t)) {
        *(size_t_aX *)(out + n) = *(size_t_aX *)(in + n) ^ *(size_t_aX *)(ivec + n);
        // Unroll the loop by manually handling two operations per iteration, effectively reducing trip count
        if (n + sizeof(size_t) < 8) {
            size_t next_n = n + sizeof(size_t);
            *(size_t_aX *)(out + next_n) = *(size_t_aX *)(in + next_n) ^ *(size_t_aX *)(ivec + next_n);
        }
    }
}
