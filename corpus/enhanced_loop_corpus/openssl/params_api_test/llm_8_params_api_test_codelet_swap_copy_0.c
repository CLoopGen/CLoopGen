#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  void *in;
extern size_t len;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (j = 0; j < len; j += step) {
        size_t idx1 = len - j - 1;
        out[j] = ((unsigned char *)in)[idx1];
        if (j + 1 < len) {
            size_t idx2 = len - j - 2;
            out[j + 1] = ((unsigned char *)in)[idx2];
        }
    }
}
