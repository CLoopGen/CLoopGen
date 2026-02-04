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
for (i = 1; i < (key->rounds); i++) {
    rk += 4;
    for (j = 0; j < 4; j++) {
        u32 tp1, tp2, tp4, tp8, tp9, tpb, tpd, tpe, m;
        int idx = (j * 15) % 4; // Strided and wrapped index: creates non-consecutive access pattern
        tp1 = rk[idx];
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
        rk[idx] = tpe ^ (tpd >> 16) ^ (tpd << 16) ^ (tp9 >> 8) ^ (tp9 << 24) ^ (tpb >> 24) ^ (tpb << 8);
    }
}
}
