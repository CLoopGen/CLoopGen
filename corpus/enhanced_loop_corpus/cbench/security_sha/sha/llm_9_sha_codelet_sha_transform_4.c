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
    LONG shifted_A = (A << 5) | (A >> 27);
    LONG majority = (B & C) ^ (B & D) ^ (C & D);
    LONG rotated_B = (B << 30) | (B >> 2);
    temp = shifted_A + majority + E + W[i] + 2400959708L;
    E = D;
    D = C;
    C = rotated_B;
    B = A;
    A = temp;

    // Additional computational work to increase intensity
    temp = (temp ^ W[(i+5) % 80]) + (A & 0xFFFF) + ((E << 1) | (E >> 31));
    A = temp;
}
}
