#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  void *in;
extern size_t len;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        size_t i;
        for (i = 0; i < len; i += 2) {
            out[i] = ((unsigned char *)in)[len - i - 1];
            if (i + 1 < len) {
                out[i + 1] = ((unsigned char *)in)[len - (i + 1) - 1];
            }
        }
    }
}
