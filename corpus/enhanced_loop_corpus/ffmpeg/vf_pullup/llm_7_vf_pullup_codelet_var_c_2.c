#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern ptrdiff_t s;
extern int i;
extern int j;
extern int var;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        int local_var = var;
        for (j = 0; j < 8; j += 2) {
            int diff1 = a[j] - a[j + s];
            int diff2 = (j + 1 < 8) ? (a[j + 1] - a[j + 1 + s]) : 0;
            local_var += ((diff1 ^ (diff1 >> 31)) - (diff1 >> 31));
            if (j + 1 < 8)
                local_var += ((diff2 ^ (diff2 >> 31)) - (diff2 >> 31));
        }
        var = local_var;
        a += s;
    }
}
