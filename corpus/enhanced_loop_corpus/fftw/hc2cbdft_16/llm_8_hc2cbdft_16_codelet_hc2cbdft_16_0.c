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
extern  E KP923879532;
extern  E KP382683432;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 30) {
    E TB, T2L, T30, T1n, Tf, T1U, T2H, T3p, T1E, T1Z, TM, T31, T2s, T3k, T1i;
    E T2M, Tu, T1Y, T2Q, T2X, T2T, T2Y, TY, T1d, T19, T1e, T2v, T2C, T2y, T2D;
    E T1x, T1V;

    {
        E T3, T1j, TA, T1B, T6, Tx, T1m, T1C, Ta, TC, TF, T1y, Td, TH, TK;
        E T1z;
        T3 = Rp[0] + Rm[(rs[7])];
        T1j = Rp[0] - Rm[(rs[7])];
        TA = Ip[0] + Im[(rs[7])];
        T1B = Ip[0] - Im[(rs[7])];

        T6 = Rp[(rs[4])] + Rm[(rs[3])];
        Tx = Rp[(rs[4])] - Rm[(rs[3])];
        T1m = Ip[(rs[4])] + Im[(rs[3])];
        T1C = Ip[(rs[4])] - Im[(rs[3])];

        Ta = Rp[(rs[2])] + Rm[(rs[5])];
        TC = Rp[(rs[2])] - Rm[(rs[5])];
        TF = Ip[(rs[2])] + Im[(rs[5])];
        T1y = Ip[(rs[2])] - Im[(rs[5])];

        Td = Rm[(rs[1])] + Rp[(rs[6])];
        TH = Rm[(rs[1])] - Rp[(rs[6])];
        TK = Im[(rs[1])] + Ip[(rs[6])];
        T1z = Ip[(rs[6])] - Im[(rs[1])];

        TB = Tx + TA;
        T2L = TA - Tx;
        T30 = T1j + T1m;
        T1n = T1j - T1m;

        Tf = (Rp[0] + Rm[(rs[7])]) + (Rp[(rs[4])] + Rm[(rs[3])]) + (Rp[(rs[2])] + Rm[(rs[5])]) + (Rm[(rs[1])] + Rp[(rs[6])]);
        T1U = ((Rp[0] + Rm[(rs[7])]) - (Rp[(rs[4])] + Rm[(rs[3])])) - ((Rp[(rs[2])] + Rm[(rs[5])]) - (Rm[(rs[1])] + Rp[(rs[6])]));

        T2H = (Ta - Td) + (T1B - T1C);
        T3p = (T1B - T1C) - (Ta - Td);
        T1E = (T1y + T1z) + (T1B + T1C);
        T1Z = (T1B + T1C) - (T1y + T1z);

        TM = KP707106781 * ((TC + TF) - (TH + TK));
        T31 = KP707106781 * ((TC + TF) + (TH + TK));

        T2s = (Rp[(rs[1])] - Rm[(rs[6])]) + (Ip[(rs[4])] - Im[(rs[3])]);
        T3k = (Rp[(rs[1])] - Rm[(rs[6])]) - (Ip[(rs[4])] - Im[(rs[3])]);
        T1i = KP707106781 * ((TC - TF) + (TH - TK));
        T2M = KP707106781 * ((TC - TF) - (TH - TK));
    }

    {
        E Ti, TT, TR, T1r, Tl, TO, TW, T1s, Tp, T14, T12, T1u, Ts, TZ, T17;
        E T1v;

        Ti = Rp[(rs[1])] + Rm[(rs[6])];
        TT = Rp[(rs[1])] - Rm[(rs[6])];
        TR = Ip[(rs[1])] + Im[(rs[6])];
        T1r = Ip[(rs[1])] - Im[(rs[6])];

        Tl = Rp[(rs[5])] + Rm[(rs[2])];
        TO = Rp[(rs[5])] - Rm[(rs[2])];
        TW = Ip[(rs[5])] + Im[(rs[2])];
        T1s = Ip[(rs[5])] - Im[(rs[2])];

        Tp = Rm[0] + Rp[(rs[7])];
        T14 = Rm[0] - Rp[(rs[7])];
        T12 = Im[0] + Ip[(rs[7])];
        T1u = Ip[(rs[7])] - Im[0];

        Ts = Rp[(rs[3])] + Rm[(rs[4])];
        TZ = Rp[(rs[3])] - Rm[(rs[4])];
        T17 = Ip[(rs[3])] + Im[(rs[4])];
        T1v = Ip[(rs[3])] - Im[(rs[4])];

        Tu = (Ti + Tl) + (Tp + Ts);
        T1Y = (Ti + Tl) - (Tp + Ts);

        T2Q = (KP382683432 * (TR - TO)) + (KP923879532 * (TT + TW));
        T2X = (KP382683432 * (TT + TW)) - (KP923879532 * (TR - TO));

        T2T = (KP382683432 * (TZ + T12)) + (KP923879532 * (T14 + T17));
        T2Y = (KP382683432 * (T14 + T17)) - (KP923879532 * (TZ + T12));

        TY = (KP923879532 * (TO + TR)) + (KP382683432 * (TT - TW));
        T1d = (KP923879532 * (TT - TW)) - (KP382683432 * (TO + TR));

        T19 = (KP923879532 * (TZ - T12)) - (KP382683432 * (T14 - T17));
        T1e = (KP382683432 * (TZ - T12)) + (KP923879532 * (T14 - T17));

        T2v = (Ti - Tl) - (T1r - T1s);
        T2C = (Ti - Tl) + (T1r - T1s);

        T2y = (Tp - Ts) + (T1u - T1v);
        T2D = (T1u - T1v) - (Tp - Ts);

        T1x = (T1r + T1s) + (T1u + T1v);
        T1V = (T1u + T1v) - (T1r + T1s);
    }

    {
        E Tv, T1F, T1b, T1N, T1p, T1P, T1L, T1R;
        Tv = Tf + Tu;
        T1F = T1x + T1E;

        T1b = (TB + TM) + (TY + T19);
        T1N = (TB + TM) - (TY + T19);
        T1p = (T1d + T1e) + (T1i + T1n);
        T1P = (T1i + T1n) - (T1d + T1e);

        T1L = (W[14] * (Tf - Tu)) - (W[15] * (T1E - T1x));
        T1R = (W[15] * (Tf - Tu)) + (W[14] * (T1E - T1x));

        Rp[0] = Tv - (W[0] * T1b + W[1] * T1p);
        Ip[0] = T1F + (W[0] * T1p - W[1] * T1b);
        Rm[0] = Tv + (W[0] * T1b + W[1] * T1p);
        Im[0] = (W[0] * T1p - W[1] * T1b) - T1F;

        Rp[(rs[4])] = T1L - (W[16] * T1N + W[17] * T1P);
        Ip[(rs[4])] = T1R + (W[16] * T1P - W[17] * T1N);
        Rm[(rs[4])] = T1L + (W[16] * T1N + W[17] * T1P);
        Im[(rs[4])] = (W[16] * T1P - W[17] * T1N) - T1R;
    }

    {
        E T25, T2j, T29, T2l, T21, T2b, T2h, T2n;
        T25 = (TB - TM) + (T1d - T1e);
        T2j = (TB - TM) - (T1d - T1e);
        T29 = (T19 - TY) + (T1n - T1i);
        T2l = (T1n - T1i) - (T19 - TY);

        T21 = (W[6] * (T1U + T1V)) - (W[7] * (T1Y + T1Z));
        T2b = (W[7] * (T1U + T1V)) + (W[6] * (T1Y + T1Z));

        T2h = (W[22] * (T1U - T1V)) - (W[23] * (T1Z - T1Y));
        T2n = (W[23] * (T1U - T1V)) + (W[22] * (T1Z - T1Y));

        Rp[(rs[2])] = T21 - (W[8] * T25 + W[9] * T29);
        Ip[(rs[2])] = T2b + (W[8] * T29 - W[9] * T25);
        Rm[(rs[2])] = T21 + (W[8] * T25 + W[9] * T29);
        Im[(rs[2])] = (W[8] * T29 - W[9] * T25) - T2b;

        Rp[(rs[6])] = T2h - (W[24] * T2j + W[25] * T2l);
        Ip[(rs[6])] = T2n + (W[24] * T2l - W[25] * T2j);
        Rm[(rs[6])] = T2h + (W[24] * T2j + W[25] * T2l);
        Im[(rs[6])] = (W[24] * T2l - W[25] * T2j) - T2n;
    }

    {
        E T2A, T38, T2I, T3a, T2V, T3d, T33, T3f;
        T2A = T2s + KP707106781 * (T2v + T2y);
        T38 = T2s - KP707106781 * (T2v + T2y);
        T2I = KP707106781 * (T2C + T2D) + T2H;
        T3a = T2H - KP707106781 * (T2C + T2D);

        T2V = (T2L + T2M) + (T2Q - T2T);
        T3d = (T2L + T2M) - (T2Q - T2T);
        T33 = (T2X + T2Y) + (T30 - T31);
        T3f = (T30 - T31) - (T2X + T2Y);

        Rp[(rs[1])] = (W[2] * T2A - W[3] * T2I) - (W[4] * T2V + W[5] * T33);
        Ip[(rs[1])] = (W[3] * T2A + W[2] * T2I) + (W[4] * T33 - W[5] * T2V);
        Rm[(rs[1])] = (W[2] * T2A - W[3] * T2I) + (W[4] * T2V + W[5] * T33);
        Im[(rs[1])] = (W[4] * T33 - W[5] * T2V) - (W[3] * T2A + W[2] * T2I);

        Rp[(rs[5])] = (W[18] * T38 - W[19] * T3a) - (W[20] * T3d + W[21] * T3f);
        Ip[(rs[5])] = (W[19] * T38 + W[18] * T3a) + (W[20] * T3f - W[21] * T3d);
        Rm[(rs[5])] = (W[18] * T38 - W[19] * T3a) + (W[20] * T3d + W[21] * T3f);
        Im[(rs[5])] = (W[20] * T3f - W[21] * T3d) - (W[19] * T38 + W[18] * T3a);
    }

    {
        E T3m, T3E, T3q, T3G, T3v, T3J, T3z, T3L;
        T3m = T3k + KP707106781 * (T2D - T2C);
        T3E = T3k - KP707106781 * (T2D - T2C);
        T3q = KP707106781 * (T2v - T2y) + T3p;
        T3G = T3p - KP707106781 * (T2v - T2y);

        T3v = (T2L - T2M) + (T2X - T2Y);
        T3J = (T2L - T2M) - (T2X - T2Y);
        T3z = (T31 + T30) - (T2Q + T2T);
        T3L = (T2Q + T2T) + (T31 + T30);

        Rp[(rs[3])] = (W[10] * T3m - W[11] * T3q) - (W[12] * T3v + W[13] * T3z);
        Ip[(rs[3])] = (W[11] * T3m + W[10] * T3q) + (W[12] * T3z - W[13] * T3v);
        Rm[(rs[3])] = (W[10] * T3m - W[11] * T3q) + (W[12] * T3v + W[13] * T3z);
        Im[(rs[3])] = (W[12] * T3z - W[13] * T3v) - (W[11] * T3m + W[10] * T3q);

        Rp[(rs[7])] = (W[26] * T3E - W[27] * T3G) - (W[28] * T3J + W[29] * T3L);
        Ip[(rs[7])] = (W[27] * T3E + W[26] * T3G) + (W[28] * T3L - W[29] * T3J);
        Rm[(rs[7])] = (W[26] * T3E - W[27] * T3G) + (W[28] * T3J + W[29] * T3L);
        Im[(rs[7])] = (W[28] * T3L - W[29] * T3J) - (W[27] * T3E + W[26] * T3G);
    }
}
}
