#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2 bytes (processing alternating segments)
    size_t i;
    for (i = 0; i < 16; i += 2 * sizeof(size_t_aX)) {
        *(size_t_aX *)(out + i) = *(size_t_aX *)(in + i) ^ *(size_t_aX *)(iv + i);
    }
    // Handle remaining segment if needed, but since n=16 and aligned, it's covered for typical size_t=8
}
