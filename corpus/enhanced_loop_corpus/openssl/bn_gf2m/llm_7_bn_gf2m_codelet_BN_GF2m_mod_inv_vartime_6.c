#include <stdio.h>

#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};


typedef struct bignum_st BIGNUM;

extern BIGNUM *u;
extern int i;
extern int top;
extern unsigned long *udp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned long *local_udp = udp;
    int offset = u->top;
    for (i = 0; i < top - offset; i++) {
        local_udp[offset + i] = 0;
        if (i > 0) {
            local_udp[offset + i - 1] = 0; // Introduces WAW (write-after-write) and WAR (write-after-read) dependencies across iterations
        }
    }
}
