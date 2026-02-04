#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t c;
extern uint64_t a0;
extern uint64_t a1;
extern uint64_t t1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint64_t local_a1 = a1;
uint64_t local_t1 = t1;
int64_t local_c = c;
for (i = 63; i >= 0; i--) {
    uint64_t bit = (a0 >> i) & 1;
    local_a1 = local_a1 + local_a1 + bit;
    local_t1 = local_t1 + local_t1;
    if (local_c <= local_a1) {
        local_a1 -= local_c;
        local_t1 += 1;
    }
}
a1 = local_a1;
t1 = local_t1;
c = local_c;
}
