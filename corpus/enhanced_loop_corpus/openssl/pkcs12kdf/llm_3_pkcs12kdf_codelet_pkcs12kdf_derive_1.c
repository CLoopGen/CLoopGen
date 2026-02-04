#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *salt;
extern size_t saltlen;
extern unsigned char *p;
extern size_t Slen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)__builtin_alloca(Slen * sizeof(size_t));
    for (size_t idx = 0; idx < Slen; idx++)
        indices[idx] = (idx * 7) % Slen;  // Stride via indirect indexing

    for (size_t j = 0; j < Slen; j++) {
        size_t pos = indices[j] % saltlen;
        *p++ = salt[pos];
    }
}
