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
        unsigned int temp_A = A, temp_B = B, temp_C = C, temp_D = D;

        for (int i = 0; i < 16; i += 4) {
            (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
            switch(i) {
                case 0:  XX0 = l; if (l % 2 == 0) { temp_A += (XX0 + 0 + (((temp_C ^ temp_D) & temp_B) ^ temp_D)); temp_A = ((temp_A << 3) | ((temp_A & 4294967295U) >> 29)); } break;
                case 4:  XX1 = l; if (l % 2 == 1) { temp_D += (XX1 + 0 + (((temp_B ^ temp_C) & temp_A) ^ temp_C)); temp_D = ((temp_D << 7) | ((temp_D & 4294967295U) >> 25)); } break;
                case 8:  XX2 = l; if (l > 0x80000000U) { temp_C += (XX2 + 0 + (((temp_A ^ temp_B) & temp_D) ^ temp_B)); temp_C = ((temp_C << 11) | ((temp_C & 4294967295U) >> 21)); } break;
                case 12: XX3 = l; if (l < 0x7FFFFFFFU) { temp_B += (XX3 + 0 + (((temp_D ^ temp_A) & temp_C) ^ temp_A)); temp_B = ((temp_B << 19) | ((temp_B & 4294967295U) >> 13)); } break;
                default:
                    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
                    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
                    (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
                    break;
            }
        }

        data += 48;

        if ((temp_A + temp_B + temp_C + temp_D) & 1) {
            temp_A += (XX0 + 1518500249L + ((temp_B & temp_C) | (temp_B & temp_D) | (temp_C & temp_D)));
            temp_A = ((temp_A << 3) | ((temp_A & 4294967295U) >> 29));
            temp_D += (XX4 + 1518500249L + ((temp_A & temp_B) | (temp_A & temp_C) | (temp_B & temp_C)));
            temp_D = ((temp_D << 5) | ((temp_D & 4294967295U) >> 27));
        } else {
            temp_C += (XX8 + 1859775393L + (temp_D ^ temp_A ^ temp_B));
            temp_C = ((temp_C << 11) | ((temp_C & 4294967295U) >> 21));
            temp_B += (XX12 + 1859775393L + (temp_C ^ temp_D ^ temp_A));
            temp_B = ((temp_B << 15) | ((temp_B & 4294967295U) >> 17));
        }

        A = c->A += temp_A;
        B = c->B += temp_B;
        C = c->C += temp_C;
        D = c->D += temp_D;
    }
}
