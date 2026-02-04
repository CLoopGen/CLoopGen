#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int n;
extern int order;
extern int i;
extern int a;
extern int c;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n <= order) return;
int local_a = a;
int local_c = c;
int local_e = e;

for (i = order; i < n - 3; i += 1) {
    int b = smp[i] - smp[i - 1];
    int d = b - local_a;
    int f = d - local_c;
    res[i] = f - local_e;

    local_a = smp[i + 1] - smp[i];
    local_c = local_a - b;
    local_e = local_c - d;

    res[i + 1] = local_e - f;
}
a = local_a;
c = local_c;
e = local_e;
}
