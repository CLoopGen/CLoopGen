#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i += 2) {
    volatile int64_t a = i * i * i;
    volatile int64_t b = a + (i << 3);
    volatile int64_t c = b % 17;
}
}
