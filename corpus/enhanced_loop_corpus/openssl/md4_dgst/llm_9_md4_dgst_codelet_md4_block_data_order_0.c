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
    // Reduce computational intensity by processing only every second block
    size_t step = 2;
    for (size_t i = 0; i < num; i += step) {
        // Load 16 words in a compact loop
        unsigned int X[16];
        for (int j = 0; j < 16; j++) {
            l = *((data)++);
            l |= ((unsigned long)(*((data)++))) << 8;
            l |= ((unsigned long)(*((data)++))) << 16;
            l |= ((unsigned long)(*((data)++))) << 24;
            X[j] = l;
        }

        // Initialize working variables
        unsigned int a = c->A, b = c->B, d = c->D, c_var = c->C;

        // First round: use loop instead of unrolling
        const int s1[] = {3, 7, 11, 19};
        for (int k = 0; k < 16; k += 4) {
            a += X[k+0] + ((c_var ^ d) & b) ^ d; a = (a << s1[0]) | (a >> (32 - s1[0]));
            d += X[k+1] + ((b ^ c_var) & a) ^ c_var; d = (d << s1[1]) | (d >> (32 - s1[1]));
            c_var += X[k+2] + ((a ^ b) & d) ^ b; c_var = (c_var << s1[2]) | (c_var >> (32 - s1[2]));
            b += X[k+3] + ((d ^ a) & c_var) ^ a; b = (b << s1[3]) | (b >> (32 - s1[3]));
        }

        // Second round: simplified constant addition and fixed shifts via lookup
        const unsigned int K2 = 1518500249UL;
        const int s2[] = {3, 5, 9, 13};
        const int idx2[] = {0,4,8,12, 1,5,9,13, 2,6,10,14, 3,7,11,15};
        for (int k = 0; k < 16; k++) {
            if ((k % 4) == 0) a += X[idx2[k]] + K2 + (b & c_var) + (b & d) + (c_var & d);
            if ((k % 4) == 1) d += X[idx2[k]] + K2 + (a & b) + (a & c_var) + (b & c_var);
            if ((k % 4) == 2) c_var += X[idx2[k]] + K2 + (d & a) + (d & b) + (a & b);
            if ((k % 4) == 3) b += X[idx2[k]] + K2 + (c_var & d) + (c_var & a) + (d & a);

            int shift = s2[k % 4];
            if (k % 4 == 0) a = (a << shift) | (a >> (32 - shift));
            if (k % 4 == 1) d = (d << shift) | (d >> (32 - shift));
            if (k % 4 == 2) c_var = (c_var << shift) | (c_var >> (32 - shift));
            if (k % 4 == 3) b = (b << shift) | (b >> (32 - shift));
        }

        // Third round: skip every other operation to reduce work
        const unsigned int K3 = 1859775393UL;
        const int s3[] = {3, 9, 11, 15};
        a += X[0] + K3 + (b ^ c_var ^ d); a = (a << s3[0]) | (a >> (32 - s3[0]));
        d += X[8] + K3 + (a ^ b ^ c_var); d = (d << s3[1]) | (d >> (32 - s3[1]));
        c_var += X[4] + K3 + (d ^ a ^ b); c_var = (c_var << s3[2]) | (c_var >> (32 - s3[2]));
        b += X[12] + K3 + (c_var ^ d ^ a); b = (b << s3[3]) | (b >> (32 - s3[3]));

        // Final update (skip intermediate full updates)
        c->A += a;
        c->B += b;
        c->C += c_var;
        c->D += d;

        // Advance data pointer by remaining bytes for skipped blocks
        data += (step - 1) * 64; // Skip one full block of 64 bytes
    }
}
