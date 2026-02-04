#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t j;
extern  unsigned int K[64];
extern unsigned int A;
extern unsigned int B;
extern unsigned int C;
extern unsigned int D;
extern unsigned int E;
extern unsigned int F;
extern unsigned int G;
extern unsigned int H;
extern unsigned int T1;
extern unsigned int T2;
extern unsigned int W[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
unsigned int temp_A, temp_B, temp_C, temp_D;
for (j = 0; j < 64; j++) {
    T1 = ((unsigned int)((H + ((((unsigned int)((((E) >> 6) | ((E) << (32 - 6))) & 4294967295U))) ^ (((unsigned int)((((E) >> 11) | ((E) << (32 - 11))) & 4294967295U))) ^ (((unsigned int)((((E) >> 25) | ((E) << (32 - 25))) & 4294967295U)))) + (((E) & (F)) ^ (~(E) & (G))) + K[j] + W[j]) & 4294967295U));
    T2 = ((unsigned int)((((((unsigned int)((((A) >> 2) | ((A) << (32 - 2))) & 4294967295U))) ^ (((unsigned int)((((A) >> 13) | ((A) << (32 - 13))) & 4294967295U))) ^ (((unsigned int)((((A) >> 22) | ((A) << (32 - 22))) & 4294967295U)))) + (((A) & (B)) ^ ((A) & (C)) ^ ((B) & (C)))) & 4294967295U));

    temp_A = ((unsigned int)((T1 + T2) & 4294967295U));
    temp_B = A;
    temp_C = B;
    temp_D = C;

    H = G;
    G = F;
    F = E;
    E = ((unsigned int)((D + T1) & 4294967295U));
    D = temp_C;
    C = temp_B;
    B = temp_B; 
    A = temp_A;
}

}
