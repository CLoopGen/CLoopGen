#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern short *xk;
extern FLOAT8 *in;
extern int i;
extern FLOAT8 s;
extern FLOAT8 t;
extern FLOAT8 *wp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 14; i >= 0; --i) {
    short *x1 = &xk[i];
    short *x2 = &xk[-i];
    FLOAT8 w;
    s = x2[270];
    t = x1[240];
    w = wp[0];
    s += x2[334] * w;
    t += x1[176] * w;
    w = wp[1];
    s += x2[398] * w;
    t += x1[112] * w;
    w = wp[2];
    s += x2[462] * w;
    t += x1[48] * w;
    w = wp[3];
    s += x2[14] * w;
    t += x1[496] * w;
    w = wp[4];
    s += x2[78] * w;
    t += x1[432] * w;
    w = wp[5];
    s += x2[142] * w;
    t += x1[368] * w;
    w = wp[6];
    s += x2[206] * w;
    t += x1[304] * w;
    w = wp[7];
    s += x1[16] * w;
    t -= x2[494] * w;
    w = wp[8];
    s += x1[80] * w;
    t -= x2[430] * w;
    w = wp[9];
    s += x1[144] * w;
    t -= x2[366] * w;
    w = wp[10];
    s += x1[208] * w;
    t -= x2[302] * w;
    w = wp[11];
    s -= x1[272] * w;
    t += x2[238] * w;
    w = wp[12];
    s -= x1[336] * w;
    t += x2[174] * w;
    w = wp[13];
    s -= x1[400] * w;
    t += x2[110] * w;
    w = wp[14];
    s -= x1[464] * w;
    t += x2[46] * w;
    in[30 - i] = s;
    in[i] = t;
    wp += 15; // Advance wp once per iteration to remove per-load increment
}
}
