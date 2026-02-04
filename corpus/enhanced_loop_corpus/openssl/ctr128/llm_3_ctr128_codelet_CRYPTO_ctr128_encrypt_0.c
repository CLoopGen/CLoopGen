#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ecount_buf[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access – process array from high to low address
    // Maintains same logic but reverses iteration order
    for (n = 16 - sizeof(size_t); ; n -= sizeof(size_t)) {
        *(size_t_aX *)(out + n) = *(size_t_aX *)(in + n) ^ *(size_t_aX *)(ecount_buf + n);
        if (n == 0) break;
    }
}
