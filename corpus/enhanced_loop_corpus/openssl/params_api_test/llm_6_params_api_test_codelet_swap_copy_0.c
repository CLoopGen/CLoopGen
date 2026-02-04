#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  void *in;
extern size_t len;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < len; i++) {
        size_t idx = len - i - 1;
        out[i] = ((unsigned char *)in)[idx];
    }
}
