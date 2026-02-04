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

    (void)(W00 = (((unsigned long)(*((data)++))) << 24), W00 |= (((unsigned long)(*((data)++))) << 16), W00 |= (((unsigned long)(*((data)++))) << 8), W00 |= (((unsigned long)(*((data)++)))));
    (void)(W01 = (((unsigned long)(*((data)++))) << 24), W01 |= (((unsigned long)(*((data)++))) << 16), W01 |= (((unsigned long)(*((data)++))) << 8), W01 |= (((unsigned long)(*((data)++)))));
    (void)(W02 = (((unsigned long)(*((data)++))) << 24), W02 |= (((unsigned long)(*((data)++))) << 16), W02 |= (((unsigned long)(*((data)++))) << 8), W02 |= (((unsigned long)(*((data)++)))));
    (void)(W03 = (((unsigned long)(*((data)++))) << 24), W03 |= (((unsigned long)(*((data)++))) << 16), W03 |= (((unsigned long)(*((data)++))) << 8), W03 |= (((unsigned long)(*((data)++)))));
    (void)(W04 = (((unsigned long)(*((data)++))) << 24), W04 |= (((unsigned long)(*((data)++))) << 16), W04 |= (((unsigned long)(*((data)++))) << 8), W04 |= (((unsigned long)(*((data)++)))));
    (void)(W05 = (((unsigned long)(*((data)++))) << 24), W05 |= (((unsigned long)(*((data)++))) << 16), W05 |= (((unsigned long)(*((data)++))) << 8), W05 |= (((unsigned long)(*((data)++)))));
    (void)(W06 = (((unsigned long)(*((data)++))) << 24), W06 |= (((unsigned long)(*((data)++))) << 16), W06 |= (((unsigned long)(*((data)++))) << 8), W06 |= (((unsigned long)(*((data)++)))));
    (void)(W07 = (((unsigned long)(*((data)++))) << 24), W07 |= (((unsigned long)(*((data)++))) << 16), W07 |= (((unsigned long)(*((data)++))) << 8), W07 |= (((unsigned long)(*((data)++)))));
    (void)(W08 = (((unsigned long)(*((data)++))) << 24), W08 |= (((unsigned long)(*((data)++))) << 16), W08 |= (((unsigned long)(*((data)++))) << 8), W08 |= (((unsigned long)(*((data)++)))));
    (void)(W09 = (((unsigned long)(*((data)++))) << 24), W09 |= (((unsigned long)(*((data)++))) << 16), W09 |= (((unsigned long)(*((data)++))) << 8), W09 |= (((unsigned long)(*((data)++)))));
    (void)(W10 = (((unsigned long)(*((data)++))) << 24), W10 |= (((unsigned long)(*((data)++))) << 16), W10 |= (((unsigned long)(*((data)++))) << 8), W10 |= (((unsigned long)(*((data)++)))));
    (void)(W11 = (((unsigned long)(*((data)++))) << 24), W11 |= (((unsigned long)(*((data)++))) << 16), W11 |= (((unsigned long)(*((data)++))) << 8), W11 |= (((unsigned long)(*((data)++)))));
    (void)(W12 = (((unsigned long)(*((data)++))) << 24), W12 |= (((unsigned long)(*((data)++))) << 16), W12 |= (((unsigned long)(*((data)++))) << 8), W12 |= (((unsigned long)(*((data)++)))));
    (void)(W13 = (((unsigned long)(*((data)++))) << 24), W13 |= (((unsigned long)(*((data)++))) << 16), W13 |= (((unsigned long)(*((data)++))) << 8), W13 |= (((unsigned long)(*((data)++)))));
    (void)(W14 = (((unsigned long)(*((data)++))) << 24), W14 |= (((unsigned long)(*((data)++))) << 16), W14 |= (((unsigned long)(*((data)++))) << 8), W14 |= (((unsigned long)(*((data)++)))));
    (void)(W15 = (((unsigned long)(*((data)++))) << 24), W15 |= (((unsigned long)(*((data)++))) << 16), W15 |= (((unsigned long)(*((data)++))) << 8), W15 |= (((unsigned long)(*((data)++)))));

    if ((A ^ C ^ E ^ G) < (B ^ D ^ F ^ H)) {
        const unsigned int A12 = (((A) << (12)) | (((A) & 4294967295U) >> (32 - (12))));
        const unsigned int A12_SM = A12 + E + 2043430169;
        const unsigned int SS1 = (((A12_SM) << (7)) | (((A12_SM) & 4294967295U) >> (32 - (7))));
        const unsigned int TT1 = (A ^ B ^ C) + D + (SS1 ^ A12) + (W00 ^ W04);
        const unsigned int TT2 = (E ^ F ^ G) + H + SS1 + W00;
        B = (((B) << (9)) | (((B) & 4294967295U) >> (32 - (9))));
        D = TT1;
        F = (((F) << (19)) | (((F) & 4294967295U) >> (32 - (19))));
        H = (TT2 ^ (((TT2) << (9)) | (((TT2) & 4294967295U) >> (32 - (9)))) ^ (((TT2) << (17)) | (((TT2) & 4294967295U) >> (32 - (17)))));
    } else if ((A ^ B) > 0x7FFFFFFFU) {
        const unsigned int A12 = (((D) << (12)) | (((D) & 4294967295U) >> (32 - (12))));
        const unsigned int A12_SM = A12 + H + 4086860338U;
        const unsigned int SS1 = (((A12_SM) << (7)) | (((A12_SM) & 4294967295U) >> (32 - (7))));
        const unsigned int TT1 = (D ^ A ^ B) + C + (SS1 ^ A12) + (W01 ^ W05);
        const unsigned int TT2 = (H ^ E ^ F) + G + SS1 + W01;
        A = (((A) << (9)) | (((A) & 4294967295U) >> (32 - (9))));
        C = TT1;
        E = (((E) << (19)) | (((E) & 4294967295U) >> (32 - (19))));
        G = (TT2 ^ (((TT2) << (9)) | (((TT2) & 4294967295U) >> (32 - (9)))) ^ (((TT2) << (17)) | (((TT2) & 4294967295U) >> (32 - (17)))));
    } else {
        const unsigned int A12 = (((C) << (12)) | (((C) & 4294967295U) >> (32 - (12))));
        const unsigned int A12_SM = A12 + G + 3878753381U;
        const unsigned int SS1 = (((A12_SM) << (7)) | (((A12_SM) & 4294967295U) >> (32 - (7))));
        const unsigned int TT1 = (C ^ D ^ A) + B + (SS1 ^ A12) + (W02 ^ W06);
        const unsigned int TT2 = (G ^ H ^ E) + F + SS1 + W02;
        D = (((D) << (9)) | (((D) & 4294967295U) >> (32 - (9))));
        B = TT1;
        H = (((H) << (19)) | (((H) & 4294967295U) >> (32 - (19))));
        F = (TT2 ^ (((TT2) << (9)) | (((TT2) & 4294967295U) >> (32 - (9)))) ^ (((TT2) << (17)) | (((TT2) & 4294967295U) >> (32 - (17)))));
    }

    W00 = ((W00 ^ W07 ^ (((W13) << (15)) | (((W13) & 4294967295U) >> (32 - (15)))) ^ (((W00 ^ W07 ^ (((W13) << (15)) | (((W13) & 4294967295U) >> (32 - (15))))) << (15)) | (((W00 ^ W07 ^ (((W13) << (15)) | (((W13) & 4294967295U) >> (32 - (15))))) & 4294967295U) >> (32 - (15)))) ^ (((W00 ^ W07 ^ (((W13) << (15)) | (((W13) & 4294967295U) >> (32 - (15))))) << (23)) | (((W00 ^ W07 ^ (((W13) << (15)) | (((W13) & 4294967295U) >> (32 - (15))))) & 4294967295U) >> (32 - (23))))) ^ (((W03) << (7)) | (((W03) & 4294967295U) >> (32 - (7)))) ^ W10);

    if ((E ^ H) & 0x1) {
        const unsigned int A12 = (((B) << (12)) | (((B) & 4294967295U) >> (32 - (12))));
        const unsigned int A12_SM = A12 + F + 3462539467U;
        const unsigned int SS1 = (((A12_SM) << (7)) | (((A12_SM) & 4294967295U) >> (32 - (7))));
        const unsigned int TT1 = (B ^ C ^ D) + A + (SS1 ^ A12) + (W03 ^ W07);
        const unsigned int TT2 = (F ^ G ^ H) + E + SS1 + W03;
        C = (((C) << (9)) | (((C) & 4294967295U) >> (32 - (9))));
        A = TT1;
        G = (((G) << (19)) | (((G) & 4294967295U) >> (32 - (19))));
        E = (TT2 ^ (((TT2) << (9)) | (((TT2) & 4294967295U) >> (32 - (9)))) ^ (((TT2) << (17)) | (((TT2) & 4294967295U) >> (32 - (17)))));
    } else {
        const unsigned int A12 = (((A) << (12)) | (((A) & 4294967295U) >> (32 - (12))));
        const unsigned int A12_SM = A12 + E + 2630111639U;
        const unsigned int SS1 = (((A12_SM) << (7)) | (((A12_SM) & 4294967295U) >> (32 - (7))));
        const unsigned int TT1 = (A ^ B ^ C) + D + (SS1 ^ A12) + (W04 ^ W08);
        const unsigned int TT2 = (E ^ F ^ G) + H + SS1 + W04;
        B = (((B) << (9)) | (((B) & 4294967295U) >> (32 - (9))));
        D = TT1;
        F = (((F) << (19)) | (((F) & 4294967295U) >> (32 - (19))));
        H = (TT2 ^ (((TT2) << (9)) | (((TT2) & 4294967295U) >> (32 - (9)))) ^ (((TT2) << (17)) | (((TT2) & 4294967295U) >> (32 - (17)))));
    }

    W01 = ((W01 ^ W08 ^ (((W14) << (15)) | (((W14) & 4294967295U) >> (32 - (15)))) ^ (((W01 ^ W08 ^ (((W14) << (15)) | (((W14) & 4294967295U) >> (32 - (15))))) << (15)) | (((W01 ^ W08 ^ (((W14) << (15)) | (((W14) & 4294967295U) >> (32 - (15))))) & 4294967295U) >> (32 - (15)))) ^ (((W01 ^ W08 ^ (((W14) << (15)) | (((W14) & 4294967295U) >> (32 - (15))))) << (23)) | (((W01 ^ W08 ^ (((W14) << (15)) | (((W14) & 4294967295U) >> (32 - (15))))) & 4294967295U) >> (32 - (23))))) ^ (((W04) << (7)) | (((W04) & 4294967295U) >> (32 - (7)))) ^ W11);

    for (int i = 0; i < 2; ++i) {
        if (i == 0 && (W02 & 1)) continue;
        const unsigned int A12 = (((D) << (12)) | (((D) & 4294967295U) >> (32 - (12))));
        const unsigned int A12_SM = A12 + H + 965255983;
        const unsigned int SS1 = (((A12_SM) << (7)) | (((A12_SM) & 4294967295U) >> (32 - (7))));
        const unsigned int TT1 = (D ^ A ^ B) + C + (SS1 ^ A12) + (W05 ^ W09);
        const unsigned int TT2 = (H ^ E ^ F) + G + SS1 + W05;
        A = (((A) << (9)) | (((A) & 4294967295U) >> (32 - (9))));
        C = TT1;
        E = (((E) << (19)) | (((E) & 4294967295U) >> (32 - (19))));
        G = (TT2 ^ (((TT2) << (9)) | (((TT2) & 4294967295U) >> (32 - (9)))) ^ (((TT2) << (17)) | (((TT2) & 4294967295U) >> (32 - (17)))));
        break;
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
