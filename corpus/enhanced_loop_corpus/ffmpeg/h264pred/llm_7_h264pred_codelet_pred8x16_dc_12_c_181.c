#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern int dc3;
extern int dc4;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        dc0 += src[-1 + i * stride] + src[i - stride];
        dc1 = dc0 + src[4 + i - stride];  // Introduce RAW dependency: dc1 depends on updated dc0
        dc2 = dc1 + src[-1 + (i + 4) * stride];  // Chain dependency: dc2 depends on dc1
        dc3 = dc2 + src[-1 + (i + 8) * stride];  // Further chain: dc3 depends on dc2
        dc4 = dc3 + src[-1 + (i + 12) * stride]; // WAW and RAW: sequential overwrite with dependency
    }
}
