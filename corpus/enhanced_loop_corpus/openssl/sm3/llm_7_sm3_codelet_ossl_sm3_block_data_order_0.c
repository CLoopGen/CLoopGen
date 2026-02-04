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
for (; num > 0; num -= 2) {
    if (num == 1) break;

    A = ctx->A; B = ctx->B; C = ctx->C; D = ctx->D;
    E = ctx->E; F = ctx->F; G = ctx->G; H = ctx->H;

    for (int i = 0; i < 16; ++i) {
        ((unsigned int*)&W00)[i] = (((unsigned long)data[0]) << 24) |
                                    (((unsigned long)data[1]) << 16) |
                                    (((unsigned long)data[2]) << 8) |
                                    (((unsigned long)data[3]));
        data += 4;
    }

    for (int r = 0; r < 8; ++r) {
        unsigned int A12 = ((A << 12) | (A >> 20));
        unsigned int SS1 = ((A12 + E + 2043430169U) << 7) | ((A12 + E + 2043430169U) >> 25);
        unsigned int TT1 = (A ^ B ^ C) + D + (SS1 ^ A12) + (W00 ^ W04);
        unsigned int TT2 = (E ^ F ^ G) + H + SS1 + W00;

        B = (B << 9) | (B >> 23);
        D = TT1;
        F = (F << 19) | (F >> 13);
        H = TT2 ^ (TT2 << 9) ^ (TT2 << 17);

        unsigned int new_W = (W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17)) ^
                             (((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) << 15) |
                              ((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) >> 17)) ^
                             (((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) << 23) |
                              ((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) >> 9))) ^
                            ((W03 << 7) | (W03 >> 25)) ^ W10;

        W00 = W01; W01 = W02; W02 = W03; W03 = W04; W04 = W05; W05 = W06; W06 = W07;
        W07 = W08; W08 = W09; W09 = W10; W10 = W11; W11 = W12; W12 = W13; W13 = W14; W14 = W15; W15 = new_W;

        unsigned int t = A; A = B; B = C; C = D; D = t;
        t = E; E = F; F = G; G = H; H = t;
    }

    ctx->A ^= A;
    ctx->B ^= B;
    ctx->C ^= C;
    ctx->D ^= D;
    ctx->E ^= E;
    ctx->F ^= F;
    ctx->G ^= G;
    ctx->H ^= H;

    A = ctx->A; B = ctx->B; C = ctx->C; D = ctx->D;
    E = ctx->E; F = ctx->F; G = ctx->G; H = ctx->H;

    for (int r = 0; r < 8; ++r) {
        unsigned int A12 = ((A << 12) | (A >> 20));
        unsigned int SS1 = ((A12 + E + 4086860338U) << 7) | ((A12 + E + 4086860338U) >> 25);
        unsigned int TT1 = (D ^ A ^ B) + C + (SS1 ^ A12) + (W01 ^ W05);
        unsigned int TT2 = (H ^ E ^ F) + G + SS1 + W01;

        A = (A << 9) | (A >> 23);
        C = TT1;
        E = (E << 19) | (E >> 13);
        G = TT2 ^ (TT2 << 9) ^ (TT2 << 17);

        unsigned int new_W = (W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17)) ^
                             (((W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17))) << 15) |
                              ((W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17))) >> 17)) ^
                             (((W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17))) << 23) |
                              ((W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17))) >> 9))) ^
                            ((W04 << 7) | (W04 >> 25)) ^ W11;

        W01 = W02; W02 = W03; W03 = W04; W04 = W05; W05 = W06; W06 = W07; W07 = W08;
        W08 = W09; W09 = W10; W10 = W11; W11 = W12; W12 = W13; W13 = W14; W14 = W15; W15 = new_W;

        unsigned int t = A; A = B; B = C; C = D; D = t;
        t = E; E = F; F = G; G = H; H = t;
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
