#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  void *in;
extern size_t len;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < len; j++)
    out[j] = ((unsigned char *)in)[len - j - 1];

}
