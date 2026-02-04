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
    int idx = 79 - (i - 60); // Reverse access: from W[79] down to W[60]
    temp = ((A << 5) | (A >> (32 - 5))) + (B ^ C ^ D) + E + W[idx] + 3395469782L;
    E = D;
    D = C;
    C = ((B << 30) | (B >> (32 - 30)));
    B = A;
    A = temp;
}
}
