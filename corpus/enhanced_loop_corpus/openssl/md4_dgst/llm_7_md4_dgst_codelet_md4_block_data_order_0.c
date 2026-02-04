#include <stdio.h>

#include <inttypes.h>

typedef struct MD4state_st {
    unsigned int A;
    unsigned int B;
    unsigned int C;
    unsigned int D;
    unsigned int Nl;
    unsigned int Nh;
    unsigned int data[16];
    unsigned int num;
} MD4_CTX;

extern MD4_CTX *c;
extern size_t num;
extern  unsigned char *data;
extern unsigned int A;
extern unsigned int B;
extern unsigned int C;
extern unsigned int D;
extern unsigned int l;
extern unsigned int XX0;
extern unsigned int XX1;
extern unsigned int XX2;
extern unsigned int XX3;
extern unsigned int XX4;
extern unsigned int XX5;
extern unsigned int XX6;
extern unsigned int XX7;
extern unsigned int XX8;
extern unsigned int XX9;
extern unsigned int XX10;
extern unsigned int XX11;
extern unsigned int XX12;
extern unsigned int XX13;
extern unsigned int XX14;
extern unsigned int XX15;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; num--;) {
    unsigned int local_data[16];
    for (int i = 0; i < 16; ++i) {
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        local_data[i] = l;
    }

    unsigned int tempA = c->A;
    unsigned int tempB = c->B;
    unsigned int tempC = c->C;
    unsigned int tempD = c->D;

    #define ROUND1_STEP(a,b,c,d,x,s) \
        a += (x) + (0) + ((((c) ^ (d)) & (b)) ^ (d)); \
        a = (((a) << (s)) | (((a) & 4294967295U) >> (32 - (s))));

    #define ROUND2_STEP(a,b,c,d,x,s) \
        a += (x) + (1518500249L) + (((b) & (c)) | ((b) & (d)) | ((c) & (d))); \
        a = (((a) << (s)) | (((a) & 4294967295U) >> (32 - (s))));

    #define ROUND3_STEP(a,b,c,d,x,s) \
        a += (x) + (1859775393L) + ((b) ^ (c) ^ (d)); \
        a = (((a) << (s)) | (((a) & 4294967295U) >> (32 - (s))));

    ROUND1_STEP(tempA, tempB, tempC, tempD, local_data[0],  3)
    ROUND1_STEP(tempD, tempA, tempB, tempC, local_data[1],  7)
    ROUND1_STEP(tempC, tempD, tempA, tempB, local_data[2], 11)
    ROUND1_STEP(tempB, tempC, tempD, tempA, local_data[3], 19)

    ROUND1_STEP(tempA, tempB, tempC, tempD, local_data[4],  3)
    ROUND1_STEP(tempD, tempA, tempB, tempC, local_data[5],  7)
    ROUND1_STEP(tempC, tempD, tempA, tempB, local_data[6], 11)
    ROUND1_STEP(tempB, tempC, tempD, tempA, local_data[7], 19)

    ROUND1_STEP(tempA, tempB, tempC, tempD, local_data[8],  3)
    ROUND1_STEP(tempD, tempA, tempB, tempC, local_data[9],  7)
    ROUND1_STEP(tempC, tempD, tempA, tempB, local_data[10], 11)
    ROUND1_STEP(tempB, tempC, tempD, tempA, local_data[11], 19)

    ROUND1_STEP(tempA, tempB, tempC, tempD, local_data[12],  3)
    ROUND1_STEP(tempD, tempA, tempB, tempC, local_data[13],  7)
    ROUND1_STEP(tempC, tempD, tempA, tempB, local_data[14], 11)
    ROUND1_STEP(tempB, tempC, tempD, tempA, local_data[15], 19)

    ROUND2_STEP(tempA, tempB, tempC, tempD, local_data[0],  3)
    ROUND2_STEP(tempD, tempA, tempB, tempC, local_data[4],  5)
    ROUND2_STEP(tempC, tempD, tempA, tempB, local_data[8],  9)
    ROUND2_STEP(tempB, tempC, tempD, tempA, local_data[12], 13)

    ROUND2_STEP(tempA, tempB, tempC, tempD, local_data[1],  3)
    ROUND2_STEP(tempD, tempA, tempB, tempC, local_data[5],  5)
    ROUND2_STEP(tempC, tempD, tempA, tempB, local_data[9],  9)
    ROUND2_STEP(tempB, tempC, tempD, tempA, local_data[13], 13)

    ROUND2_STEP(tempA, tempB, tempC, tempD, local_data[2],  3)
    ROUND2_STEP(tempD, tempA, tempB, tempC, local_data[6],  5)
    ROUND2_STEP(tempC, tempD, tempA, tempB, local_data[10], 9)
    ROUND2_STEP(tempB, tempC, tempD, tempA, local_data[14], 13)

    ROUND2_STEP(tempA, tempB, tempC, tempD, local_data[3],  3)
    ROUND2_STEP(tempD, tempA, tempB, tempC, local_data[7],  5)
    ROUND2_STEP(tempC, tempD, tempA, tempB, local_data[11], 9)
    ROUND2_STEP(tempB, tempC, tempD, tempA, local_data[15], 13)

    ROUND3_STEP(tempA, tempB, tempC, tempD, local_data[0],  3)
    ROUND3_STEP(tempD, tempA, tempB, tempC, local_data[8],  9)
    ROUND3_STEP(tempC, tempD, tempA, tempB, local_data[4], 11)
    ROUND3_STEP(tempB, tempC, tempD, tempA, local_data[12], 15)

    ROUND3_STEP(tempA, tempB, tempC, tempD, local_data[2],  3)
    ROUND3_STEP(tempD, tempA, tempB, tempC, local_data[10], 9)
    ROUND3_STEP(tempC, tempD, tempA, tempB, local_data[6], 11)
    ROUND3_STEP(tempB, tempC, tempD, tempA, local_data[14], 15)

    ROUND3_STEP(tempA, tempB, tempC, tempD, local_data[1],  3)
    ROUND3_STEP(tempD, tempA, tempB, tempC, local_data[9],  9)
    ROUND3_STEP(tempC, tempD, tempA, tempB, local_data[5], 11)
    ROUND3_STEP(tempB, tempC, tempD, tempA, local_data[13], 15)

    ROUND3_STEP(tempA, tempB, tempC, tempD, local_data[3],  3)
    ROUND3_STEP(tempD, tempA, tempB, tempC, local_data[11], 9)
    ROUND3_STEP(tempC, tempD, tempA, tempB, local_data[7], 11)
    ROUND3_STEP(tempB, tempC, tempD, tempA, local_data[15], 15)

    c->A += tempA;
    c->B += tempB;
    c->C += tempC;
    c->D += tempD;

    A = c->A;
    B = c->B;
    C = c->C;
    D = c->D;
}
}
