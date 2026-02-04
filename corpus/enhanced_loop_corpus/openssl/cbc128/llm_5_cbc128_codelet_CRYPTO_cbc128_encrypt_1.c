#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16 && in != NULL && out != NULL && iv != NULL; n += sizeof(size_t)) {
        size_t_aX *in_p = (size_t_aX *)(in + n);
        size_t_aX *out_p = (size_t_aX *)(out + n);
        size_t_aX *iv_p = (size_t_aX *)(iv + n);
        if (*in_p | *iv_p) {
            *out_p = *in_p ^ *iv_p;
        } else {
            *out_p = 0;
        }
    }
}
