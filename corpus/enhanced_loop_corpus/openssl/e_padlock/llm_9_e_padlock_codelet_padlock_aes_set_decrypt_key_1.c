#include <stdio.h>

#include <inttypes.h>

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};


typedef struct aes_key_st AES_KEY;

typedef unsigned int u32;

extern AES_KEY *key;
extern u32 *rk;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < (key->rounds); i += 2) {
    rk += 8;
    for (j = 0; j < 4; j++) {
        u32 tp1, tp2, tp4, tp8, tp9, tpb, tpd, tpe, m;
        // Unroll two iterations of the inner loop manually
        // First element: j = 0
        tp1 = rk[0];
        m = tp1 & 2155905152U;
        tp2 = ((tp1 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp2 & 2155905152U;
        tp4 = ((tp2 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp4 & 2155905152U;
        tp8 = ((tp4 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        tp9 = tp8 ^ tp1;
        tpb = tp9 ^ tp2;
        tpd = tp9 ^ tp4;
        tpe = tp8 ^ tp4 ^ tp2;
        rk[0] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^ (tp9 >> 8) ^ (tp9 << 24) ^ (tpb >> 24) ^ (tpb << 8);

        // Second element: j = 1
        tp1 = rk[1];
        m = tp1 & 2155905152U;
        tp2 = ((tp1 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp2 & 2155905152U;
        tp4 = ((tp2 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp4 & 2155905152U;
        tp8 = ((tp4 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        tp9 = tp8 ^ tp1;
        tpb = tp9 ^ tp2;
        tpd = tp9 ^ tp4;
        tpe = tp8 ^ tp4 ^ tp2;
        rk[1] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^ (tp9 >> 8) ^ (tp9 << 24) ^ (tpb >> 24) ^ (tpb << 8);

        // Third element: j = 2
        tp1 = rk[2];
        m = tp1 & 2155905152U;
        tp2 = ((tp1 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp2 & 2155905152U;
        tp4 = ((tp2 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp4 & 2155905152U;
        tp8 = ((tp4 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        tp9 = tp8 ^ tp1;
        tpb = tp9 ^ tp2;
        tpd = tp9 ^ tp4;
        tpe = tp8 ^ tp4 ^ tp2;
        rk[2] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^ (tp9 >> 8) ^ (tp9 << 24) ^ (tpb >> 24) ^ (tpb << 8);

        // Fourth element: j = 3
        tp1 = rk[3];
        m = tp1 & 2155905152U;
        tp2 = ((tp1 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp2 & 2155905152U;
        tp4 = ((tp2 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        m = tp4 & 2155905152U;
        tp8 = ((tp4 & 2139062143) << 1) ^ ((m - (m >> 7)) & 454761243);
        tp9 = tp8 ^ tp1;
        tpb = tp9 ^ tp2;
        tpd = tp9 ^ tp4;
        tpe = tp8 ^ tp4 ^ tp2;
        rk[3] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^ (tp9 >> 8) ^ (tp9 << 24) ^ (tpb >> 24) ^ (tpb << 8);
    }
}
}
