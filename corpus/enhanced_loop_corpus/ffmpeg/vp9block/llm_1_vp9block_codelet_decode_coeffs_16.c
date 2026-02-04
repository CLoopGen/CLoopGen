#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer;
for (outer = 1; outer < end_x; outer += 8) {
    for (n = outer; n < outer + 4 && n < end_x; n++) {
        a[n] = a[n - 1];
    }
}
}
