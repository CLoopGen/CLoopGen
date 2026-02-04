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
    tmp.data[0] = inp->data[0] ^ iv2p->data[0];
    if ((16 / sizeof(unsigned long)) > 1)
        tmp.data[1] = inp->data[1] ^ iv2p->data[1];
}
