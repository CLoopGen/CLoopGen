#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t_aX in_val, ivec_val, result;
    for (; n < 16; n += sizeof(size_t)) {
        in_val = *(size_t_aX *)(in + n);
        ivec_val = *(size_t_aX *)(ivec + n);
        result = ivec_val ^ in_val;
        *(size_t_aX *)(out + n) = result;
        // Break WAW and WAR dependency by delaying ivec update
        if (n + sizeof(size_t) >= 16) {
            *(size_t_aX *)(ivec + n) = result;
        }
    }
    // Finalize ivec update outside the main data flow to eliminate loop-carried dependency
    for (; n >= 16 && (n - sizeof(size_t)) < 16; ) {
        n -= sizeof(size_t);
        *(size_t_aX *)(ivec + n) = *(size_t_aX *)(out + n);
        break;
    }
}
