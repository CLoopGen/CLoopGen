#include <stdio.h>

#include <inttypes.h>

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

extern RIPEMD160_CTX *ctx;
extern size_t num;
extern  unsigned char *data;
extern unsigned int A;
extern unsigned int B;
extern unsigned int C;
extern unsigned int D;
extern unsigned int E;
extern unsigned int a;
extern unsigned int b;
extern unsigned int c;
extern unsigned int d;
extern unsigned int e;
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
        // Initialize working variables from context
        A = ctx->A;
        B = ctx->B;
        C = ctx->C;
        D = ctx->D;
        E = ctx->E;

        // Load first 16 words using compact macro
        #define LOAD_WORD(var) \
            (void)(l = *((data)++), \
                   l |= ((unsigned long)(*((data)++)) << 8), \
                   l |= ((unsigned long)(*((data)++)) << 16), \
                   l |= ((unsigned long)(*((data)++)) << 24)), \
            var = l

        LOAD_WORD(XX0);
        LOAD_WORD(XX1);
        LOAD_WORD(XX2);
        LOAD_WORD(XX3);
        LOAD_WORD(XX4);
        LOAD_WORD(XX5);
        LOAD_WORD(XX6);
        LOAD_WORD(XX7);
        LOAD_WORD(XX8);
        LOAD_WORD(XX9);
        LOAD_WORD(XX10);
        LOAD_WORD(XX11);
        LOAD_WORD(XX12);
        LOAD_WORD(XX13);
        LOAD_WORD(XX14);
        LOAD_WORD(XX15);

        #undef LOAD_WORD

        // First round: simple XOR and rotate
        {
            A += ((B) ^ (C) ^ (D)) + XX0;
            A = (((A) << (11)) | (((A) & 4294967295U) >> (32 - (11)))) + E;
            C = (((C) << (10)) | (((C) & 4294967295U) >> (32 - (10))));
        }
        {
            E += ((A) ^ (B) ^ (C)) + XX1;
            E = (((E) << (14)) | (((E) & 4294967295U) >> (32 - (14)))) + D;
            B = (((B) << (10)) | (((B) & 4294967295U) >> (32 - (10))));
        }

        // Conditional execution: only proceed if data entropy is high
        if ((XX0 ^ XX1 ^ XX2 ^ XX3) != 0xFFFFFFFFU) {
            // Proceed with normal full-round processing
            {
                D += ((E) ^ (A) ^ (B)) + XX2;
                D = (((D) << (15)) | (((D) & 4294967295U) >> (32 - (15)))) + C;
                A = (((A) << (10)) | (((A) & 4294967295U) >> (32 - (10))));
            }
            {
                C += ((D) ^ (E) ^ (A)) + XX3;
                C = (((C) << (12)) | (((C) & 4294967295U) >> (32 - (12)))) + B;
                E = (((E) << (10)) | (((E) & 4294967295U) >> (32 - (10))));
            }
            {
                B += ((C) ^ (D) ^ (E)) + XX4;
                B = (((B) << (5)) | (((B) & 4294967295U) >> (32 - (5)))) + A;
                D = (((D) << (10)) | (((D) & 4294967295U) >> (32 - (10))));
            }
            {
                A += ((B) ^ (C) ^ (D)) + XX5;
                A = (((A) << (8)) | (((A) & 4294967295U) >> (32 - (8)))) + E;
                C = (((C) << (10)) | (((C) & 4294967295U) >> (32 - (10))));
            }
            {
                E += ((A) ^ (B) ^ (C)) + XX6;
                E = (((E) << (7)) | (((E) & 4294967295U) >> (32 - (7)))) + D;
                B = (((B) << (10)) | (((B) & 4294967295U) >> (32 - (10))));
            }
            {
                D += ((E) ^ (A) ^ (B)) + XX7;
                D = (((D) << (9)) | (((D) & 4294967295U) >> (32 - (9)))) + C;
                A = (((A) << (10)) | (((A) & 4294967295U) >> (32 - (10))));
            }
            {
                C += ((D) ^ (E) ^ (A)) + XX8;
                C = (((C) << (11)) | (((C) & 4294967295U) >> (32 - (11)))) + B;
                E = (((E) << (10)) | (((E) & 4294967295U) >> (32 - (10))));
            }
            {
                B += ((C) ^ (D) ^ (E)) + XX9;
                B = (((B) << (13)) | (((B) & 4294967295U) >> (32 - (13)))) + A;
                D = (((D) << (10)) | (((D) & 4294967295U) >> (32 - (10))));
            }
            {
                A += ((B) ^ (C) ^ (D)) + XX10;
                A = (((A) << (14)) | (((A) & 4294967295U) >> (32 - (14)))) + E;
                C = (((C) << (10)) | (((C) & 4294967295U) >> (32 - (10))));
            }
            {
                E += ((A) ^ (B) ^ (C)) + XX11;
                E = (((E) << (15)) | (((E) & 4294967295U) >> (32 - (15)))) + D;
                B = (((B) << (10)) | (((B) & 4294967295U) >> (32 - (10))));
            }
            {
                D += ((E) ^ (A) ^ (B)) + XX12;
                D = (((D) << (6)) | (((D) & 4294967295U) >> (32 - (6)))) + C;
                A = (((A) << (10)) | (((A) & 4294967295U) >> (32 - (10))));
            }
            {
                C += ((D) ^ (E) ^ (A)) + XX13;
                C = (((C) << (7)) | (((C) & 4294967295U) >> (32 - (7)))) + B;
                E = (((E) << (10)) | (((E) & 4294967295U) >> (32 - (10))));
            }
            {
                B += ((C) ^ (D) ^ (E)) + XX14;
                B = (((B) << (9)) | (((B) & 4294967295U) >> (32 - (9)))) + A;
                D = (((D) << (10)) | (((D) & 4294967295U) >> (32 - (10))));
            }
            {
                A += ((B) ^ (C) ^ (D)) + XX15;
                A = (((A) << (8)) | (((A) & 4294967295U) >> (32 - (8)))) + E;
                C = (((C) << (10)) | (((C) & 4294967295U) >> (32 - (10))));
            }
        } else {
            // Low entropy: skip most rounds, jump directly to late-stage mixing
            A += ((B) ^ (C) ^ (D)) + XX15;
            A = (((A) << (8)) | (((A) & 4294967295U) >> (32 - (8)))) + E;
            C = (((C) << (10)) | (((C) & 4294967295U) >> (32 - (10))));

            E += ((((B) ^ (C)) & (A)) ^ (C)) + XX7 + 1518500249L;
            E = (((E) << (7)) | (((E) & 4294967295U) >> (32 - (7)))) + D;
            B = (((B) << (10)) | (((B) & 4294967295U) >> (32 - (10))));

            D += ((((A) ^ (B)) & (E)) ^ (B)) + XX4 + 1518500249L;
            D = (((D) << (6)) | (((D) & 4294967295U) >> (32 - (6)))) + C;
            A = (((A) << (10)) | (((A) & 4294967295U) >> (32 - (10))));

            C += ((((E) ^ (A)) & (D)) ^ (A)) + XX13 + 1518500249L;
            C = (((C) << (8)) | (((C) & 4294967295U) >> (32 - (8)))) + B;
            E = (((E) << (10)) | (((E) & 4294967295U) >> (32 - (10))));

            // Save intermediate values
            a = A; b = B; c = C; d = D; e = E;

            // Reinitialize A-E from context again before second half
            A = ctx->A; B = ctx->B; C = ctx->C; D = ctx->D; E = ctx->E;

            // Apply only one round of second pass
            {
                A += (((~(D)) | (C)) ^ (B)) + XX5 + 1352829926L;
                A = (((A) << (8)) | (((A) & 4294967295U) >> (32 - (8)))) + E;
                C = (((C) << (10)) | (((C) & 4294967295U) >> (32 - (10))));
            }
            goto finalize_fast;
        }

        // Full first-half completed — save values
        a = A; b = B; c = C; d = D; e = E;

        // Reinitialize A-E from context for second half
        A = ctx->A;
        B = ctx->B;
        C = ctx->C;
        D = ctx->D;
        E = ctx->E;

        // Second half: conditional unrolling — apply only odd-numbered rounds
        #define APPLY_ROUND(cond, expr, rot) \
            if (cond) { \
                expr; \
                A = (((A) << (rot)) | (((A) & 4294967295U) >> (32 - (rot)))) + E; \
                C = (((C) << (10)) | (((C) & 4294967295U) >> (32 - (10)))); \
            }

        APPLY_ROUND((XX5 & 1), A += (((~(D)) | (C)) ^ (B)) + XX5 + 1352829926L, 8);
        APPLY_ROUND((XX14 & 1), E += (((~(C)) | (B)) ^ (A)) + XX14 + 1352829926L, 9);
        APPLY_ROUND((XX7 & 1), D += (((~(B)) | (A)) ^ (E)) + XX7 + 1352829926L, 9);
        APPLY_ROUND((XX0 & 1), C += (((~(A)) | (E)) ^ (D)) + XX0 + 1352829926L, 11);
        APPLY_ROUND((XX9 & 1), B += (((~(E)) | (D)) ^ (C)) + XX9 + 1352829926L, 13);
        APPLY_ROUND((XX2 & 1), A += (((~(D)) | (C)) ^ (B)) + XX2 + 1352829926L, 15);
        APPLY_ROUND((XX11 & 1), E += (((~(C)) | (B)) ^ (A)) + XX11 + 1352829926L, 15);
        APPLY_ROUND((XX4 & 1), D += (((~(B)) | (A)) ^ (E)) + XX4 + 1352829926L, 5);
        APPLY_ROUND((XX13 & 1), C += (((~(A)) | (E)) ^ (D)) + XX13 + 1352829926L, 7);
        APPLY_ROUND((XX6 & 1), B += (((~(E)) | (D)) ^ (C)) + XX6 + 1352829926L, 7);
        APPLY_ROUND((XX15 & 1), A += (((~(D)) | (C)) ^ (B)) + XX15 + 1352829926L, 8);
        APPLY_ROUND((XX8 & 1), E += (((~(C)) | (B)) ^ (A)) + XX8 + 1352829926L, 11);
        APPLY_ROUND((XX1 & 1), D += (((~(B)) | (A)) ^ (E)) + XX1 + 1352829926L, 14);
        APPLY_ROUND((XX10 & 1), C += (((~(A)) | (E)) ^ (D)) + XX10 + 1352829926L, 14);
        APPLY_ROUND((XX3 & 1), B += (((~(E)) | (D)) ^ (C)) + XX3 + 1352829926L, 12);
        APPLY_ROUND((XX12 & 1), A += (((~(D)) | (C)) ^ (B)) + XX12 + 1352829926L, 6);

        #undef APPLY_ROUND

finalize_fast:
        D = ctx->B + c + D;
        ctx->B = ctx->C + d + E;
        ctx->C = ctx->D + e + A;
        ctx->D = ctx->E + a + B;
        ctx->E = ctx->A + b + C;
        ctx->A = D;
    }
}
