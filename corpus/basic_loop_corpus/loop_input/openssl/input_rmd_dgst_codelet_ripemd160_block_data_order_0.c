#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RIPEMD160state_st {
    unsigned int A;
    unsigned int B;
    unsigned int C;
    unsigned int D;
    unsigned int E;
    unsigned int Nl;
    unsigned int Nh;
    unsigned int data[16];
    unsigned int num;
} RIPEMD160_CTX;

RIPEMD160_CTX ctx_instance;

RIPEMD160_CTX *ctx = &ctx_instance;
size_t num;
unsigned char *data;

unsigned int A;
unsigned int B;
unsigned int C;
unsigned int D;
unsigned int E;
unsigned int a;
unsigned int b;
unsigned int c;
unsigned int d;
unsigned int e;
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

unsigned char input_data[1024 * 128]; // 128KB of input data

void init_vars() {
    // Initialize context
    ctx->A = 0x67452301U;
    ctx->B = 0xEFCDAB89U;
    ctx->C = 0x98BADCFEU;
    ctx->D = 0x10325476U;
    ctx->E = 0xC3D2E1F0U;
    ctx->Nl = 0;
    ctx->Nh = 0;
    ctx->num = 0;
    memset(ctx->data, 0, sizeof(ctx->data));

    // Initialize global state variables
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    E = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    l = 0;
    XX0 = 0;
    XX1 = 0;
    XX2 = 0;
    XX3 = 0;
    XX4 = 0;
    XX5 = 0;
    XX6 = 0;
    XX7 = 0;
    XX8 = 0;
    XX9 = 0;
    XX10 = 0;
    XX11 = 0;
    XX12 = 0;
    XX13 = 0;
    XX14 = 0;
    XX15 = 0;

    // Initialize input data
    for (size_t i = 0; i < sizeof(input_data); i++) {
        input_data[i] = (unsigned char)(i & 0xFF);
    }

    // Set data pointer to start of input buffer
    data = input_data;

    // Set loop counter: each iteration consumes 64 bytes (16 words * 4 bytes)
    // We want enough iterations to take ~0.01 seconds on modern CPU
    // Assuming ~1000-2000 cycles per iteration, we need several thousand iterations
    num = sizeof(input_data) / 64;
}