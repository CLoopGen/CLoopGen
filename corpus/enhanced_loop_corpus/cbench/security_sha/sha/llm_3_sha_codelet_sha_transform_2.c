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
int indices[20];
for (int j = 0; j < 20; ++j) {
    indices[j] = (19 - j); // Reverse order access
}
for (i = 0; i < 20; ++i) {
    int idx = indices[i]; // Indirect access via index array
    temp = ((A << 5) | (A >> (32 - 5))) + ((B & C) | (~B & D)) + E + W[idx] + 1518500249L;
    E = D;
    D = C;
    C = ((B << 30) | (B >> (32 - 30)));
    B = A;
    A = temp;
}
}
