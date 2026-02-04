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
    LONG temp_arr[20];
    for (i = 0; i < 20; ++i) {
        temp_arr[i] = ((A << 5) | (A >> (32 - 5))) + ((B & C) | (~B & D)) + E + W[i] + 1518500249L;
    }
    for (i = 0; i < 20; ++i) {
        E = D;
        D = C;
        C = ((B << 30) | (B >> (32 - 30)));
        B = A;
        A = temp_arr[i];
    }
}
