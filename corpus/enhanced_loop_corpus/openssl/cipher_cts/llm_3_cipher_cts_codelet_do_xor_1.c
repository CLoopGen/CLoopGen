#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in1;
extern  unsigned char *in2;
extern size_t len;
extern unsigned char *out;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)__builtin_alloca(len * sizeof(size_t));
    for (i = 0; i < len; ++i)
        indices[i] = len - 1 - i;
    for (i = 0; i < len; ++i) {
        size_t idx = indices[i];
        out[idx] = in1[idx] ^ in2[idx];
    }
}
