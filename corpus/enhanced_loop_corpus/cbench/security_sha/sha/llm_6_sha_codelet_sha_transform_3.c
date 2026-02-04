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
    LONG temp1, temp2;
    for (i = 20; i < 40; ++i) {
        temp1 = ((A << 5) | (A >> (32 - 5))) + (B ^ C ^ D) + E + W[i] + 1859775393L;
        temp2 = ((B << 5) | (B >> (32 - 5))) + (C ^ D ^ E) + A + W[(i + 10) % 80] + 1859775393L;
        E = D;
        D = C;
        C = ((B << 30) | (B >> (32 - 30)));
        B = A;
        A = temp1;
    }
}
