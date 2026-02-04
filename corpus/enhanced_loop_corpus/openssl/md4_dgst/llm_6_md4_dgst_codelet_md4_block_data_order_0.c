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
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX0 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX1 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX2 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX3 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX4 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX5 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX6 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX7 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX8 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX9 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX10 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX11 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX12 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX13 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX14 = l;
    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
    XX15 = l;

    unsigned int tempA = A, tempB = B, tempC = C, tempD = D;

    {
        tempA += ((XX0) + (0) + (((((tempC)) ^ ((tempD))) & ((tempB))) ^ ((tempD))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX1) + (0) + (((((tempB)) ^ ((tempC))) & ((tempA))) ^ ((tempC))));
        tempD = (((tempD) << (7)) | (((tempD) & 4294967295U) >> (32 - (7))));
    }
    {
        tempC += ((XX2) + (0) + (((((tempA)) ^ ((tempB))) & ((tempD))) ^ ((tempB))));
        tempC = (((tempC) << (11)) | (((tempC) & 4294967295U) >> (32 - (11))));
    }
    {
        tempB += ((XX3) + (0) + (((((tempD)) ^ ((tempA))) & ((tempC))) ^ ((tempA))));
        tempB = (((tempB) << (19)) | (((tempB) & 4294967295U) >> (32 - (19))));
    }

    {
        tempA += ((XX4) + (0) + (((((tempC)) ^ ((tempD))) & ((tempB))) ^ ((tempD))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX5) + (0) + (((((tempB)) ^ ((tempC))) & ((tempA))) ^ ((tempC))));
        tempD = (((tempD) << (7)) | (((tempD) & 4294967295U) >> (32 - (7))));
    }
    {
        tempC += ((XX6) + (0) + (((((tempA)) ^ ((tempB))) & ((tempD))) ^ ((tempB))));
        tempC = (((tempC) << (11)) | (((tempC) & 4294967295U) >> (32 - (11))));
    }
    {
        tempB += ((XX7) + (0) + (((((tempD)) ^ ((tempA))) & ((tempC))) ^ ((tempA))));
        tempB = (((tempB) << (19)) | (((tempB) & 4294967295U) >> (32 - (19))));
    }

    {
        tempA += ((XX8) + (0) + (((((tempC)) ^ ((tempD))) & ((tempB))) ^ ((tempD))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX9) + (0) + (((((tempB)) ^ ((tempC))) & ((tempA))) ^ ((tempC))));
        tempD = (((tempD) << (7)) | (((tempD) & 4294967295U) >> (32 - (7))));
    }
    {
        tempC += ((XX10) + (0) + (((((tempA)) ^ ((tempB))) & ((tempD))) ^ ((tempB))));
        tempC = (((tempC) << (11)) | (((tempC) & 4294967295U) >> (32 - (11))));
    }
    {
        tempB += ((XX11) + (0) + (((((tempD)) ^ ((tempA))) & ((tempC))) ^ ((tempA))));
        tempB = (((tempB) << (19)) | (((tempB) & 4294967295U) >> (32 - (19))));
    }

    {
        tempA += ((XX12) + (0) + (((((tempC)) ^ ((tempD))) & ((tempB))) ^ ((tempD))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX13) + (0) + (((((tempB)) ^ ((tempC))) & ((tempA))) ^ ((tempC))));
        tempD = (((tempD) << (7)) | (((tempD) & 4294967295U) >> (32 - (7))));
    }
    {
        tempC += ((XX14) + (0) + (((((tempA)) ^ ((tempB))) & ((tempD))) ^ ((tempB))));
        tempC = (((tempC) << (11)) | (((tempC) & 4294967295U) >> (32 - (11))));
    }
    {
        tempB += ((XX15) + (0) + (((((tempD)) ^ ((tempA))) & ((tempC))) ^ ((tempA))));
        tempB = (((tempB) << (19)) | (((tempB) & 4294967295U) >> (32 - (19))));
    }

    {
        tempA += ((XX0) + (1518500249L) + ((((tempB)) & ((tempC))) | (((tempB)) & ((tempD))) | (((tempC)) & ((tempD)))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX4) + (1518500249L) + ((((tempA)) & ((tempB))) | (((tempA)) & ((tempC))) | (((tempB)) & ((tempC)))));
        tempD = (((tempD) << (5)) | (((tempD) & 4294967295U) >> (32 - (5))));
    }
    {
        tempC += ((XX8) + (1518500249L) + ((((tempD)) & ((tempA))) | (((tempD)) & ((tempB))) | (((tempA)) & ((tempB)))));
        tempC = (((tempC) << (9)) | (((tempC) & 4294967295U) >> (32 - (9))));
    }
    {
        tempB += ((XX12) + (1518500249L) + ((((tempC)) & ((tempD))) | (((tempC)) & ((tempA))) | (((tempD)) & ((tempA)))));
        tempB = (((tempB) << (13)) | (((tempB) & 4294967295U) >> (32 - (13))));
    }

    {
        tempA += ((XX1) + (1518500249L) + ((((tempB)) & ((tempC))) | (((tempB)) & ((tempD))) | (((tempC)) & ((tempD)))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX5) + (1518500249L) + ((((tempA)) & ((tempB))) | (((tempA)) & ((tempC))) | (((tempB)) & ((tempC)))));
        tempD = (((tempD) << (5)) | (((tempD) & 4294967295U) >> (32 - (5))));
    }
    {
        tempC += ((XX9) + (1518500249L) + ((((tempD)) & ((tempA))) | (((tempD)) & ((tempB))) | (((tempA)) & ((tempB)))));
        tempC = (((tempC) << (9)) | (((tempC) & 4294967295U) >> (32 - (9))));
    }
    {
        tempB += ((XX13) + (1518500249L) + ((((tempC)) & ((tempD))) | (((tempC)) & ((tempA))) | (((tempD)) & ((tempA)))));
        tempB = (((tempB) << (13)) | (((tempB) & 4294967295U) >> (32 - (13))));
    }

    {
        tempA += ((XX2) + (1518500249L) + ((((tempB)) & ((tempC))) | (((tempB)) & ((tempD))) | (((tempC)) & ((tempD)))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX6) + (1518500249L) + ((((tempA)) & ((tempB))) | (((tempA)) & ((tempC))) | (((tempB)) & ((tempC)))));
        tempD = (((tempD) << (5)) | (((tempD) & 4294967295U) >> (32 - (5))));
    }
    {
        tempC += ((XX10) + (1518500249L) + ((((tempD)) & ((tempA))) | (((tempD)) & ((tempB))) | (((tempA)) & ((tempB)))));
        tempC = (((tempC) << (9)) | (((tempC) & 4294967295U) >> (32 - (9))));
    }
    {
        tempB += ((XX14) + (1518500249L) + ((((tempC)) & ((tempD))) | (((tempC)) & ((tempA))) | (((tempD)) & ((tempA)))));
        tempB = (((tempB) << (13)) | (((tempB) & 4294967295U) >> (32 - (13))));
    }

    {
        tempA += ((XX3) + (1518500249L) + ((((tempB)) & ((tempC))) | (((tempB)) & ((tempD))) | (((tempC)) & ((tempD)))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX7) + (1518500249L) + ((((tempA)) & ((tempB))) | (((tempA)) & ((tempC))) | (((tempB)) & ((tempC)))));
        tempD = (((tempD) << (5)) | (((tempD) & 4294967295U) >> (32 - (5))));
    }
    {
        tempC += ((XX11) + (1518500249L) + ((((tempD)) & ((tempA))) | (((tempD)) & ((tempB))) | (((tempA)) & ((tempB)))));
        tempC = (((tempC) << (9)) | (((tempC) & 4294967295U) >> (32 - (9))));
    }
    {
        tempB += ((XX15) + (1518500249L) + ((((tempC)) & ((tempD))) | (((tempC)) & ((tempA))) | (((tempD)) & ((tempA)))));
        tempB = (((tempB) << (13)) | (((tempB) & 4294967295U) >> (32 - (13))));
    }

    {
        tempA += ((XX0) + (1859775393L) + (((tempB)) ^ ((tempC)) ^ ((tempD))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX8) + (1859775393L) + (((tempA)) ^ ((tempB)) ^ ((tempC))));
        tempD = (((tempD) << (9)) | (((tempD) & 4294967295U) >> (32 - (9))));
    }
    {
        tempC += ((XX4) + (1859775393L) + (((tempD)) ^ ((tempA)) ^ ((tempB))));
        tempC = (((tempC) << (11)) | (((tempC) & 4294967295U) >> (32 - (11))));
    }
    {
        tempB += ((XX12) + (1859775393L) + (((tempC)) ^ ((tempD)) ^ ((tempA))));
        tempB = (((tempB) << (15)) | (((tempB) & 4294967295U) >> (32 - (15))));
    }

    {
        tempA += ((XX2) + (1859775393L) + (((tempB)) ^ ((tempC)) ^ ((tempD))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX10) + (1859775393L) + (((tempA)) ^ ((tempB)) ^ ((tempC))));
        tempD = (((tempD) << (9)) | (((tempD) & 4294967295U) >> (32 - (9))));
    }
    {
        tempC += ((XX6) + (1859775393L) + (((tempD)) ^ ((tempA)) ^ ((tempB))));
        tempC = (((tempC) << (11)) | (((tempC) & 4294967295U) >> (32 - (11))));
    }
    {
        tempB += ((XX14) + (1859775393L) + (((tempC)) ^ ((tempD)) ^ ((tempA))));
        tempB = (((tempB) << (15)) | (((tempB) & 4294967295U) >> (32 - (15))));
    }

    {
        tempA += ((XX1) + (1859775393L) + (((tempB)) ^ ((tempC)) ^ ((tempD))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX9) + (1859775393L) + (((tempA)) ^ ((tempB)) ^ ((tempC))));
        tempD = (((tempD) << (9)) | (((tempD) & 4294967295U) >> (32 - (9))));
    }
    {
        tempC += ((XX5) + (1859775393L) + (((tempD)) ^ ((tempA)) ^ ((tempB))));
        tempC = (((tempC) << (11)) | (((tempC) & 4294967295U) >> (32 - (11))));
    }
    {
        tempB += ((XX13) + (1859775393L) + (((tempC)) ^ ((tempD)) ^ ((tempA))));
        tempB = (((tempB) << (15)) | (((tempB) & 4294967295U) >> (32 - (15))));
    }

    {
        tempA += ((XX3) + (1859775393L) + (((tempB)) ^ ((tempC)) ^ ((tempD))));
        tempA = (((tempA) << (3)) | (((tempA) & 4294967295U) >> (32 - (3))));
    }
    {
        tempD += ((XX11) + (1859775393L) + (((tempA)) ^ ((tempB)) ^ ((tempC))));
        tempD = (((tempD) << (9)) | (((tempD) & 4294967295U) >> (32 - (9))));
    }
    {
        tempC += ((XX7) + (1859775393L) + (((tempD)) ^ ((tempA)) ^ ((tempB))));
        tempC = (((tempC) << (11)) | (((tempC) & 4294967295U) >> (32 - (11))));
    }
    {
        tempB += ((XX15) + (1859775393L) + (((tempC)) ^ ((tempD)) ^ ((tempA))));
        tempB = (((tempB) << (15)) | (((tempB) & 4294967295U) >> (32 - (15))));
    }

    A = c->A += tempA;
    B = c->B += tempB;
    C = c->C += tempC;
    D = c->D += tempD;
}
}
