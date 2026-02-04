#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef R E;

typedef ptrdiff_t INT;

typedef INT *stride;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP803207531;
extern  E KP595699304;
extern  E KP146730474;
extern  E KP989176509;
extern  E KP740951125;
extern  E KP671558954;
extern  E KP049067674;
extern  E KP998795456;
extern  E KP242980179;
extern  E KP970031253;
extern  E KP514102744;
extern  E KP857728610;
extern  E KP336889853;
extern  E KP941544065;
extern  E KP427555093;
extern  E KP903989293;
extern  E KP098017140;
extern  E KP995184726;
extern  E KP634393284;
extern  E KP773010453;
extern  E KP881921264;
extern  E KP471396736;
extern  E KP956940335;
extern  E KP290284677;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP195090322;
extern  E KP980785280;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E TcD, TdU, T27, T7r, T5S, T8y, Tf, Ta5, Tu, Tbq, TcG, TdV, T2e, T8z, T5V;
    E T7s, TK, Ta6, TcK, TdX, T2o, T5X, T7w, T8B, TZ, Ta7, TcN, TdY, T2x, T5Y;
    E T7z, T8C, T1g, Taa, TcU, TeA, TcX, Tez, T1v, Tab, T2M, T6z, T7E, T9e, T7H;
    E T9d, T2T, T6A, T4X, T6L, Tdz, TeL, TdK, TeP, T5G, T6P, T8d, T9p, TaV, Tc3;
    E Tbi, Tc4, T8o, T9t, T3I, T6H, Tde, TeH, Tdp, TeF, T4r, T6F, T7U, T9l, Tao;
    E TbW, TaL, TbX, T85, T9j, T1L, Tad, Td3, Tew, Td6, Tex, T20, Tae, T37, T6x;
    E T7L, T9a, T7O, T9b, T3e, T6w, TbZ, Tc0, T3Z, T4s, Tds, TeI, T4g, T4t, T80;
    E T87, Tdl, TeE, T7X, T86, TaD, TaM, Tc6, Tc7, T5e, T5H, TdN, TeM, T5v, T5I;
    E T8j, T8q, TdG, TeO, T8g, T8p, Tba, Tbj;

    if (i <= v / 2) {
        goto second_half_processing;
    }

    {
        E T3, T23, Td, T25, T6, T5R, Ta, T24;
        {
            E T1, T2, Tb, Tc;
            T1 = R0[0];
            T2 = R0[(rs[32])];
            T3 = T1 + T2;
            T23 = T1 - T2;
            Tb = R0[(rs[56])];
            Tc = R0[(rs[24])];
            Td = Tb + Tc;
            T25 = Tb - Tc;
        }
        {
            E T4, T5, T8, T9;
            T4 = R0[(rs[16])];
            T5 = R0[(rs[48])];
            T6 = T4 + T5;
            T5R = T4 - T5;
            T8 = R0[(rs[8])];
            T9 = R0[(rs[40])];
            Ta = T8 + T9;
            T24 = T8 - T9;
        }
        TcD = T3 - T6;
        TdU = Td - Ta;
        {
            E T26, T5Q, T7, Te;
            T26 = KP707106781 * (T24 + T25);
            T27 = T23 + T26;
            T7r = T23 - T26;
            T5Q = KP707106781 * (T25 - T24);
            T5S = T5Q - T5R;
            T8y = T5R + T5Q;
            T7 = T3 + T6;
            Te = Ta + Td;
            Tf = T7 + Te;
            Ta5 = T7 - Te;
        }
    }

    if (i % 4 != 0) {
        goto skip_full_computation;
    }

