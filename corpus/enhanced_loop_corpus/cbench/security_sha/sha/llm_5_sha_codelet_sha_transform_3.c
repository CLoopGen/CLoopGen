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
    E = D;
    D = C;
    C = ((B << 30) | (B >> (32 - 30)));
    B = A;
    temp = ((A << 5) | (A >> (32 - 5))) + (B ^ C ^ D) + E + W[i] + 1859775393L;
    A = temp;
}
}
