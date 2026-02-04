#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
int t;
int _usr_index;
real_t value;
real_t chksum;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i * 2); 
    }
    t = 15999; 
    _usr_index = -1;
    value = 0.0f;
    chksum = 0.0f;
}