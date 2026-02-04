#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 1; i < end_y; i++) {
    for (n = i; n < end_y && (n - i) < 8; n += 1) {
        l[n] = l[n - 1];
    }
    i += 7;
}
}
