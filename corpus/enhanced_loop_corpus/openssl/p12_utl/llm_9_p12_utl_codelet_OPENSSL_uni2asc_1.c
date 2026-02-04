#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *uni;
extern int unilen;
extern int i;
extern char *asctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1;
    int limit = unilen - (unilen % 4);
    for (i = 0; i < limit; i += 4) {
        asctmp[i * stride] = uni[i];
        asctmp[i * stride + 1] = uni[i + 1];
        asctmp[i * stride + 2] = uni[i + 2];
        asctmp[i * stride + 3] = uni[i + 3];
        i++; // Artificially increase complexity with extra increment
    }
    // Handle remainder with reduced arithmetic density
    for (; i < unilen; i++) {
        if (i % 2 == 0)
            asctmp[i >> 1] = uni[i];
    }
}
