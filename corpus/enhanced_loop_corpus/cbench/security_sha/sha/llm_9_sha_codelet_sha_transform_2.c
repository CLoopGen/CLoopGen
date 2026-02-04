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
for (i = 0; i < 10; ++i) {
    LONG w_val = W[i] + W[i + 10];
    temp = ((A << 6) | (A >> 26)) + (B ^ C ^ D) + E + w_val + 1518500249L;
    temp = (temp << 1) | (temp >> 31);
    E = D;
    D = C;
    C = ((B << 31) | (B >> 1));
    B = A;
    A = temp;
    
    temp = ((A << 5) | (A >> 27)) + (B + C & D) + E + W[i + 20] + 1518500249L;
    A = temp;
}
}
