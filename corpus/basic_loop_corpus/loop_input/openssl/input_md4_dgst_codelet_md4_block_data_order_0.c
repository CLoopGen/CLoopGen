#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

MD4_CTX *c;
size_t num;
unsigned char *data;
unsigned int A;
unsigned int B;
unsigned int C;
unsigned int D;
unsigned int l;
unsigned int XX0;
unsigned int XX1;
unsigned int XX2;
unsigned int XX3;
unsigned int XX4;
unsigned int XX5;
unsigned int XX6;
unsigned int XX7;
unsigned int XX8;
unsigned int XX9;
unsigned int XX10;
unsigned int XX11;
unsigned int XX12;
unsigned int XX13;
unsigned int XX14;
unsigned int XX15;

void init_vars() {
    c = (MD4_CTX *)malloc(sizeof(MD4_CTX));
    c->A = 0x67452301;
    c->B = 0xefcdab89;
    c->C = 0x98badcfe;
    c->D = 0x10325476;
    c->Nl = 0;
    c->Nh = 0;
    c->num = 0;
    memset(c->data, 0, 16 * sizeof(unsigned int));

    const size_t input_size = 1024 * 256; // ~256KB of data to target ~0.01s runtime on modern CPUs
    data = (unsigned char *)malloc(input_size);
    for (size_t i = 0; i < input_size; ++i) {
        data[i] = (unsigned char)(i & 0xFF);
    }

    num = input_size / 64; // Each loop iteration consumes 64 bytes (16 words × 4 bytes)

    A = c->A;
    B = c->B;
    C = c->C;
    D = c->D;
    l = 0;
    XX0 = XX1 = XX2 = XX3 = XX4 = XX5 = XX6 = XX7 = XX8 = XX9 = XX10 = XX11 = XX12 = XX13 = XX14 = XX15 = 0;
}