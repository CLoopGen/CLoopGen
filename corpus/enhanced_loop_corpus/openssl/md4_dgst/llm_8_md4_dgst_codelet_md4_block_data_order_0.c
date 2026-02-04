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
    for (; num--; ) {
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX0 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX1 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX2 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX3 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX4 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX5 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX6 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX7 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX8 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX9 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX10 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX11 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX12 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX13 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX14 = l;
        (void)(l = (((unsigned long)(*((data)++)))) , l |= (((unsigned long)(*((data)++))) << 8) , l |= (((unsigned long)(*((data)++))) << 16) , l |= (((unsigned long)(*((data)++))) << 24));
        XX15 = l;

        // Unroll and combine first round with simplified operations
        A += XX0 + ((((C) ^ D) & B) ^ D); A = (A << 3) | (A >> 29);
        D += XX1 + ((((B) ^ C) & A) ^ C); D = (D << 7) | (D >> 25);
        C += XX2 + ((((A) ^ B) & D) ^ B); C = (C << 11) | (C >> 21);
        B += XX3 + ((((D) ^ A) & C) ^ A); B = (B << 19) | (B >> 13);

        A += XX4 + ((((C) ^ D) & B) ^ D); A = (A << 3) | (A >> 29);
        D += XX5 + ((((B) ^ C) & A) ^ C); D = (D << 7) | (D >> 25);
        C += XX6 + ((((A) ^ B) & D) ^ B); C = (C << 11) | (C >> 21);
        B += XX7 + ((((D) ^ A) & C) ^ A); B = (B << 19) | (B >> 13);

        A += XX8 + ((((C) ^ D) & B) ^ D); A = (A << 3) | (A >> 29);
        D += XX9 + ((((B) ^ C) & A) ^ C); D = (D << 7) | (D >> 25);
        C += XX10 + ((((A) ^ B) & D) ^ B); C = (C << 11) | (C >> 21);
        B += XX11 + ((((D) ^ A) & C) ^ A); B = (B << 19) | (B >> 13);

        A += XX12 + ((((C) ^ D) & B) ^ D); A = (A << 3) | (A >> 29);
        D += XX13 + ((((B) ^ C) & A) ^ C); D = (D << 7) | (D >> 25);
        C += XX14 + ((((A) ^ B) & D) ^ B); C = (C << 11) | (C >> 21);
        B += XX15 + ((((D) ^ A) & C) ^ A); B = (B << 19) | (B >> 13);

        // Second round: reduce redundant macro expansions and group common patterns
        #define ROUND2(x, v, s) x += v + 1518500249UL + ((x & (x ^ ~0U)) | (x & x) | ((x ^ ~0U) & x)); x = (x << s) | (x >> (32 - s))
        ROUND2(A, XX0, 3); ROUND2(D, XX4, 5); ROUND2(C, XX8, 9); ROUND2(B, XX12, 13);
        ROUND2(A, XX1, 3); ROUND2(D, XX5, 5); ROUND2(C, XX9, 9); ROUND2(B, XX13, 13);
        ROUND2(A, XX2, 3); ROUND2(D, XX6, 5); ROUND2(C, XX10, 9); ROUND2(B, XX14, 13);
        ROUND2(A, XX3, 3); ROUND2(D, XX7, 5); ROUND2(C, XX11, 9); ROUND2(B, XX15, 13);
        #undef ROUND2

        // Third round: use direct XOR without intermediate grouping
        #define ROUND3(x, y, v, s) x += v + 1859775393UL + (y); x = (x << s) | (x >> (32 - s))
        ROUND3(A, B^C^D, XX0, 3); ROUND3(D, A^B^C, XX8, 9);
        ROUND3(C, D^A^B, XX4, 11); ROUND3(B, C^D^A, XX12, 15);
        ROUND3(A, B^C^D, XX2, 3); ROUND3(D, A^B^C, XX10, 9);
        ROUND3(C, D^A^B, XX6, 11); ROUND3(B, C^D^A, XX14, 15);
        ROUND3(A, B^C^D, XX1, 3); ROUND3(D, A^B^C, XX9, 9);
        ROUND3(C, D^A^B, XX5, 11); ROUND3(B, C^D^A, XX13, 15);
        ROUND3(A, B^C^D, XX3, 3); ROUND3(D, A^B^C, XX11, 9);
        ROUND3(C, D^A^B, XX7, 11); ROUND3(B, C^D^A, XX15, 15);
        #undef ROUND3

        c->A += A; c->B += B; c->C += C; c->D += D;
    }
}
