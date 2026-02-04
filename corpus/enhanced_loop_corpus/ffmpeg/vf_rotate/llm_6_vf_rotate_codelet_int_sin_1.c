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
int64_t temp_res = res;
int64_t temp_a = a;
for (i = 2; i < 11; i += 2) {
    int64_t prev_a = temp_a;
    temp_a = -temp_a * a2 / ((1 << 20) * i * (i + 1));
    temp_res += prev_a;
}
res = temp_res;
a = temp_a;
}