second_half_processing:
    {
        E T14, T2N, T17, T2D, T1b, T2O, T1e, T2C, T1j, T1m, T2K, TcR, T2Q, T1q, T1t;
        E T2H, TcS, T2R;
        {
            E T12, T13, T15, T16;
            T12 = R0[(rs[1])];
            T13 = R0[(rs[33])];
            T14 = T12 + T13;
            T2N = T12 - T13;
            T15 = R0[(rs[17])];
            T16 = R0[(rs[49])];
            T17 = T15 + T16;
            T2D = T15 - T16;
        }
        {
            E T19, T1a, T2B, T1c, T1d, T2A;
            T19 = R0[(rs[9])];
            T1a = R0[(rs[41])];
            T2B = T19 - T1a;
            T1c = R0[(rs[57])];
            T1d = R0[(rs[25])];
            T2A = T1c - T1d;
            T1b = T19 + T1a;
            T2O = KP707106781 * (T2B + T2A);
            T1e = T1c + T1d;
            T2C = KP707106781 * (T2A - T2B);
        }
        {
            E T2I, T2J, T2F, T2G;
            {
                E T1h, T1i, T1k, T1l;
                T1h = R0[(rs[5])];
                T1i = R0[(rs[37])];
                T1j = T1h + T1i;
                T2I = T1h - T1i;
                T1k = R0[(rs[21])];
                T1l = R0[(rs[53])];
                T1m = T1k + T1l;
                T2J = T1k - T1l;
            }
            T2K = (((KP382683432) * (T2I)) + (KP923879532 * T2J));
            TcR = T1j - T1m;
            T2Q = ((KP923879532 * T2I) - ((KP382683432) * (T2J)));
            {
                E T1o, T1p, T1r, T1s;
                T1o = R0[(rs[61])];
                T1p = R0[(rs[29])];
                T1q = T1o + T1p;
                T2F = T1o - T1p;
                T1r = R0[(rs[13])];
                T1s = R0[(rs[45])];
                T1t = T1r + T1s;
                T2G = T1r - T1s;
            }
            T2H = ((KP382683432 * T2F) - ((KP923879532) * (T2G)));
            TcS = T1q - T1t;
            T2R = (((KP923879532) * (T2F)) + (KP382683432 * T2G));
        }
        {
            E T18, T1f, TcQ, TcT;
            T18 = T14 + T17;
            T1f = T1b + T1e;
            T1g = T18 + T1f;
            Taa = T18 - T1f;
            TcQ = T14 - T17;
            TcT = KP707106781 * (TcR + TcS);
            TcU = TcQ + TcT;
            TeA = TcQ - TcT;
        }
        {
            E TcV, TcW, T1n, T1u;
            TcV = T1e - T1b;
            TcW = KP707106781 * (TcS - TcR);
            TcX = TcV + TcW;
            Tez = TcW - TcV;
            T1n = T1j + T1m;
            T1u = T1q + T1t;
            T1v = T1n + T1u;
            Tab = T1u - T1n;
        }
        {
            E T2E, T2L, T7C, T7D;
            T2E = T2C - T2D;
            T2L = T2H - T2K;
            T2M = T2E + T2L;
            T6z = T2L - T2E;
            T7C = T2N - T2O;
            T7D = T2K + T2H;
            T7E = T7C + T7D;
            T9e = T7C - T7D;
        }
        {
            E T7F, T7G, T2P, T2S;
            T7F = T2D + T2C;
            T7G = T2R - T2Q;
            T7H = T7F + T7G;
            T9d = T7G - T7F;
            T2P = T2N + T2O;
            T2S = T2Q + T2R;
            T2T = T2P + T2S;
            T6A = T2P - T2S;
        }
    }

