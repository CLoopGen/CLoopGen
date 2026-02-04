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
    for (i = 0; i < n; i++) {
        k = pp[i];
        s = 1;
        size_t temp_k = k;
        for (size_t j = 0; j < n && temp_k > i; j++) {
            temp_k = pp[temp_k];
            s++;
        }
        if (temp_k < i)
            continue;
        t -= s;
        qq[t] = i;
        size_t curr = pp[i];
        for (size_t idx = 1; idx < s && curr > i; idx++) {
            qq[t + idx] = curr;
            curr = pp[curr];
        }
        if (t == 0)
            break;
    }
}
