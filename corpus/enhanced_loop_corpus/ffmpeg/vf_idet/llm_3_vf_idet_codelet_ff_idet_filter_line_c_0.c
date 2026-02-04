#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern  uint8_t *b;
extern  uint8_t *c;
extern int w;
extern int x;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive array access using pointer arithmetic in a blocked fashion (unrolled by 2)
    uint8_t *aa = a, *bb = b, *cc = c;
    int limit = w - (w % 2);
    for (x = 0; x < limit; x += 2) {
        int v1 = (*aa++ + *cc++) - 2 * *bb++;
        int v2 = (*aa++ + *cc++) - 2 * *bb++;
        ret += ((v1) >= 0 ? (v1) : (-(v1)));
        ret += ((v2) >= 0 ? (v2) : (-(v2)));
    }
    // Handle remaining element if w is odd
    if (x < w) {
        int v = (*aa + *cc) - 2 * *bb;
        ret += ((v) >= 0 ? (v) : (-(v)));
    }
}
