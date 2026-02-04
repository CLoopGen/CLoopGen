#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *b;
extern size_t blen;
extern unsigned int pad;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    pad = 0;
    for (i = 1; i < blen; i++) {
        unsigned char temp = b[i];
        for (size_t j = 0; j < 1; j++) { // Artificially increased nesting depth
            pad |= temp;
        }
    }
}
