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



void loop(){
for (i = 0; i < n && t >= 8; i += 2) {
    size_t local_k1 = pp[i];
    size_t local_s1 = 1;
    size_t local_k2 = (i + 1 < n) ? pp[i + 1] : 0;
    size_t local_s2 = 1;

    for (size_t iter = local_k1; iter > i; iter = pp[iter], local_s1++);
    for (size_t iter = local_k2; iter > i + 1; iter = pp[iter], local_s2++);

    if (local_k1 < i) {
        if (i + 1 < n && local_k2 >= i + 1) {
            t -= local_s2;
            qq[t] = i + 1;
            size_t temp = pp[i + 1];
            for (size_t j = 1; j <= local_s2; j++) {
                qq[t + j] = temp;
                if (j < local_s2) temp = pp[temp];
            }
        }
        continue;
    }

    t -= local_s1;
    qq[t] = i;
    size_t temp = pp[i];
    for (size_t j = 1; j <= local_s1; j++) {
        qq[t + j] = temp;
        if (j < local_s1) temp = pp[temp];
    }

    if (i + 1 < n && local_k2 >= i + 1 && t >= local_s2) {
        t -= local_s2;
        qq[t] = i + 1;
        temp = pp[i + 1];
        for (size_t j = 1; j <= local_s2; j++) {
            qq[t + j] = temp;
            if (j < local_s2) temp = pp[temp];
        }
    }

    if (t < 8) break;
}
}
