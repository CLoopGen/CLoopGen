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
for (i = 60; i < 80; ++i) {
    LONG w_val = W[i] ^ 1817834972L;
    temp = ((A << 5) | (A >> 27)) + (B ^ C ^ D) + E + w_val + 3395469782L;
    E = D;
    D = C;
    C = ((C << 1) | (C >> 31)) ^ temp;
    B = (B ^ A) + temp;
    A = temp + ((E << 3) | (E >> 29));
}
}
