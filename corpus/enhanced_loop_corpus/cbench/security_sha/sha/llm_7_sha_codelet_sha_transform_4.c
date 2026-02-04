#include <stdio.h>

#include <inttypes.h>

typedef unsigned long LONG;

extern int i;
extern LONG temp;
extern LONG A;
extern LONG B;
extern LONG C;
extern LONG D;
extern LONG E;
extern LONG W[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    LONG local_A = A, local_B = B, local_C = C, local_D = D, local_E = E;
    for (i = 40; i < 60; ++i) {
        temp = ((local_A << 5) | (local_A >> (32 - 5))) + ((local_B & local_C) | (local_B & local_D) | (local_C & local_D)) + local_E + W[i] + 2400959708L;
        local_E = local_D;
        local_D = local_C;
        local_C = ((local_B << 30) | (local_B >> (32 - 30)));
        local_B = local_A;
        local_A = temp;
    }
    A = local_A; B = local_B; C = local_C; D = local_D; E = local_E;
}