skip_full_computation:

    for (INT k = 0; k < 1; ++k) {
        E T4z, TaP, T5B, TaQ, T4G, TaT, T5y, TaS, Tbf, Tbg, T4O, Tdw, T5E, Tbc, Tbd;
        E T4V, Tdx, T5D;
        {
            E T4x, T4y, T5z, T5A;
            T4x = R1[(rs[63])];
            T4y = R1[(rs[31])];
            T4z = T4x - T4y;
            TaP = T4x + T4y;
            T5z = R1[(rs[15])];
            T5A = R1[(rs[47])];
            T5B = T5z - T5A;
            TaQ = T5z + T5A;
        }
        {
            E T4A, T4B, T4C, T4D, T4E, T4F;
            T4A = R1[(rs[7])];
            T4B = R1[(rs[39])];
            T4C = T4A - T4B;
            T4D = R1[(rs[55])];
            T4E = R1[(rs[23])];
            T4F = T4D - T4E;
            T4G = KP707106781 * (T4C + T4F);
            TaT = T4D + T4E;
            T5y = KP707106781 * (T4F - T4C);
            TaS = T4A + T4B;
        }
        {
            E T4K, T4N, T4R, T4U;
            {
                E T4I, T4J, T4L, T4M;
                T4I = R1[(rs[3])];
                T4J = R1[(rs[35])];
                T4K = T4I - T4J;
                Tbf = T4I + T4J;
                T4L = R1[(rs[19])];
                T4M = R1[(rs[51])];
                T4N = T4L - T4M;
                Tbg = T4L + T4M;
            }
            T4O = ((KP923879532 * T4K) - ((KP382683432) * (T4N)));
            Tdw = Tbf - Tbg;
            T5E = (((KP382683432) * (T4K)) + (KP923879532 * T4N));
            {
                E T4P, T4Q, T4S, T4T;
                T4P = R1[(rs[59])];
                T4Q = R1[(rs[27])];
                T4R = T4P - T4Q;
                Tbc = T4P + T4Q;
                T4S = R1[(rs[11])];
                T4T = R1[(rs[43])];
                T4U = T4S - T4T;
                Tbd = T4S + T4T;
            }
            T4V = (((KP923879532) * (T4R)) + (KP382683432 * T4U));
            Tdx = Tbc - Tbd;
            T5D = ((KP382683432 * T4R) - ((KP923879532) * (T4U)));
        }
        {
            E T4H, T4W, Tdv, Tdy;
            T4H = T4z + T4G;
            T4W = T4O + T4V;
            T4X = T4H + T4W;
            T6L = T4H - T4W;
            Tdv = TaP - TaQ;
            Tdy = KP707106781 * (Tdw + Tdx);
            Tdz = Tdv + Tdy;
            TeL = Tdv - Tdy;
        }
        {
            E TdI, TdJ, T5C, T5F;
            TdI = TaT - TaS;
            TdJ = KP707106781 * (Tdx - Tdw);
            TdK = TdI + TdJ;
            TeP = TdJ - TdI;
            T5C = T5y - T5B;
            T5F = T5D - T5E;
            T5G = T5C + T5F;
            T6P = T5F - T5C;
        }
        {
            E T8b, T8c, TaR, TaU;
            T8b = T4z - T4G;
            T8c = T5E + T5D;
            T8d = T8b + T8c;
            T9p = T8b - T8c;
            TaR = TaP + TaQ;
            TaU = TaS + TaT;
            TaV = TaR - TaU;
            Tc3 = TaR + TaU;
        }
        {
            E Tbe, Tbh, T8m, T8n;
            Tbe = Tbc + Tbd;
            Tbh = Tbf + Tbg;
            Tbi = Tbe - Tbh;
            Tc4 = Tbh + Tbe;
            T8m = T5B + T5y;
            T8n = T4V - T4O;
            T8o = T8m + T8n;
            T9t = T8n - T8m;
        }
    }

    if (i > v / 4) {
        goto next_iteration;
    }

    {
        E Tch, Tcu, Tck, Tct, Tco, Tcy, Tcr, Tcz, Tci, Tcj;
        Tch = Tf - Tu;
        Tcu = TZ - TK;
        Tci = T1g - T1v;
        Tcj = T1L - T20;
        Tck = KP707106781 * (Tci + Tcj);
        Tct = KP707106781 * (Tcj - Tci);
        {
            E Tcm, Tcn, Tcp, Tcq;
            Tcm = TbW - TbX;
            Tcn = Tc0 - TbZ;
            Tco = (((KP923879532) * (Tcm)) + (KP382683432 * Tcn));
            Tcy = ((KP923879532 * Tcn) - ((KP382683432) * (Tcm)));
            Tcp = Tc3 - Tc4;
            Tcq = Tc7 - Tc6;
            Tcr = ((KP923879532 * Tcp) - ((KP382683432) * (Tcq)));
            Tcz = (((KP382683432) * (Tcp)) + (KP923879532 * Tcq));
        }
        {
            E Tcl, Tcs, Tcx, TcA;
            Tcl = Tch + Tck;
            Tcs = Tco + Tcr;
            Cr[(csr[56])] = Tcl - Tcs;
            Cr[(csr[8])] = Tcl + Tcs;
            Tcx = Tcu + Tct;
            TcA = Tcy + Tcz;
            Ci[(csi[8])] = Tcx + TcA;
            Ci[(csi[56])] = TcA - Tcx;
        }
        {
            E Tcv, Tcw, TcB, TcC;
            Tcv = Tct - Tcu;
            Tcw = Tcr - Tco;
            Ci[(csi[24])] = Tcv + Tcw;
            Ci[(csi[40])] = Tcw - Tcv;
            TcB = Tch - Tck;
            TcC = Tcz - Tcy;
            Cr[(csr[40])] = TcB - TcC;
            Cr[(csr[24])] = TcB + TcC;
        }
    }

next_iteration:
    ;
}
}
