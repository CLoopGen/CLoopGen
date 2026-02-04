#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 10; nl += 2) {
    for (int i = 0; i < 32000; i++) {
        a[i] = b[i];
    }
    for (int i = 0; i < 32000; i++) {
        b[i] = a[i]; // WAW and WAR dependencies introduced between iterations of nl
    }
}
}
