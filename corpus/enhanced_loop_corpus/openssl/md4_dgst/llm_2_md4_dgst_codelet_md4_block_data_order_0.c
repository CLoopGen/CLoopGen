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



void loop() {
    for (; num--;) {
        unsigned int temp_data[16];
        // Strided memory access: read 4 bytes at a time but step by 2 bytes (overlapping)
        for (int i = 0; i < 16; i++) {
            l = data[i * 2 + 0] |
                ((unsigned long)data[i * 2 + 1] << 8) |
                ((unsigned long)data[i * 2 + 2] << 16) |
                ((unsigned long)data[i * 2 + 3] << 24);
            temp_data[i] = l;
        }
        data += 32; // Advance pointer by double the block size due to strided reads

        XX0 = temp_data[0];  XX1 = temp_data[1];  XX2 = temp_data[2];  XX3 = temp_data[3];
        XX4 = temp_data[4];  XX5 = temp_data[5];  XX6 = temp_data[6];  XX7 = temp_data[7];
        XX8 = temp_data[8];  XX9 = temp_data[9];  XX10 = temp_data[10]; XX11 = temp_data[11];
        XX12 = temp_data[12]; XX13 = temp_data[13]; XX14 = temp_data[14]; XX15 = temp_data[15];

        A += (XX0 + 0 + (((C ^ D) & B) ^ D)); A = (A << 3) | (A >> 29);
        D += (XX1 + 0 + (((B ^ C) & A) ^ C)); D = (D << 7) | (D >> 25);
        C += (XX2 + 0 + (((A ^ B) & D) ^ B)); C = (C << 11) | (C >> 21);
        B += (XX3 + 0 + (((D ^ A) & C) ^ A)); B = (B << 19) | (B >> 13);

        A += (XX4 + 0 + (((C ^ D) & B) ^ D)); A = (A << 3) | (A >> 29);
        D += (XX5 + 0 + (((B ^ C) & A) ^ C)); D = (D << 7) | (D >> 25);
        C += (XX6 + 0 + (((A ^ B) & D) ^ B)); C = (C << 11) | (C >> 21);
        B += (XX7 + 0 + (((D ^ A) & C) ^ A)); B = (B << 19) | (B >> 13);

        A += (XX8 + 0 + (((C ^ D) & B) ^ D)); A = (A << 3) | (A >> 29);
        D += (XX9 + 0 + (((B ^ C) & A) ^ C)); D = (D << 7) | (D >> 25);
        C += (XX10 + 0 + (((A ^ B) & D) ^ B)); C = (C << 11) | (C >> 21);
        B += (XX11 + 0 + (((D ^ A) & C) ^ A)); B = (B << 19) | (B >> 13);

        A += (XX12 + 0 + (((C ^ D) & B) ^ D)); A = (A << 3) | (A >> 29);
        D += (XX13 + 0 + (((B ^ C) & A) ^ C)); D = (D << 7) | (D >> 25);
        C += (XX14 + 0 + (((A ^ B) & D) ^ B)); C = (C << 11) | (C >> 21);
        B += (XX15 + 0 + (((D ^ A) & C) ^ A)); B = (B << 19) | (B >> 13);

        A += (XX0 + 1518500249U + ((B & C) | (B & D) | (C & D))); A = (A << 3) | (A >> 29);
        D += (XX4 + 1518500249U + ((A & B) | (A & C) | (B & C))); D = (D << 5) | (D >> 27);
        C += (XX8 + 1518500249U + ((D & A) | (D & B) | (A & B))); C = (C << 9) | (C >> 23);
        B += (XX12 + 1518500249U + ((C & D) | (C & A) | (D & A))); B = (B << 13) | (B >> 19);

        A += (XX1 + 1518500249U + ((B & C) | (B & D) | (C & D))); A = (A << 3) | (A >> 29);
        D += (XX5 + 1518500249U + ((A & B) | (A & C) | (B & C))); D = (D << 5) | (D >> 27);
        C += (XX9 + 1518500249U + ((D & A) | (D & B) | (A & B))); C = (C << 9) | (C >> 23);
        B += (XX13 + 1518500249U + ((C & D) | (C & A) | (D & A))); B = (B << 13) | (B >> 19);

        A += (XX2 + 1518500249U + ((B & C) | (B & D) | (C & D))); A = (A << 3) | (A >> 29);
        D += (XX6 + 1518500249U + ((A & B) | (A & C) | (B & C))); D = (D << 5) | (D >> 27);
        C += (XX10 + 1518500249U + ((D & A) | (D & B) | (A & B))); C = (C << 9) | (C >> 23);
        B += (XX14 + 1518500249U + ((C & D) | (C & A) | (D & A))); B = (B << 13) | (B >> 19);

        A += (XX3 + 1518500249U + ((B & C) | (B & D) | (C & D))); A = (A << 3) | (A >> 29);
        D += (XX7 + 1518500249U + ((A & B) | (A & C) | (B & C))); D = (D << 5) | (D >> 27);
        C += (XX11 + 1518500249U + ((D & A) | (D & B) | (A & B))); C = (C << 9) | (C >> 23);
        B += (XX15 + 1518500249U + ((C & D) | (C & A) | (D & A))); B = (B << 13) | (B >> 19);

        A += (XX0 + 1859775393U + (B ^ C ^ D)); A = (A << 3) | (A >> 29);
        D += (XX8 + 1859775393U + (A ^ B ^ C)); D = (D << 9) | (D >> 23);
        C += (XX4 + 1859775393U + (D ^ A ^ B)); C = (C << 11) | (C >> 21);
        B += (XX12 + 1859775393U + (C ^ D ^ A)); B = (B << 15) | (B >> 17);

        A += (XX2 + 1859775393U + (B ^ C ^ D)); A = (A << 3) | (A >> 29);
        D += (XX10 + 1859775393U + (A ^ B ^ C)); D = (D << 9) | (D >> 23);
        C += (XX6 + 1859775393U + (D ^ A ^ B)); C = (C << 11) | (C >> 21);
        B += (XX14 + 1859775393U + (C ^ D ^ A)); B = (B << 15) | (B >> 17);

        A += (XX1 + 1859775393U + (B ^ C ^ D)); A = (A << 3) | (A >> 29);
        D += (XX9 + 1859775393U + (A ^ B ^ C)); D = (D << 9) | (D >> 23);
        C += (XX5 + 1859775393U + (D ^ A ^ B)); C = (C << 11) | (C >> 21);
        B += (XX13 + 1859775393U + (C ^ D ^ A)); B = (B << 15) | (B >> 17);

        A += (XX3 + 1859775393U + (B ^ C ^ D)); A = (A << 3) | (A >> 29);
        D += (XX11 + 1859775393U + (A ^ B ^ C)); D = (D << 9) | (D >> 23);
        C += (XX7 + 1859775393U + (D ^ A ^ B)); C = (C << 11) | (C >> 21);
        B += (XX15 + 1859775393U + (C ^ D ^ A)); B = (B << 15) | (B >> 17);

        c->A += A;
        c->B += B;
        c->C += C;
        c->D += D;
    }
}
