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
    for (i = 40; i < 60; ++i) {
        temp1 = ((A << 5) | (A >> (32 - 5))) + ((B & C) | (B & D) | (C & D)) + E + W[i] + 2400959708L;
        temp2 = ((B << 5) | (B >> (32 - 5))) + ((C & D) | (C & E) | (D & E)) + A + W[(i + 10) % 80] + 2400959708L;
        A = temp1;
        B = temp2;
        C = ((B << 30) | (B >> (32 - 30)));
        D = C;
        E = D;
    }
}
