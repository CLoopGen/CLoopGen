#include <stdio.h>

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

extern SM3_CTX *ctx;
extern size_t num;
extern  unsigned char *data;
extern unsigned int A;
extern unsigned int B;
extern unsigned int C;
extern unsigned int D;
extern unsigned int E;
extern unsigned int F;
extern unsigned int G;
extern unsigned int H;
extern unsigned int W00;
extern unsigned int W01;
extern unsigned int W02;
extern unsigned int W03;
extern unsigned int W04;
extern unsigned int W05;
extern unsigned int W06;
extern unsigned int W07;
extern unsigned int W08;
extern unsigned int W09;
extern unsigned int W10;
extern unsigned int W11;
extern unsigned int W12;
extern unsigned int W13;
extern unsigned int W14;
extern unsigned int W15;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; num--;) {
    A = ctx->A;
    B = ctx->B;
    C = ctx->C;
    D = ctx->D;
    E = ctx->E;
    F = ctx->F;
    G = ctx->G;
    H = ctx->H;

    W00 = (((unsigned long)(data[0])) << 24) | (((unsigned long)(data[1])) << 16) |
          (((unsigned long)(data[2])) << 8) | (((unsigned long)(data[3])));
    W01 = (((unsigned long)(data[4])) << 24) | (((unsigned long)(data[5])) << 16) |
          (((unsigned long)(data[6])) << 8) | (((unsigned long)(data[7])));
    W02 = (((unsigned long)(data[8])) << 24) | (((unsigned long)(data[9])) << 16) |
          (((unsigned long)(data[10])) << 8) | (((unsigned long)(data[11])));
    W03 = (((unsigned long)(data[12])) << 24) | (((unsigned long)(data[13])) << 16) |
          (((unsigned long)(data[14])) << 8) | (((unsigned long)(data[15])));
    data += 16;

    for (int round = 0; round < 4; ++round) {
        unsigned int A12 = ((A << 12) | (A >> 20));
        unsigned int SS1 = ((A12 + E + 2043430169U) << 7) | ((A12 + E + 2043430169U) >> 25);
        unsigned int TT1 = (A ^ B ^ C) + D + (SS1 ^ A12) + (W00 ^ W04);
        unsigned int TT2 = (E ^ F ^ G) + H + SS1 + W00;

        B = (B << 9) | (B >> 23);
        D = TT1;
        F = (F << 19) | (F >> 13);
        H = TT2 ^ (TT2 << 9) ^ (TT2 << 17);

        W00 = (W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17)) ^
               (((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) << 15) |
                ((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) >> 17)) ^
               (((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) << 23) |
                ((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) >> 9))) ^
              ((W03 << 7) | (W03 >> 25)) ^ W10;

        unsigned int temp_A = A; A = D; D = C; C = B; B = temp_A;
        unsigned int temp_E = E; E = H; H = G; G = F; F = temp_E;
    }

    ctx->A ^= A;
    ctx->B ^= B;
    ctx->C ^= C;
    ctx->D ^= D;
    ctx->E ^= E;
    ctx->F ^= F;
    ctx->G ^= G;
    ctx->H ^= H;
}
}
