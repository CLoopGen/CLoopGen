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
for (i = 20; i < 40; ++i) {
    LONG w_val = W[i] ^ 0xABCDEF12L;
    temp = ((A << 7) | (A >> (32 - 7))) + (B ^ C ^ D ^ w_val) + E + W[(i+5) % 80] + 1859775393L;
    temp += (W[i] >> 16) * (W[i] & 0xFFFF);
    E = D;
    D = C;
    C = ((B << 28) | (B >> (32 - 28)));
    C ^= (E << 3);
    B = A;
    A = temp;
}
}
