#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  void *in;
extern size_t len;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < len; i += 2) {
        size_t forward_idx = i;
        size_t reverse_idx = len - i - 1;
        out[forward_idx] = ((unsigned char *)in)[reverse_idx];
        if (i + 1 < len) {
            out[i + 1] = ((unsigned char *)in)[len - i - 2];
        }
    }
}
