#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  unsigned char *in;
extern size_t size;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        if (i % 2 == 0)
            *out-- = *in++;
        else
            in++, out--;
    }
}
