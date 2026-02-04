#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int p;
extern int64_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < p * 3; i++) {
        v *= a + (i % 5);
        v >>= 15;
        if ((i & 7) == 0) {
            v += (a >> 4);
        }
    }
}
