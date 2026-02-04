#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  void *in;
extern size_t len;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_j = 0;
    while (temp_j < len) {
        out[temp_j] = ((unsigned char *)in)[len - temp_j - 1];
        temp_j++;
    }
}
