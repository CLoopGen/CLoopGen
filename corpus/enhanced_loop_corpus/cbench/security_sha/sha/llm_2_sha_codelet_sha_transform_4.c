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
for (i = 40; i < 60; ++i) {
    int idx = i; // Consecutive access preserved, but using an explicit index variable
    temp = ((A << 5) | (A >> (32 - 5))) + ((B & C) | (B & D) | (C & D)) + E + W[idx] + 2400959708L;
    E = D;
    D = C;
    C = ((B << 30) | (B >> (32 - 30)));
    B = A;
    A = temp;
}
}
