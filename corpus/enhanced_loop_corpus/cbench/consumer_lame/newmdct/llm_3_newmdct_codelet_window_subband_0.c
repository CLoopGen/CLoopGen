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
const int indices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
for (int idx = 0; idx < 15; ++idx) {
    i = indices[idx];
    short *x1 = &xk[14 - i];
    short *x2 = &xk[i - 14];
    FLOAT8 w;
    s = x2[270];
    t = x1[240];
    for (int j = 0; j < 14; ++j) {
        w = *wp++;
        switch(j) {
            case 0: s += x2[334] * w; t += x1[176] * w; break;
            case 1: s += x2[398] * w; t += x1[112] * w; break;
            case 2: s += x2[462] * w; t += x1[48]  * w; break;
            case 3: s += x2[14]  * w; t += x1[496] * w; break;
            case 4: s += x2[78]  * w; t += x1[432] * w; break;
            case 5: s += x2[142] * w; t += x1[368] * w; break;
            case 6: s += x2[206] * w; t += x1[304] * w; break;
            case 7: s += x1[16]  * w; t -= x2[494] * w; break;
            case 8: s += x1[80]  * w; t -= x2[430] * w; break;
            case 9: s += x1[144] * w; t -= x2[366] * w; break;
            case 10: s += x1[208] * w; t -= x2[302] * w; break;
            case 11: s -= x1[272] * w; t += x2[238] * w; break;
            case 12: s -= x1[336] * w; t += x2[174] * w; break;
            case 13: s -= x1[400] * w; t += x2[110] * w; break;
        }
    }
    w = *wp++;
    s -= x1[464] * w;
    t += x2[46] * w;
    in[i] = t;
    in[30 - i] = s;
}
}
