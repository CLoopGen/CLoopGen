#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int i = 0; i < 16; i += sizeof(size_t)) {
        for (unsigned int j = 0; j < sizeof(size_t); ++j) {
            if (n + i + j < 16) {
                out[n + i + j] = in[n + i + j] ^ ivec[n + i + j];
            }
        }
    }
}
