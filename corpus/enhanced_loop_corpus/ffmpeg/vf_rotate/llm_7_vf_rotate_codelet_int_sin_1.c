#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int64_t a2;
extern int64_t res;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int64_t local_a = a;
int64_t local_res = res;
for (i = 2; i < 11; i += 2) {
    int64_t factor = (1 << 20) * i * (i + 1);
    if (factor != 0) {
        local_a = -local_a * a2 / factor;
    }
    local_res += local_a;
}
res = local_res;
a = local_a;
}
