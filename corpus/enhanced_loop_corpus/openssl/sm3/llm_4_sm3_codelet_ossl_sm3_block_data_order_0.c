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

    W00 = (((unsigned long)(*((data)++))) << 24);
    W00 |= (((unsigned long)(*((data)++))) << 16);
    W00 |= (((unsigned long)(*((data)++))) << 8);
    W00 |= (((unsigned long)(*((data)++))));

    W01 = (((unsigned long)(*((data)++))) << 24);
    W01 |= (((unsigned long)(*((data)++))) << 16);
    W01 |= (((unsigned long)(*((data)++))) << 8);
    W01 |= (((unsigned long)(*((data)++))));

    W02 = (((unsigned long)(*((data)++))) << 24);
    W02 |= (((unsigned long)(*((data)++))) << 16);
    W02 |= (((unsigned long)(*((data)++))) << 8);
    W02 |= (((unsigned long)(*((data)++))));

    W03 = (((unsigned long)(*((data)++))) << 24);
    W03 |= (((unsigned long)(*((data)++))) << 16);
    W03 |= (((unsigned long)(*((data)++))) << 8);
    W03 |= (((unsigned long)(*((data)++))));

    W04 = (((unsigned long)(*((data)++))) << 24);
    W04 |= (((unsigned long)(*((data)++))) << 16);
    W04 |= (((unsigned long)(*((data)++))) << 8);
    W04 |= (((unsigned long)(*((data)++))));

    W05 = (((unsigned long)(*((data)++))) << 24);
    W05 |= (((unsigned long)(*((data)++))) << 16);
    W05 |= (((unsigned long)(*((data)++))) << 8);
    W05 |= (((unsigned long)(*((data)++))));

    W06 = (((unsigned long)(*((data)++))) << 24);
    W06 |= (((unsigned long)(*((data)++))) << 16);
    W06 |= (((unsigned long)(*((data)++))) << 8);
    W06 |= (((unsigned long)(*((data)++))));

    W07 = (((unsigned long)(*((data)++))) << 24);
    W07 |= (((unsigned long)(*((data)++))) << 16);
    W07 |= (((unsigned long)(*((data)++))) << 8);
    W07 |= (((unsigned long)(*((data)++))));

    W08 = (((unsigned long)(*((data)++))) << 24);
    W08 |= (((unsigned long)(*((data)++))) << 16);
    W08 |= (((unsigned long)(*((data)++))) << 8);
    W08 |= (((unsigned long)(*((data)++))));

    W09 = (((unsigned long)(*((data)++))) << 24);
    W09 |= (((unsigned long)(*((data)++))) << 16);
    W09 |= (((unsigned long)(*((data)++))) << 8);
    W09 |= (((unsigned long)(*((data)++))));

    W10 = (((unsigned long)(*((data)++))) << 24);
    W10 |= (((unsigned long)(*((data)++))) << 16);
    W10 |= (((unsigned long)(*((data)++))) << 8);
    W10 |= (((unsigned long)(*((data)++))));

    W11 = (((unsigned long)(*((data)++))) << 24);
    W11 |= (((unsigned long)(*((data)++))) << 16);
    W11 |= (((unsigned long)(*((data)++))) << 8);
    W11 |= (((unsigned long)(*((data)++))));

    W12 = (((unsigned long)(*((data)++))) << 24);
    W12 |= (((unsigned long)(*((data)++))) << 16);
    W12 |= (((unsigned long)(*((data)++))) << 8);
    W12 |= (((unsigned long)(*((data)++))));

    W13 = (((unsigned long)(*((data)++))) << 24);
    W13 |= (((unsigned long)(*((data)++))) << 16);
    W13 |= (((unsigned long)(*((data)++))) << 8);
    W13 |= (((unsigned long)(*((data)++))));

    W14 = (((unsigned long)(*((data)++))) << 24);
    W14 |= (((unsigned long)(*((data)++))) << 16);
    W14 |= (((unsigned long)(*((data)++))) << 8);
    W14 |= (((unsigned long)(*((data)++))));

    W15 = (((unsigned long)(*((data)++))) << 24);
    W15 |= (((unsigned long)(*((data)++))) << 16);
    W15 |= (((unsigned long)(*((data)++))) << 8);
    W15 |= (((unsigned long)(*((data)++))));

    unsigned int temp_A = A, temp_B = B, temp_C = C, temp_D = D,
                 temp_E = E, temp_F = F, temp_G = G, temp_H = H;

    const unsigned int A12_1 = ((temp_A << 12) | (temp_A >> 20));
    const unsigned int A12_SM_1 = A12_1 + temp_E + 2043430169U;
    const unsigned int SS1_1 = ((A12_SM_1 << 7) | (A12_SM_1 >> 25));
    const unsigned int TT1_1 = (temp_A ^ temp_B ^ temp_C) + temp_D + (SS1_1 ^ A12_1) + (W00 ^ W04);
    const unsigned int TT2_1 = (temp_E ^ temp_F ^ temp_G) + temp_H + SS1_1 + W00;
    temp_B = (temp_B << 9) | (temp_B >> 23);
    temp_D = TT1_1;
    temp_F = (temp_F << 19) | (temp_F >> 13);
    temp_H = TT2_1 ^ ((TT2_1 << 9) | (TT2_1 >> 23)) ^ ((TT2_1 << 17) | (TT2_1 >> 15));

    W00 = ((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) ^
           (((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) << 15) | ((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) >> 17)) ^
           (((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) << 23) | ((W00 ^ W07 ^ ((W13 << 15) | (W13 >> 17))) >> 9))) ^
           ((W03 << 7) | (W03 >> 25)) ^ W10;

    const unsigned int A12_2 = ((temp_D << 12) | (temp_D >> 20));
    const unsigned int A12_SM_2 = A12_2 + temp_H + 4086860338U;
    const unsigned int SS1_2 = ((A12_SM_2 << 7) | (A12_SM_2 >> 25));
    const unsigned int TT1_2 = (temp_D ^ temp_A ^ temp_B) + temp_C + (SS1_2 ^ A12_2) + (W01 ^ W05);
    const unsigned int TT2_2 = (temp_H ^ temp_E ^ temp_F) + temp_G + SS1_2 + W01;
    temp_A = (temp_A << 9) | (temp_A >> 23);
    temp_C = TT1_2;
    temp_E = (temp_E << 19) | (temp_E >> 13);
    temp_G = TT2_2 ^ ((TT2_2 << 9) | (TT2_2 >> 23)) ^ ((TT2_2 << 17) | (TT2_2 >> 15));

    W01 = ((W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17))) ^
           (((W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17))) << 15) | ((W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17))) >> 17)) ^
           (((W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17))) << 23) | ((W01 ^ W08 ^ ((W14 << 15) | (W14 >> 17))) >> 9))) ^
           ((W04 << 7) | (W04 >> 25)) ^ W11;

    const unsigned int A12_3 = ((temp_C << 12) | (temp_C >> 20));
    const unsigned int A12_SM_3 = A12_3 + temp_G + 3878753381U;
    const unsigned int SS1_3 = ((A12_SM_3 << 7) | (A12_SM_3 >> 25));
    const unsigned int TT1_3 = (temp_C ^ temp_D ^ temp_A) + temp_B + (SS1_3 ^ A12_3) + (W02 ^ W06);
    const unsigned int TT2_3 = (temp_G ^ temp_H ^ temp_E) + temp_F + SS1_3 + W02;
    temp_D = (temp_D << 9) | (temp_D >> 23);
    temp_B = TT1_3;
    temp_H = (temp_H << 19) | (temp_H >> 13);
    temp_F = TT2_3 ^ ((TT2_3 << 9) | (TT2_3 >> 23)) ^ ((TT2_3 << 17) | (TT2_3 >> 15));

    W02 = ((W02 ^ W09 ^ ((W15 << 15) | (W15 >> 17))) ^
           (((W02 ^ W09 ^ ((W15 << 15) | (W15 >> 17))) << 15) | ((W02 ^ W09 ^ ((W15 << 15) | (W15 >> 17))) >> 17)) ^
           (((W02 ^ W09 ^ ((W15 << 15) | (W15 >> 17))) << 23) | ((W02 ^ W09 ^ ((W15 << 15) | (W15 >> 17))) >> 9))) ^
           ((W05 << 7) | (W05 >> 25)) ^ W12;

    const unsigned int A12_4 = ((temp_B << 12) | (temp_B >> 20));
    const unsigned int A12_SM_4 = A12_4 + temp_F + 3462539467U;
    const unsigned int SS1_4 = ((A12_SM_4 << 7) | (A12_SM_4 >> 25));
    const unsigned int TT1_4 = (temp_B ^ temp_C ^ temp_D) + temp_A + (SS1_4 ^ A12_4) + (W03 ^ W07);
    const unsigned int TT2_4 = (temp_F ^ temp_G ^ temp_H) + temp_E + SS1_4 + W03;
    temp_C = (temp_C << 9) | (temp_C >> 23);
    temp_A = TT1_4;
    temp_G = (temp_G << 19) | (temp_G >> 13);
    temp_E = TT2_4 ^ ((TT2_4 << 9) | (TT2_4 >> 23)) ^ ((TT2_4 << 17) | (TT2_4 >> 15));

    W03 = ((W03 ^ W10 ^ ((W00 << 15) | (W00 >> 17))) ^
           (((W03 ^ W10 ^ ((W00 << 15) | (W00 >> 17))) << 15) | ((W03 ^ W10 ^ ((W00 << 15) | (W00 >> 17))) >> 17)) ^
           (((W03 ^ W10 ^ ((W00 << 15) | (W00 >> 17))) << 23) | ((W03 ^ W10 ^ ((W00 << 15) | (W00 >> 17))) >> 9))) ^
           ((W06 << 7) | (W06 >> 25)) ^ W13;

    const unsigned int A12_5 = ((temp_A << 12) | (temp_A >> 20));
    const unsigned int A12_SM_5 = A12_5 + temp_E + 2630111639U;
    const unsigned int SS1_5 = ((A12_SM_5 << 7) | (A12_SM_5 >> 25));
    const unsigned int TT1_5 = (temp_A ^ temp_B ^ temp_C) + temp_D + (SS1_5 ^ A12_5) + (W04 ^ W08);
    const unsigned int TT2_5 = (temp_E ^ temp_F ^ temp_G) + temp_H + SS1_5 + W04;
    temp_B = (temp_B << 9) | (temp_B >> 23);
    temp_D = TT1_5;
    temp_F = (temp_F << 19) | (temp_F >> 13);
    temp_H = TT2_5 ^ ((TT2_5 << 9) | (TT2_5 >> 23)) ^ ((TT2_5 << 17) | (TT2_5 >> 15));

    W04 = ((W04 ^ W11 ^ ((W01 << 15) | (W01 >> 17))) ^
           (((W04 ^ W11 ^ ((W01 << 15) | (W01 >> 17))) << 15) | ((W04 ^ W11 ^ ((W01 << 15) | (W01 >> 17))) >> 17)) ^
           (((W04 ^ W11 ^ ((W01 << 15) | (W01 >> 17))) << 23) | ((W04 ^ W11 ^ ((W01 << 15) | (W01 >> 17))) >> 9))) ^
           ((W07 << 7) | (W07 >> 25)) ^ W14;

    const unsigned int A12_6 = ((temp_D << 12) | (temp_D >> 20));
    const unsigned int A12_SM_6 = A12_6 + temp_H + 965255983U;
    const unsigned int SS1_6 = ((A12_SM_6 << 7) | (A12_SM_6 >> 25));
    const unsigned int TT1_6 = (temp_D ^ temp_A ^ temp_B) + temp_C + (SS1_6 ^ A12_6) + (W05 ^ W09);
    const unsigned int TT2_6 = (temp_H ^ temp_E ^ temp_F) + temp_G + SS1_6 + W05;
    temp_A = (temp_A << 9) | (temp_A >> 23);
    temp_C = TT1_6;
    temp_E = (temp_E << 19) | (temp_E >> 13);
    temp_G = TT2_6 ^ ((TT2_6 << 9) | (TT2_6 >> 23)) ^ ((TT2_6 << 17) | (TT2_6 >> 15));

    W05 = ((W05 ^ W12 ^ ((W02 << 15) | (W02 >> 17))) ^
           (((W05 ^ W12 ^ ((W02 << 15) | (W02 >> 17))) << 15) | ((W05 ^ W12 ^ ((W02 << 15) | (W02 >> 17))) >> 17)) ^
           (((W05 ^ W12 ^ ((W02 << 15) | (W02 >> 17))) << 23) | ((W05 ^ W12 ^ ((W02 << 15) | (W02 >> 17))) >> 9))) ^
           ((W08 << 7) | (W08 >> 25)) ^ W15;

    const unsigned int A12_7 = ((temp_C << 12) | (temp_C >> 20));
    const unsigned int A12_SM_7 = A12_7 + temp_G + 1930511966U;
    const unsigned int SS1_7 = ((A12_SM_7 << 7) | (A12_SM_7 >> 25));
    const unsigned int TT1_7 = (temp_C ^ temp_D ^ temp_A) + temp_B + (SS1_7 ^ A12_7) + (W06 ^ W10);
    const unsigned int TT2_7 = (temp_G ^ temp_H ^ temp_E) + temp_F + SS1_7 + W06;
    temp_D = (temp_D << 9) | (temp_D >> 23);
    temp_B = TT1_7;
    temp_H = (temp_H << 19) | (temp_H >> 13);
    temp_F = TT2_7 ^ ((TT2_7 << 9) | (TT2_7 >> 23)) ^ ((TT2_7 << 17) | (TT2_7 >> 15));

    W06 = ((W06 ^ W13 ^ ((W03 << 15) | (W03 >> 17))) ^
           (((W06 ^ W13 ^ ((W03 << 15) | (W03 >> 17))) << 15) | ((W06 ^ W13 ^ ((W03 << 15) | (W03 >> 17))) >> 17)) ^
           (((W06 ^ W13 ^ ((W03 << 15) | (W03 >> 17))) << 23) | ((W06 ^ W13 ^ ((W03 << 15) | (W03 >> 17))) >> 9))) ^
           ((W09 << 7) | (W09 >> 25)) ^ W00;

    const unsigned int A12_8 = ((temp_B << 12) | (temp_B >> 20));
    const unsigned int A12_SM_8 = A12_8 + temp_F + 3861023932U;
    const unsigned int SS1_8 = ((A12_SM_8 << 7) | (A12_SM_8 >> 25));
    const unsigned int TT1_8 = (temp_B ^ temp_C ^ temp_D) + temp_A + (SS1_8 ^ A12_8) + (W07 ^ W11);
    const unsigned int TT2_8 = (temp_F ^ temp_G ^ temp_H) + temp_E + SS1_8 + W07;
    temp_C = (temp_C << 9) | (temp_C >> 23);
    temp_A = TT1_8;
    temp_G = (temp_G << 19) | (temp_G >> 13);
    temp_E = TT2_8 ^ ((TT2_8 << 9) | (TT2_8 >> 23)) ^ ((TT2_8 << 17) | (TT2_8 >> 15));

    W07 = ((W07 ^ W14 ^ ((W04 << 15) | (W04 >> 17))) ^
           (((W07 ^ W14 ^ ((W04 << 15) | (W04 >> 17))) << 15) | ((W07 ^ W14 ^ ((W04 << 15) | (W04 >> 17))) >> 17)) ^
           (((W07 ^ W14 ^ ((W04 << 15) | (W04 >> 17))) << 23) | ((W07 ^ W14 ^ ((W04 << 15) | (W04 >> 17))) >> 9))) ^
           ((W10 << 7) | (W10 >> 25)) ^ W01;

    const unsigned int A12_9 = ((temp_A << 12) | (temp_A >> 20));
    const unsigned int A12_SM_9 = A12_9 + temp_E + 3427080569U;
    const unsigned int SS1_9 = ((A12_SM_9 << 7) | (A12_SM_9 >> 25));
    const unsigned int TT1_9 = (temp_A ^ temp_B ^ temp_C) + temp_D + (SS1_9 ^ A12_9) + (W08 ^ W12);
    const unsigned int TT2_9 = (temp_E ^ temp_F ^ temp_G) + temp_H + SS1_9 + W08;
    temp_B = (temp_B << 9) | (temp_B >> 23);
    temp_D = TT1_9;
    temp_F = (temp_F << 19) | (temp_F >> 13);
    temp_H = TT2_9 ^ ((TT2_9 << 9) | (TT2_9 >> 23)) ^ ((TT2_9 << 17) | (TT2_9 >> 15));

    W08 = ((W08 ^ W15 ^ ((W05 << 15) | (W05 >> 17))) ^
           (((W08 ^ W15 ^ ((W05 << 15) | (W05 >> 17))) << 15) | ((W08 ^ W15 ^ ((W05 << 15) | (W05 >> 17))) >> 17)) ^
           (((W08 ^ W15 ^ ((W05 << 15) | (W05 >> 17))) << 23) | ((W08 ^ W15 ^ ((W05 << 15) | (W05 >> 17))) >> 9))) ^
           ((W11 << 7) | (W11 >> 25)) ^ W02;

    const unsigned int A12_10 = ((temp_D << 12) | (temp_D >> 20));
    const unsigned int A12_SM_10 = A12_10 + temp_H + 2559193843U;
    const unsigned int SS1_10 = ((A12_SM_10 << 7) | (A12_SM_10 >> 25));
    const unsigned int TT1_10 = (temp_D ^ temp_A ^ temp_B) + temp_C + (SS1_10 ^ A12_10) + (W09 ^ W13);
    const unsigned int TT2_10 = (temp_H ^ temp_E ^ temp_F) + temp_G + SS1_10 + W09;
    temp_A = (temp_A << 9) | (temp_A >> 23);
    temp_C = TT1_10;
    temp_E = (temp_E << 19) | (temp_E >> 13);
    temp_G = TT2_10 ^ ((TT2_10 << 9) | (TT2_10 >> 23)) ^ ((TT2_10 << 17) | (TT2_10 >> 15));

    W09 = ((W09 ^ W00 ^ ((W06 << 15) | (W06 >> 17))) ^
           (((W09 ^ W00 ^ ((W06 << 15) | (W06 >> 17))) << 15) | ((W09 ^ W00 ^ ((W06 << 15) | (W06 >> 17))) >> 17)) ^
           (((W09 ^ W00 ^ ((W06 << 15) | (W06 >> 17))) << 23) | ((W09 ^ W00 ^ ((W06 << 15) | (W06 >> 17))) >> 9))) ^
           ((W12 << 7) | (W12 >> 25)) ^ W03;

    const unsigned int A12_11 = ((temp_C << 12) | (temp_C >> 20));
    const unsigned int A12_SM_11 = A12_11 + temp_G + 823420391U;
    const unsigned int SS1_11 = ((A12_SM_11 << 7) | (A12_SM_11 >> 25));
    const unsigned int TT1_11 = (temp_C ^ temp_D ^ temp_A) + temp_B + (SS1_11 ^ A12_11) + (W10 ^ W14);
    const unsigned int TT2_11 = (temp_G ^ temp_H ^ temp_E) + temp_F + SS1_11 + W10;
    temp_D = (temp_D << 9) | (temp_D >> 23);
    temp_B = TT1_11;
    temp_H = (temp_H << 19) | (temp_H >> 13);
    temp_F = TT2_11 ^ ((TT2_11 << 9) | (TT2_11 >> 23)) ^ ((TT2_11 << 17) | (TT2_11 >> 15));

    W10 = ((W10 ^ W01 ^ ((W07 << 15) | (W07 >> 17))) ^
           (((W10 ^ W01 ^ ((W07 << 15) | (W07 >> 17))) << 15) | ((W10 ^ W01 ^ ((W07 << 15) | (W07 >> 17))) >> 17)) ^
           (((W10 ^ W01 ^ ((W07 << 15) | (W07 >> 17))) << 23) | ((W10 ^ W01 ^ ((W07 << 15) | (W07 >> 17))) >> 9))) ^
           ((W13 << 7) | (W13 >> 25)) ^ W04;

    const unsigned int A12_12 = ((temp_B << 12) | (temp_B >> 20));
    const unsigned int A12_SM_12 = A12_12 + temp_F + 1646840782U;
    const unsigned int SS1_12 = ((A12_SM_12 << 7) | (A12_SM_12 >> 25));
    const unsigned int TT1_12 = (temp_B ^ temp_C ^ temp_D) + temp_A + (SS1_12 ^ A12_12) + (W11 ^ W15);
    const unsigned int TT2_12 = (temp_F ^ temp_G ^ temp_H) + temp_E + SS1_12 + W11;
    temp_C = (temp_C << 9) | (temp_C >> 23);
    temp_A = TT1_12;
    temp_G = (temp_G << 19) | (temp_G >> 13);
    temp_E = TT2_12 ^ ((TT2_12 << 9) | (TT2_12 >> 23)) ^ ((TT2_12 << 17) | (TT2_12 >> 15));

    W11 = ((W11 ^ W02 ^ ((W08 << 15) | (W08 >> 17))) ^
           (((W11 ^ W02 ^ ((W08 << 15) | (W08 >> 17))) << 15) | ((W11 ^ W02 ^ ((W08 << 15) | (W08 >> 17))) >> 17)) ^
           (((W11 ^ W02 ^ ((W08 << 15) | (W08 >> 17))) << 23) | ((W11 ^ W02 ^ ((W08 << 15) | (W08 >> 17))) >> 9))) ^
           ((W14 << 7) | (W14 >> 25)) ^ W05;

    const unsigned int A12_13 = ((temp_A << 12) | (temp_A >> 20));
    const unsigned int A12_SM_13 = A12_13 + temp_E + 3293681564U;
    const unsigned int SS1_13 = ((A12_SM_13 << 7) | (A12_SM_13 >> 25));
    const unsigned int TT1_13 = (temp_A ^ temp_B ^ temp_C) + temp_D + (SS1_13 ^ A12_13) + (W12 ^ W00);
    const unsigned int TT2_13 = (temp_E ^ temp_F ^ temp_G) + temp_H + SS1_13 + W12;
    temp_B = (temp_B << 9) | (temp_B >> 23);
    temp_D = TT1_13;
    temp_F = (temp_F << 19) | (temp_F >> 13);
    temp_H = TT2_13 ^ ((TT2_13 << 9) | (TT2_13 >> 23)) ^ ((TT2_13 << 17) | (TT2_13 >> 15));

    W12 = ((W12 ^ W03 ^ ((W09 << 15) | (W09 >> 17))) ^
           (((W12 ^ W03 ^ ((W09 << 15) | (W09 >> 17))) << 15) | ((W12 ^ W03 ^ ((W09 << 15) | (W09 >> 17))) >> 17)) ^
           (((W12 ^ W03 ^ ((W09 << 15) | (W09 >> 17))) << 23) | ((W12 ^ W03 ^ ((W09 << 15) | (W09 >> 17))) >> 9))) ^
           ((W15 << 7) | (W15 >> 25)) ^ W06;

    const unsigned int A12_14 = ((temp_D << 12) | (temp_D >> 20));
    const unsigned int A12_SM_14 = A12_14 + temp_H + 2292395833U;
    const unsigned int SS1_14 = ((A12_SM_14 << 7) | (A12_SM_14 >> 25));
    const unsigned int TT1_14 = (temp_D ^ temp_A ^ temp_B) + temp_C + (SS1_14 ^ A12_14) + (W13 ^ W01);
    const unsigned int TT2_14 = (temp_H ^ temp_E ^ temp_F) + temp_G + SS1_14 + W13;
    temp_A = (temp_A << 9) | (temp_A >> 23);
    temp_C = TT1_14;
    temp_E = (temp_E << 19) | (temp_E >> 13);
    temp_G = TT2_14 ^ ((TT2_14 << 9) | (TT2_14 >> 23)) ^ ((TT2_14 << 17) | (TT2_14 >> 15));

    W13 = ((W13 ^ W04 ^ ((W10 << 15) | (W10 >> 17))) ^
           (((W13 ^ W04 ^ ((W10 << 15) | (W10 >> 17))) << 15) | ((W13 ^ W04 ^ ((W10 << 15) | (W10 >> 17))) >> 17)) ^
           (((W13 ^ W04 ^ ((W10 << 15) | (W10 >> 17))) << 23) | ((W13 ^ W04 ^ ((W10 << 15) | (W10 >> 17))) >> 9))) ^
           ((W00 << 7) | (W00 >> 25)) ^ W07;

    const unsigned int A12_15 = ((temp_C << 12) | (temp_C >> 20));
    const unsigned int A12_SM_15 = A12_15 + temp_G + 289824371U;
    const unsigned int SS1_15 = ((A12_SM_15 << 7) | (A12_SM_15 >> 25));
    const unsigned int TT1_15 = (temp_C ^ temp_D ^ temp_A) + temp_B + (SS1_15 ^ A12_15) + (W14 ^ W02);
    const unsigned int TT2_15 = (temp_G ^ temp_H ^ temp_E) + temp_F + SS1_15 + W14;
    temp_D = (temp_D << 9) | (temp_D >> 23);
    temp_B = TT1_15;
    temp_H = (temp_H << 19) | (temp_H >> 13);
    temp_F = TT2_15 ^ ((TT2_15 << 9) | (TT2_15 >> 23)) ^ ((TT2_15 << 17) | (TT2_15 >> 15));

    W14 = ((W14 ^ W05 ^ ((W11 << 15) | (W11 >> 17))) ^
           (((W14 ^ W05 ^ ((W11 << 15) | (W11 >> 17))) << 15) | ((W14 ^ W05 ^ ((W11 << 15) | (W11 >> 17))) >> 17)) ^
           (((W14 ^ W05 ^ ((W11 << 15) | (W11 >> 17))) << 23) | ((W14 ^ W05 ^ ((W11 << 15) | (W11 >> 17))) >> 9))) ^
           ((W01 << 7) | (W01 >> 25)) ^ W08;

    const unsigned int A12_16 = ((temp_B << 12) | (temp_B >> 20));
    const unsigned int A12_SM_16 = A12_16 + temp_F + 579648742U;
    const unsigned int SS1_16 = ((A12_SM_16 << 7) | (A12_SM_16 >> 25));
    const unsigned int TT1_16 = (temp_B ^ temp_C ^ temp_D) + temp_A + (SS1_16 ^ A12_16) + (W15 ^ W03);
    const unsigned int TT2_16 = (temp_F ^ temp_G ^ temp_H) + temp_E + SS1_16 + W15;
    temp_C = (temp_C << 9) | (temp_C >> 23);
    temp_A = TT1_16;
    temp_G = (temp_G << 19) | (temp_G >> 13);
    temp_E = TT2_16 ^ ((TT2_16 << 9) | (TT2_16 >> 23)) ^ ((TT2_16 << 17) | (TT2_16 >> 15));

    W15 = ((W15 ^ W06 ^ ((W12 << 15) | (W12 >> 17))) ^
           (((W15 ^ W06 ^ ((W12 << 15) | (W12 >> 17))) << 15) | ((W15 ^ W06 ^ ((W12 << 15) | (W12 >> 17))) >> 17)) ^
           (((W15 ^ W06 ^ ((W12 << 15) | (W12 >> 17))) << 23) | ((W15 ^ W06 ^ ((W12 << 15) | (W12 >> 17))) >> 9))) ^
           ((W02 << 7) | (W02 >> 25)) ^ W09;

    ctx->A ^= temp_A;
    ctx->B ^= temp_B;
    ctx->C ^= temp_C;
    ctx->D ^= temp_D;
    ctx->E ^= temp_E;
    ctx->F ^= temp_F;
    ctx->G ^= temp_G;
    ctx->H ^= temp_H;
}
}
