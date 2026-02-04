#include <stdio.h>
#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

size_t n;
aes_block_t tmp;
aes_block_t iv2;

void init_vars() {
    tmp.data[0] = 0xdeadbeefUL;
    tmp.data[1] = 0xcafebabeUL;
    iv2.data[0] = 0x12345678UL;
    iv2.data[1] = 0xabcdef01UL;
}