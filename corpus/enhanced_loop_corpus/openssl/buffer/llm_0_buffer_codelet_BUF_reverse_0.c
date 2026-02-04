#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  unsigned char *in;
extern size_t size;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < 1; j++) {
            *out-- = *in++;
        }
    }
}
