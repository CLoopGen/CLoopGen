#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32000; i++) {
        e[i] = 5 + i;
        d[i] = e[i] - 1;       // WAR dependency introduced: d[i] depends on e[i] just written
        c[i] = d[i] - 1;       // WAR chain continues
        b[i] = c[i] - 1;
        a[i] = b[i] - 1;
        
        // Loop-carried dependence: each iteration must complete before next starts due to reuse of values
        // Although no direct scalar reuse, the pattern enforces sequential execution
    }
}
