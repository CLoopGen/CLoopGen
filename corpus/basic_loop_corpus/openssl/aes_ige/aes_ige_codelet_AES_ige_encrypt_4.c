#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long data[2];
} aes_block_t __attribute__((aligned(1)));

extern size_t n;
extern aes_block_t *iv2p;
extern aes_block_t tmp;
extern aes_block_t *inp;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (n = 0; n < (16 / sizeof(unsigned long)); ++n)
    tmp.data[n] = inp->data[n] ^ iv2p->data[n];

}
