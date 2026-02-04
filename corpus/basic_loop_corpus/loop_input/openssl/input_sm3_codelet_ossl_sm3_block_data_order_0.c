#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct SM3state_st {
    unsigned int A;
    unsigned int B;
    unsigned int C;
    unsigned int D;
    unsigned int E;
    unsigned int F;
    unsigned int G;
    unsigned int H;
    unsigned int Nl;
    unsigned int Nh;
    unsigned int data[16];
    unsigned int num;
} SM3_CTX;

SM3_CTX *ctx;
size_t num;
unsigned char *data;
unsigned int A;
unsigned int B;
unsigned int C;
unsigned int D;
unsigned int E;
unsigned int F;
unsigned int G;
unsigned int H;
unsigned int W00;
unsigned int W01;
unsigned int W02;
unsigned int W03;
unsigned int W04;
unsigned int W05;
unsigned int W06;
unsigned int W07;
unsigned int W08;
unsigned int W09;
unsigned int W10;
unsigned int W11;
unsigned int W12;
unsigned int W13;
unsigned int W14;
unsigned int W15;

static SM3_CTX ctx_storage;
static unsigned char data_storage[1024 * 128]; // 128KB

void init_vars() {
    ctx = &ctx_storage;
    data = data_storage;
    num = 64; // Each iteration consumes 64 bytes (16 words * 4 bytes)

    ctx->A = 0x73F19A1B;
    ctx->B = 0x8BD7AF44;
    ctx->C = 0x5D7E1DEF;
    ctx->D = 0x9FDAAFB3;
    ctx->E = 0x4581D02D;
    ctx->F = 0xC3AEF0CF;
    ctx->G = 0x9FBE79A8;
    ctx->H = 0x5DAE675D;
    ctx->Nl = 0;
    ctx->Nh = 0;
    ctx->num = 0;
    memset(ctx->data, 0, sizeof(ctx->data));

    memset(data, 0x42, 1024 * 128);

    A = 0;
    B = 0;
    C = 0;
    D = 0;
    E = 0;
    F = 0;
    G = 0;
    H = 0;
    W00 = 0;
    W01 = 0;
    W02 = 0;
    W03 = 0;
    W04 = 0;
    W05 = 0;
    W06 = 0;
    W07 = 0;
    W08 = 0;
    W09 = 0;
    W10 = 0;
    W11 = 0;
    W12 = 0;
    W13 = 0;
    W14 = 0;
    W15 = 0;
}