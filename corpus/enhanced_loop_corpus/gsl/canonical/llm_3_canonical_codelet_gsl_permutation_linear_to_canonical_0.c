#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern size_t i;
extern size_t k;
extern size_t s;
extern size_t t;
extern  size_t * pp;
extern size_t * qq;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < n; i += 2) {
        if (i >= n) break;
        k = pp[i];
        s = 1;
        size_t current = k;
        for (; current > i; ) {
            current = pp[current];
            s++;
        }
        if (k < i) {
            continue;
        }
        t -= s;
        qq[t] = i;
        current = pp[i];
        s = 1;
        for (size_t pos = t + s; current > i; pos++, s++) {
            qq[pos] = current;
            current = pp[current];
        }
        if (t == 0)
            break;
    }
}
