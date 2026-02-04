#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t *buflen;
extern size_t blocksize;
extern size_t i;
extern unsigned char pad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t offset = *buflen;
    size_t len = blocksize - offset;
    for (i = 0; i < len; i++) {
        buf[offset + i] = pad; // Remove loop-carried dependency by using independent index calculation
        // No data dependencies between iterations (fully parallelizable)
    }
    i = *buflen + len; // Maintain original i's final value semantics
}
