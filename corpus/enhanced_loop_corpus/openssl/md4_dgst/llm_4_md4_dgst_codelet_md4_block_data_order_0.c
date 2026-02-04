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

        if ((XX0 & 1)) {
            A += ((XX0) + (0) + (((((C)) ^ ((D))) & ((B))) ^ ((D))));
            A = (((A) << (3)) | (((A) & 4294967295U) >> (32 - (3))));
        } else {
            D += ((XX1) + (0) + (((((B)) ^ ((C))) & ((A))) ^ ((C))));
            D = (((D) << (7)) | (((D) & 4294967295U) >> (32 - (7))));
        }

        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX2 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX3 = l;

        if ((XX2 & 1)) {
            C += ((XX2) + (0) + (((((A)) ^ ((B))) & ((D))) ^ ((B))));
            C = (((C) << (11)) | (((C) & 4294967295U) >> (32 - (11))));
        } else {
            B += ((XX3) + (0) + (((((D)) ^ ((A))) & ((C))) ^ ((A))));
            B = (((B) << (19)) | (((B) & 4294967295U) >> (32 - (19))));
        }

        for (int i = 4; i < 16; i++) {
            (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
            switch(i) {
                case 4: XX4 = l; A += ((XX4) + (0) + (((((C)) ^ ((D))) & ((B))) ^ ((D)))); A = (((A) << (3)) | (((A) & 4294967295U) >> (32 - (3)))); break;
                case 5: XX5 = l; D += ((XX5) + (0) + (((((B)) ^ ((C))) & ((A))) ^ ((C)))); D = (((D) << (7)) | (((D) & 4294967295U) >> (32 - (7)))); break;
                case 6: XX6 = l; C += ((XX6) + (0) + (((((A)) ^ ((B))) & ((D))) ^ ((B)))); C = (((C) << (11)) | (((C) & 4294967295U) >> (32 - (11)))); break;
                case 7: XX7 = l; B += ((XX7) + (0) + (((((D)) ^ ((A))) & ((C))) ^ ((A)))); B = (((B) << (19)) | (((B) & 4294967295U) >> (32 - (19)))); break;
                case 8: XX8 = l; A += ((XX8) + (0) + (((((C)) ^ ((D))) & ((B))) ^ ((D)))); A = (((A) << (3)) | (((A) & 4294967295U) >> (32 - (3)))); break;
                case 9: XX9 = l; D += ((XX9) + (0) + (((((B)) ^ ((C))) & ((A))) ^ ((C)))); D = (((D) << (7)) | (((D) & 4294967295U) >> (32 - (7)))); break;
                case 10: XX10 = l; C += ((XX10) + (0) + (((((A)) ^ ((B))) & ((D))) ^ ((B)))); C = (((C) << (11)) | (((C) & 4294967295U) >> (32 - (11)))); break;
                case 11: XX11 = l; B += ((XX11) + (0) + (((((D)) ^ ((A))) & ((C))) ^ ((A)))); B = (((B) << (19)) | (((B) & 4294967295U) >> (32 - (19)))); break;
                case 12: XX12 = l; A += ((XX12) + (0) + (((((C)) ^ ((D))) & ((B))) ^ ((D)))); A = (((A) << (3)) | (((A) & 4294967295U) >> (32 - (3)))); break;
                case 13: XX13 = l; D += ((XX13) + (0) + (((((B)) ^ ((C))) & ((A))) ^ ((C)))); D = (((D) << (7)) | (((D) & 4294967295U) >> (32 - (7)))); break;
                case 14: XX14 = l; C += ((XX14) + (0) + (((((A)) ^ ((B))) & ((D))) ^ ((B)))); C = (((C) << (11)) | (((C) & 4294967295U) >> (32 - (11)))); break;
                case 15: XX15 = l; B += ((XX15) + (0) + (((((D)) ^ ((A))) & ((C))) ^ ((A)))); B = (((B) << (19)) | (((B) & 4294967295U) >> (32 - (19)))); break;
            }
        }

        if ((A & 1)) {
            A += ((XX0) + (1518500249L) + ((((B)) & ((C))) | (((B)) & ((D))) | (((C)) & ((D)))));
            A = (((A) << (3)) | (((A) & 4294967295U) >> (32 - (3))));
        }
        if ((D & 1)) {
            D += ((XX4) + (1518500249L) + ((((A)) & ((B))) | (((A)) & ((C))) | (((B)) & ((C)))));
            D = (((D) << (5)) | (((D) & 4294967295U) >> (32 - (5))));
        }

        C += ((XX8) + (1518500249L) + ((((D)) & ((A))) | (((D)) & ((B))) | (((A)) & ((B)))));
        C = (((C) << (9)) | (((C) & 4294967295U) >> (32 - (9))));

        B += ((XX12) + (1518500249L) + ((((C)) & ((D))) | (((C)) & ((A))) | (((D)) & ((A)))));
        B = (((B) << (13)) | (((B) & 4294967295U) >> (32 - (13))));

        A = c->A += A;
        B = c->B += B;
        C = c->C += C;
        D = c->D += D;
    }
}
