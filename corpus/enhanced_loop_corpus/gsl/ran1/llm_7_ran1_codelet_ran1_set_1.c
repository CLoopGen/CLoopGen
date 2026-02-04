#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned long x;
    unsigned long n;
    unsigned long shuffle[32];
} ran1_state_t;

extern  long m;
extern  long a;
extern  long q;
extern  long r;
extern unsigned long s;
extern ran1_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp_shuffle[32];
    for (i = 0; i < 32; i++) {
        long h = s / q;
        long t = a * (s - h * q) - h * r;
        if (t < 0)
            t += m;
        temp_shuffle[31 - i] = t;
        s = t;
    }
    for (i = 0; i < 32; i++) {
        state->shuffle[i] = temp_shuffle[i];
    }
}
