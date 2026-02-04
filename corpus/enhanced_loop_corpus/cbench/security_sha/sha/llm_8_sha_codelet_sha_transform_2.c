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
for (i = 0; i < 40; ++i) {
    temp = ((A << 4) | (A >> (32 - 4))) + ((B & C) | (~B & D)) + E + W[i % 80] + 1518500249L;
    E = D;
    D = C;
    C = ((B << 28) | (B >> (32 - 28)));
    B = A;
    A = temp;
}
}
