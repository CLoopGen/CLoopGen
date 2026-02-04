#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 2, Rp = Rp + 2*ms, Ip = Ip + 2*ms, Rm = Rm - 2*ms, Im = Im - 2*ms, W = W + 76) {
    E Tj, T1R, T4j, T4s, T2q, T37, T3Q, T42;
    E T1r, T1O, T1P, T3p, T3s, T3K, T3A, T3B, T3Z;
    E T1V, T1W, T1X, T23, T28, T4q, T2W, T2X, T4f;
    E T33, T34, T35, T2G, T2L, T2M, TG, T13, T14;
    E T3i, T3l, T3J, T3D, T3E, T40, T1S, T1T, T1U;
    E T2e, T2j, T4p, T2T, T2U, T4e, T30, T31, T32;
    E T2v, T2A, T2B;

    // First iteration (m)
    {
        E T1, T3O, T6, T3N, Tc, T2n, Th, T2o;
        T1 = Rp[0];
        T3O = Rm[0];
        {
            E T3 = Rp[rs[5]], T5 = Rm[rs[5]];
            E T2 = W[18], T4 = W[19];
            T6 = T2*T3 + T4*T5;
            T3N = T2*T5 - T4*T3;
        }
        {
            E T9 = Ip[rs[2]], Tb = Im[rs[2]];
            E T8 = W[8], Ta = W[9];
            Tc = T8*T9 + Ta*Tb;
            T2n = T8*Tb - Ta*T9;
        }
        {
            E Te = Ip[rs[7]], Tg = Im[rs[7]];
            E Td = W[28], Tf = W[29];
            Th = Td*Te + Tf*Tg;
            T2o = Td*Tg - Tf*Te;
        }
        {
            E T7 = T1 + T6, Ti = Tc + Th;
            Tj = T7 - Ti;
            T1R = T7 + Ti;
            E T4h = T3O - T3N, T4i = Tc - Th;
            T4j = T4h - T4i;
            T4s = T4i + T4h;
        }
        {
            E T2m = T1 - T6, T2p = T2n - T2o;
            T2q = T2m - T2p;
            T37 = T2m + T2p;
            E T3M = T2n + T2o, T3P = T3N + T3O;
            T3Q = T3M + T3P;
            T42 = T3P - T3M;
        }
    }

    {
        E Tu, T3g, T2c, T2r, T12, T3k, T2f, T2z;
        E TF, T3h, T2d, T2u, TR, T3j, T2i, T2w;
        {
            E To = Rp[rs[2]] + Rp[rs[7]], Tt = Rp[rs[7]];
            E T2a = W[6]*Rm[rs[2]] - W[7]*Rp[rs[2]];
            E T2b = W[26]*Rm[rs[7]] - W[27]*Rp[rs[7]];
            Tu = To + Tt;
            T3g = T2a + T2b;
            T2c = T2a - T2b;
            T2r = To - Tt;
        }
        {
            E TW = W[0]*Ip[0] + W[1]*Im[0];
            E T2x = W[0]*Im[0] - W[1]*Ip[0];
            E T11 = W[20]*Ip[rs[5]] + W[21]*Im[rs[5]];
            E T2y = W[20]*Im[rs[5]] - W[21]*Ip[rs[5]];
            T12 = TW + T11;
            T3k = T2x + T2y;
            T2f = T11 - TW;
            T2z = T2x - T2y;
        }
        {
            E Tz = W[16]*Ip[rs[4]] + W[17]*Im[rs[4]];
            E T2s = W[16]*Im[rs[4]] - W[17]*Ip[rs[4]];
            E TE = W[36]*Ip[rs[9]] + W[37]*Im[rs[9]];
            E T2t = W[36]*Im[rs[9]] - W[37]*Ip[rs[9]];
            TF = Tz + TE;
            T3h = T2s + T2t;
            T2d = Tz - TE;
            T2u = T2s - T2t;
        }
        {
            E TL = W[30]*Rp[rs[8]] + W[31]*Rm[rs[8]];
            E T2g = W[30]*Rm[rs[8]] - W[31]*Rp[rs[8]];
            E TQ = W[10]*Rp[rs[3]] + W[11]*Rm[rs[3]];
            E T2h = W[10]*Rm[rs[3]] - W[11]*Rp[rs[3]];
            TR = TL + TQ;
            T3j = T2g + T2h;
            T2i = T2g - T2h;
            T2w = TL - TQ;
        }
        TG = Tu - TF;
        T13 = TR - T12;
        T14 = TG + T13;
        T3i = T3g + T3h;
        T3l = T3j + T3k;
        T3J = T3i + T3l;
        T3D = T3g - T3h;
        T3E = T3j - T3k;
        T40 = T3D + T3E;
        T1S = Tu + TF;
        T1T = TR + T12;
        T1U = T1S + T1T;
        T2e = T2c + T2d;
        T2j = T2f - T2i;
        T4p = T2j - T2e;
        T2T = T2c - T2d;
        T2U = T2i + T2f;
        T4e = T2T + T2U;
        T30 = T2r + T2u;
        T31 = T2w + T2z;
        T32 = T30 + T31;
        T2v = T2r - T2u;
        T2A = T2w - T2z;
        T2B = T2v + T2A;
    }

    {
        E T3y = KP559016994 * (T14 - T1P);
        E T1Q = T14 + T1P;
        E T3x = Tj - KP250000000*T1Q;
        E T3C = T3A + T3B;
        E T3F = T3D - T3E;
        E T3G = KP951056516*T3C - KP587785252*T3F;
        E T3I = KP951056516*T3F + KP587785252*T3C;
        Rm[rs[9]] = Tj + T1Q;
        E T3H = T3y + T3x;
        Rm[rs[5]] = T3H - T3I;
        Rp[rs[6]] = T3H + T3I;
        E T3z = T3x - T3y;
        Rp[rs[2]] = T3z - T3G;
        Rm[rs[1]] = T3z + T3G;
    }

    {
        E T47 = KP559016994 * (T40 + T3Z);
        E T41 = T3Z - T40;
        E T46 = KP250000000*T41 + T42;
        E T43 = T13 - TG;
        E T44 = T1r - T1O;
        E T45 = KP587785252*T43 + KP951056516*T44;
        E T49 = KP951056516*T43 - KP587785252*T44;
        Im[rs[9]] = T41 - T42;
        E T4a = T47 + T46;
        Im[rs[5]] = T49 - T4a;
        Ip[rs[6]] = T49 + T4a;
        E T48 = T46 - T47;
        Im[rs[1]] = T45 - T48;
        Ip[rs[2]] = T45 + T48;
    }

    // Second iteration (m+1), unrolled and simplified using same pattern
    if (m + 1 >= me) continue;

    {
        E T1 = Rp[ms], T3O = Rm[-ms];
        E T3 = Rp[ms + rs[5]], T5 = Rm[-ms + rs[5]];
        E T2 = W[56], T4 = W[57];
        E T6 = T2*T3 + T4*T5;
        E T3N = T2*T5 - T4*T3;
        E T9 = Ip[ms + rs[2]], Tb = Im[-ms + rs[2]];
        E T8 = W[48], Ta = W[49];
        E Tc = T8*T9 + Ta*Tb;
        E T2n = T8*Tb - Ta*T9;
        E Te = Ip[ms + rs[7]], Tg = Im[-ms + rs[7]];
        E Td = W[68], Tf = W[69];
        E Th = Td*Te + Tf*Tg;
        E T2o = Td*Tg - Tf*Te;
        E T7 = T1 + T6, Ti = Tc + Th;
        E Tj = T7 - Ti;
        E T1R = T7 + Ti;
        E T4h = T3O - T3N, T4i = Tc - Th;
        E T4j = T4h - T4i;
        E T4s = T4i + T4h;
        E T2m = T1 - T6, T2p = T2n - T2o;
        E T2q = T2m - T2p;
        E T37 = T2m + T2p;
        E T3M = T2n + T2o, T3P = T3N + T3O;
        E T3Q = T3M + T3P;
        E T42 = T3P - T3M;

        E T3y = KP559016994 * (T14 - T1P);
        E T1Q = T14 + T1P;
        E T3x = Tj - KP250000000*T1Q;
        E T3C = T3A + T3B;
        E T3F = T3D - T3E;
        E T3G = KP951056516*T3C - KP587785252*T3F;
        E T3I = KP951056516*T3F + KP587785252*T3C;
        Rm[-ms + rs[9]] = Tj + T1Q;
        E T3H = T3y + T3x;
        Rm[-ms + rs[5]] = T3H - T3I;
        Rp[ms + rs[6]] = T3H + T3I;
        E T3z = T3x - T3y;
        Rp[ms + rs[2]] = T3z - T3G;
        Rm[-ms + rs[1]] = T3z + T3G;
    }
}
}
