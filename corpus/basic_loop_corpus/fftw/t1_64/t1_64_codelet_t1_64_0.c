#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef R E;

typedef ptrdiff_t INT;

typedef INT *stride;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP471396736;
extern  E KP881921264;
extern  E KP290284677;
extern  E KP956940335;
extern  E KP634393284;
extern  E KP773010453;
extern  E KP098017140;
extern  E KP995184726;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP980785280;
extern  E KP195090322;
extern  E KP923879532;
extern  E KP382683432;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = mb , W = W + (mb * 126); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 126 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tj, TcL, ThT, Tin, T6b, Taz, TgT, Thn, TG, Thm, TcO, TgO, T6m, ThQ, TaC;
    E Tim, T14, Tfq, T6y, T9O, TaG, Tc0, TcU, TeE, T1r, Tfr, T6J, T9P, TaJ, Tc1;
    E TcZ, TeF, T1Q, T2d, Tfx, Tfu, Tfv, Tfw, T6Q, TaM, Tdb, TeJ, T71, TaQ, T7a;
    E TaN, Td6, TeI, T77, TaP, T2B, T2Y, Tfz, TfA, TfB, TfC, T7h, TaW, Tdm, TeM;
    E T7s, TaU, T7B, TaX, Tdh, TeL, T7y, TaT, T5j, TfR, Tec, Tf0, TfY, Tgy, T8D;
    E Tbl, T8O, Tbx, T9l, Tbm, TdV, TeX, T9i, Tbw, T3M, TfL, TdL, TeQ, TfI, Tgt;
    E T7K, Tb2, T7V, Tbe, T8s, Tb3, Tdu, TeT, T8p, Tbd, T4x, TfJ, TdE, TdM, TfO;
    E Tgu, T87, T8v, T8i, T8u, Tba, Tbg, Tdz, TdN, Tb7, Tbh, T64, TfZ, Te5, Ted;
    E TfU, Tgz, T90, T9o, T9b, T9n, Tbt, Tbz, Te0, Tee, Tbq, TbA;
    {
        E T1, TgR, T6, TgQ, Tc, T68, Th, T69;
        T1 = ri[0];
        TgR = ii[0];
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[32])];
            T5 = ii[(rs[32])];
            T2 = W[62];
            T4 = W[63];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TgQ = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T9, Tb, T8, Ta;
            T9 = ri[(rs[16])];
            Tb = ii[(rs[16])];
            T8 = W[30];
            Ta = W[31];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            T68 = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = ri[(rs[48])];
            Tg = ii[(rs[48])];
            Td = W[94];
            Tf = W[95];
            Th = (((Td) * (Te)) + (Tf * Tg));
            T69 = ((Td * Tg) - ((Tf) * (Te)));
        }
        {
            E T7, Ti, ThR, ThS;
            T7 = T1 + T6;
            Ti = Tc + Th;
            Tj = T7 + Ti;
            TcL = T7 - Ti;
            ThR = TgR - TgQ;
            ThS = Tc - Th;
            ThT = ThR - ThS;
            Tin = ThS + ThR;
        }
        {
            E T67, T6a, TgP, TgS;
            T67 = T1 - T6;
            T6a = T68 - T69;
            T6b = T67 - T6a;
            Taz = T67 + T6a;
            TgP = T68 + T69;
            TgS = TgQ + TgR;
            TgT = TgP + TgS;
            Thn = TgS - TgP;
        }
    }
    {
        E To, T6c, Tt, T6d, T6e, T6f, Tz, T6i, TE, T6j, T6h, T6k;
        {
            E Tl, Tn, Tk, Tm;
            Tl = ri[(rs[8])];
            Tn = ii[(rs[8])];
            Tk = W[14];
            Tm = W[15];
            To = (((Tk) * (Tl)) + (Tm * Tn));
            T6c = ((Tk * Tn) - ((Tm) * (Tl)));
        }
        {
            E Tq, Ts, Tp, Tr;
            Tq = ri[(rs[40])];
            Ts = ii[(rs[40])];
            Tp = W[78];
            Tr = W[79];
            Tt = (((Tp) * (Tq)) + (Tr * Ts));
            T6d = ((Tp * Ts) - ((Tr) * (Tq)));
        }
        T6e = T6c - T6d;
        T6f = To - Tt;
        {
            E Tw, Ty, Tv, Tx;
            Tw = ri[(rs[56])];
            Ty = ii[(rs[56])];
            Tv = W[110];
            Tx = W[111];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            T6i = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = ri[(rs[24])];
            TD = ii[(rs[24])];
            TA = W[46];
            TC = W[47];
            TE = (((TA) * (TB)) + (TC * TD));
            T6j = ((TA * TD) - ((TC) * (TB)));
        }
        T6h = Tz - TE;
        T6k = T6i - T6j;
        {
            E Tu, TF, TcM, TcN;
            Tu = To + Tt;
            TF = Tz + TE;
            TG = Tu + TF;
            Thm = TF - Tu;
            TcM = T6c + T6d;
            TcN = T6i + T6j;
            TcO = TcM - TcN;
            TgO = TcM + TcN;
        }
        {
            E T6g, T6l, TaA, TaB;
            T6g = T6e - T6f;
            T6l = T6h + T6k;
            T6m = KP707106781 * (T6g - T6l);
            ThQ = KP707106781 * (T6g + T6l);
            TaA = T6f + T6e;
            TaB = T6h - T6k;
            TaC = KP707106781 * (TaA + TaB);
            Tim = KP707106781 * (TaB - TaA);
        }
    }
    {
        E TS, TcQ, T6q, T6t, T13, TcR, T6r, T6w, T6s, T6x;
        {
            E TM, T6o, TR, T6p;
            {
                E TJ, TL, TI, TK;
                TJ = ri[(rs[4])];
                TL = ii[(rs[4])];
                TI = W[6];
                TK = W[7];
                TM = (((TI) * (TJ)) + (TK * TL));
                T6o = ((TI * TL) - ((TK) * (TJ)));
            }
            {
                E TO, TQ, TN, TP;
                TO = ri[(rs[36])];
                TQ = ii[(rs[36])];
                TN = W[70];
                TP = W[71];
                TR = (((TN) * (TO)) + (TP * TQ));
                T6p = ((TN * TQ) - ((TP) * (TO)));
            }
            TS = TM + TR;
            TcQ = T6o + T6p;
            T6q = T6o - T6p;
            T6t = TM - TR;
        }
        {
            E TX, T6u, T12, T6v;
            {
                E TU, TW, TT, TV;
                TU = ri[(rs[20])];
                TW = ii[(rs[20])];
                TT = W[38];
                TV = W[39];
                TX = (((TT) * (TU)) + (TV * TW));
                T6u = ((TT * TW) - ((TV) * (TU)));
            }
            {
                E TZ, T11, TY, T10;
                TZ = ri[(rs[52])];
                T11 = ii[(rs[52])];
                TY = W[102];
                T10 = W[103];
                T12 = (((TY) * (TZ)) + (T10 * T11));
                T6v = ((TY * T11) - ((T10) * (TZ)));
            }
            T13 = TX + T12;
            TcR = T6u + T6v;
            T6r = TX - T12;
            T6w = T6u - T6v;
        }
        T14 = TS + T13;
        Tfq = TcQ + TcR;
        T6s = T6q + T6r;
        T6x = T6t - T6w;
        T6y = ((KP382683432 * T6s) - ((KP923879532) * (T6x)));
        T9O = (((KP923879532) * (T6s)) + (KP382683432 * T6x));
        {
            E TaE, TaF, TcS, TcT;
            TaE = T6q - T6r;
            TaF = T6t + T6w;
            TaG = ((KP923879532 * TaE) - ((KP382683432) * (TaF)));
            Tc0 = (((KP382683432) * (TaE)) + (KP923879532 * TaF));
            TcS = TcQ - TcR;
            TcT = TS - T13;
            TcU = TcS - TcT;
            TeE = TcT + TcS;
        }
    }
    {
        E T1f, TcW, T6B, T6E, T1q, TcX, T6C, T6H, T6D, T6I;
        {
            E T19, T6z, T1e, T6A;
            {
                E T16, T18, T15, T17;
                T16 = ri[(rs[60])];
                T18 = ii[(rs[60])];
                T15 = W[118];
                T17 = W[119];
                T19 = (((T15) * (T16)) + (T17 * T18));
                T6z = ((T15 * T18) - ((T17) * (T16)));
            }
            {
                E T1b, T1d, T1a, T1c;
                T1b = ri[(rs[28])];
                T1d = ii[(rs[28])];
                T1a = W[54];
                T1c = W[55];
                T1e = (((T1a) * (T1b)) + (T1c * T1d));
                T6A = ((T1a * T1d) - ((T1c) * (T1b)));
            }
            T1f = T19 + T1e;
            TcW = T6z + T6A;
            T6B = T6z - T6A;
            T6E = T19 - T1e;
        }
        {
            E T1k, T6F, T1p, T6G;
            {
                E T1h, T1j, T1g, T1i;
                T1h = ri[(rs[12])];
                T1j = ii[(rs[12])];
                T1g = W[22];
                T1i = W[23];
                T1k = (((T1g) * (T1h)) + (T1i * T1j));
                T6F = ((T1g * T1j) - ((T1i) * (T1h)));
            }
            {
                E T1m, T1o, T1l, T1n;
                T1m = ri[(rs[44])];
                T1o = ii[(rs[44])];
                T1l = W[86];
                T1n = W[87];
                T1p = (((T1l) * (T1m)) + (T1n * T1o));
                T6G = ((T1l * T1o) - ((T1n) * (T1m)));
            }
            T1q = T1k + T1p;
            TcX = T6F + T6G;
            T6C = T1k - T1p;
            T6H = T6F - T6G;
        }
        T1r = T1f + T1q;
        Tfr = TcW + TcX;
        T6D = T6B + T6C;
        T6I = T6E - T6H;
        T6J = (((KP382683432) * (T6D)) + (KP923879532 * T6I));
        T9P = ((KP382683432 * T6I) - ((KP923879532) * (T6D)));
        {
            E TaH, TaI, TcV, TcY;
            TaH = T6B - T6C;
            TaI = T6E + T6H;
            TaJ = (((KP923879532) * (TaH)) + (KP382683432 * TaI));
            Tc1 = ((KP923879532 * TaI) - ((KP382683432) * (TaH)));
            TcV = T1f - T1q;
            TcY = TcW - TcX;
            TcZ = TcV + TcY;
            TeF = TcV - TcY;
        }
    }
    {
        E T1y, T6M, T1D, T6N, T1E, Td2, T1J, T74, T1O, T75, T1P, Td3, T21, Td8, T6W;
        E T6Z, T2c, Td9, T6R, T6U;
        {
            E T1v, T1x, T1u, T1w;
            T1v = ri[(rs[2])];
            T1x = ii[(rs[2])];
            T1u = W[2];
            T1w = W[3];
            T1y = (((T1u) * (T1v)) + (T1w * T1x));
            T6M = ((T1u * T1x) - ((T1w) * (T1v)));
        }
        {
            E T1A, T1C, T1z, T1B;
            T1A = ri[(rs[34])];
            T1C = ii[(rs[34])];
            T1z = W[66];
            T1B = W[67];
            T1D = (((T1z) * (T1A)) + (T1B * T1C));
            T6N = ((T1z * T1C) - ((T1B) * (T1A)));
        }
        T1E = T1y + T1D;
        Td2 = T6M + T6N;
        {
            E T1G, T1I, T1F, T1H;
            T1G = ri[(rs[18])];
            T1I = ii[(rs[18])];
            T1F = W[34];
            T1H = W[35];
            T1J = (((T1F) * (T1G)) + (T1H * T1I));
            T74 = ((T1F * T1I) - ((T1H) * (T1G)));
        }
        {
            E T1L, T1N, T1K, T1M;
            T1L = ri[(rs[50])];
            T1N = ii[(rs[50])];
            T1K = W[98];
            T1M = W[99];
            T1O = (((T1K) * (T1L)) + (T1M * T1N));
            T75 = ((T1K * T1N) - ((T1M) * (T1L)));
        }
        T1P = T1J + T1O;
        Td3 = T74 + T75;
        {
            E T1V, T6X, T20, T6Y;
            {
                E T1S, T1U, T1R, T1T;
                T1S = ri[(rs[10])];
                T1U = ii[(rs[10])];
                T1R = W[18];
                T1T = W[19];
                T1V = (((T1R) * (T1S)) + (T1T * T1U));
                T6X = ((T1R * T1U) - ((T1T) * (T1S)));
            }
            {
                E T1X, T1Z, T1W, T1Y;
                T1X = ri[(rs[42])];
                T1Z = ii[(rs[42])];
                T1W = W[82];
                T1Y = W[83];
                T20 = (((T1W) * (T1X)) + (T1Y * T1Z));
                T6Y = ((T1W * T1Z) - ((T1Y) * (T1X)));
            }
            T21 = T1V + T20;
            Td8 = T6X + T6Y;
            T6W = T1V - T20;
            T6Z = T6X - T6Y;
        }
        {
            E T26, T6S, T2b, T6T;
            {
                E T23, T25, T22, T24;
                T23 = ri[(rs[58])];
                T25 = ii[(rs[58])];
                T22 = W[114];
                T24 = W[115];
                T26 = (((T22) * (T23)) + (T24 * T25));
                T6S = ((T22 * T25) - ((T24) * (T23)));
            }
            {
                E T28, T2a, T27, T29;
                T28 = ri[(rs[26])];
                T2a = ii[(rs[26])];
                T27 = W[50];
                T29 = W[51];
                T2b = (((T27) * (T28)) + (T29 * T2a));
                T6T = ((T27 * T2a) - ((T29) * (T28)));
            }
            T2c = T26 + T2b;
            Td9 = T6S + T6T;
            T6R = T26 - T2b;
            T6U = T6S - T6T;
        }
        T1Q = T1E + T1P;
        T2d = T21 + T2c;
        Tfx = T1Q - T2d;
        Tfu = Td2 + Td3;
        Tfv = Td8 + Td9;
        Tfw = Tfu - Tfv;
        {
            E T6O, T6P, Td7, Tda;
            T6O = T6M - T6N;
            T6P = T1J - T1O;
            T6Q = T6O + T6P;
            TaM = T6O - T6P;
            Td7 = T1E - T1P;
            Tda = Td8 - Td9;
            Tdb = Td7 - Tda;
            TeJ = Td7 + Tda;
        }
        {
            E T6V, T70, T78, T79;
            T6V = T6R - T6U;
            T70 = T6W + T6Z;
            T71 = KP707106781 * (T6V - T70);
            TaQ = KP707106781 * (T70 + T6V);
            T78 = T6Z - T6W;
            T79 = T6R + T6U;
            T7a = KP707106781 * (T78 - T79);
            TaN = KP707106781 * (T78 + T79);
        }
        {
            E Td4, Td5, T73, T76;
            Td4 = Td2 - Td3;
            Td5 = T2c - T21;
            Td6 = Td4 - Td5;
            TeI = Td4 + Td5;
            T73 = T1y - T1D;
            T76 = T74 - T75;
            T77 = T73 - T76;
            TaP = T73 + T76;
        }
    }
    {
        E T2j, T7d, T2o, T7e, T2p, Tdd, T2u, T7v, T2z, T7w, T2A, Tde, T2M, Tdj, T7n;
        E T7q, T2X, Tdk, T7i, T7l;
        {
            E T2g, T2i, T2f, T2h;
            T2g = ri[(rs[62])];
            T2i = ii[(rs[62])];
            T2f = W[122];
            T2h = W[123];
            T2j = (((T2f) * (T2g)) + (T2h * T2i));
            T7d = ((T2f * T2i) - ((T2h) * (T2g)));
        }
        {
            E T2l, T2n, T2k, T2m;
            T2l = ri[(rs[30])];
            T2n = ii[(rs[30])];
            T2k = W[58];
            T2m = W[59];
            T2o = (((T2k) * (T2l)) + (T2m * T2n));
            T7e = ((T2k * T2n) - ((T2m) * (T2l)));
        }
        T2p = T2j + T2o;
        Tdd = T7d + T7e;
        {
            E T2r, T2t, T2q, T2s;
            T2r = ri[(rs[14])];
            T2t = ii[(rs[14])];
            T2q = W[26];
            T2s = W[27];
            T2u = (((T2q) * (T2r)) + (T2s * T2t));
            T7v = ((T2q * T2t) - ((T2s) * (T2r)));
        }
        {
            E T2w, T2y, T2v, T2x;
            T2w = ri[(rs[46])];
            T2y = ii[(rs[46])];
            T2v = W[90];
            T2x = W[91];
            T2z = (((T2v) * (T2w)) + (T2x * T2y));
            T7w = ((T2v * T2y) - ((T2x) * (T2w)));
        }
        T2A = T2u + T2z;
        Tde = T7v + T7w;
        {
            E T2G, T7o, T2L, T7p;
            {
                E T2D, T2F, T2C, T2E;
                T2D = ri[(rs[6])];
                T2F = ii[(rs[6])];
                T2C = W[10];
                T2E = W[11];
                T2G = (((T2C) * (T2D)) + (T2E * T2F));
                T7o = ((T2C * T2F) - ((T2E) * (T2D)));
            }
            {
                E T2I, T2K, T2H, T2J;
                T2I = ri[(rs[38])];
                T2K = ii[(rs[38])];
                T2H = W[74];
                T2J = W[75];
                T2L = (((T2H) * (T2I)) + (T2J * T2K));
                T7p = ((T2H * T2K) - ((T2J) * (T2I)));
            }
            T2M = T2G + T2L;
            Tdj = T7o + T7p;
            T7n = T2G - T2L;
            T7q = T7o - T7p;
        }
        {
            E T2R, T7j, T2W, T7k;
            {
                E T2O, T2Q, T2N, T2P;
                T2O = ri[(rs[54])];
                T2Q = ii[(rs[54])];
                T2N = W[106];
                T2P = W[107];
                T2R = (((T2N) * (T2O)) + (T2P * T2Q));
                T7j = ((T2N * T2Q) - ((T2P) * (T2O)));
            }
            {
                E T2T, T2V, T2S, T2U;
                T2T = ri[(rs[22])];
                T2V = ii[(rs[22])];
                T2S = W[42];
                T2U = W[43];
                T2W = (((T2S) * (T2T)) + (T2U * T2V));
                T7k = ((T2S * T2V) - ((T2U) * (T2T)));
            }
            T2X = T2R + T2W;
            Tdk = T7j + T7k;
            T7i = T2R - T2W;
            T7l = T7j - T7k;
        }
        T2B = T2p + T2A;
        T2Y = T2M + T2X;
        Tfz = T2B - T2Y;
        TfA = Tdd + Tde;
        TfB = Tdj + Tdk;
        TfC = TfA - TfB;
        {
            E T7f, T7g, Tdi, Tdl;
            T7f = T7d - T7e;
            T7g = T2u - T2z;
            T7h = T7f + T7g;
            TaW = T7f - T7g;
            Tdi = T2p - T2A;
            Tdl = Tdj - Tdk;
            Tdm = Tdi - Tdl;
            TeM = Tdi + Tdl;
        }
        {
            E T7m, T7r, T7z, T7A;
            T7m = T7i - T7l;
            T7r = T7n + T7q;
            T7s = KP707106781 * (T7m - T7r);
            TaU = KP707106781 * (T7r + T7m);
            T7z = T7q - T7n;
            T7A = T7i + T7l;
            T7B = KP707106781 * (T7z - T7A);
            TaX = KP707106781 * (T7z + T7A);
        }
        {
            E Tdf, Tdg, T7u, T7x;
            Tdf = Tdd - Tde;
            Tdg = T2X - T2M;
            Tdh = Tdf - Tdg;
            TeL = Tdf + Tdg;
            T7u = T2j - T2o;
            T7x = T7v - T7w;
            T7y = T7u - T7x;
            TaT = T7u + T7x;
        }
    }
    {
        E T4D, T9e, T4I, T9f, T4J, Te8, T4O, T8A, T4T, T8B, T4U, Te9, T56, TdS, T8G;
        E T8H, T5h, TdT, T8J, T8M;
        {
            E T4A, T4C, T4z, T4B;
            T4A = ri[(rs[63])];
            T4C = ii[(rs[63])];
            T4z = W[124];
            T4B = W[125];
            T4D = (((T4z) * (T4A)) + (T4B * T4C));
            T9e = ((T4z * T4C) - ((T4B) * (T4A)));
        }
        {
            E T4F, T4H, T4E, T4G;
            T4F = ri[(rs[31])];
            T4H = ii[(rs[31])];
            T4E = W[60];
            T4G = W[61];
            T4I = (((T4E) * (T4F)) + (T4G * T4H));
            T9f = ((T4E * T4H) - ((T4G) * (T4F)));
        }
        T4J = T4D + T4I;
        Te8 = T9e + T9f;
        {
            E T4L, T4N, T4K, T4M;
            T4L = ri[(rs[15])];
            T4N = ii[(rs[15])];
            T4K = W[28];
            T4M = W[29];
            T4O = (((T4K) * (T4L)) + (T4M * T4N));
            T8A = ((T4K * T4N) - ((T4M) * (T4L)));
        }
        {
            E T4Q, T4S, T4P, T4R;
            T4Q = ri[(rs[47])];
            T4S = ii[(rs[47])];
            T4P = W[92];
            T4R = W[93];
            T4T = (((T4P) * (T4Q)) + (T4R * T4S));
            T8B = ((T4P * T4S) - ((T4R) * (T4Q)));
        }
        T4U = T4O + T4T;
        Te9 = T8A + T8B;
        {
            E T50, T8E, T55, T8F;
            {
                E T4X, T4Z, T4W, T4Y;
                T4X = ri[(rs[7])];
                T4Z = ii[(rs[7])];
                T4W = W[12];
                T4Y = W[13];
                T50 = (((T4W) * (T4X)) + (T4Y * T4Z));
                T8E = ((T4W * T4Z) - ((T4Y) * (T4X)));
            }
            {
                E T52, T54, T51, T53;
                T52 = ri[(rs[39])];
                T54 = ii[(rs[39])];
                T51 = W[76];
                T53 = W[77];
                T55 = (((T51) * (T52)) + (T53 * T54));
                T8F = ((T51 * T54) - ((T53) * (T52)));
            }
            T56 = T50 + T55;
            TdS = T8E + T8F;
            T8G = T8E - T8F;
            T8H = T50 - T55;
        }
        {
            E T5b, T8K, T5g, T8L;
            {
                E T58, T5a, T57, T59;
                T58 = ri[(rs[55])];
                T5a = ii[(rs[55])];
                T57 = W[108];
                T59 = W[109];
                T5b = (((T57) * (T58)) + (T59 * T5a));
                T8K = ((T57 * T5a) - ((T59) * (T58)));
            }
            {
                E T5d, T5f, T5c, T5e;
                T5d = ri[(rs[23])];
                T5f = ii[(rs[23])];
                T5c = W[44];
                T5e = W[45];
                T5g = (((T5c) * (T5d)) + (T5e * T5f));
                T8L = ((T5c * T5f) - ((T5e) * (T5d)));
            }
            T5h = T5b + T5g;
            TdT = T8K + T8L;
            T8J = T5b - T5g;
            T8M = T8K - T8L;
        }
        {
            E T4V, T5i, Tea, Teb;
            T4V = T4J + T4U;
            T5i = T56 + T5h;
            T5j = T4V + T5i;
            TfR = T4V - T5i;
            Tea = Te8 - Te9;
            Teb = T5h - T56;
            Tec = Tea - Teb;
            Tf0 = Tea + Teb;
        }
        {
            E TfW, TfX, T8z, T8C;
            TfW = Te8 + Te9;
            TfX = TdS + TdT;
            TfY = TfW - TfX;
            Tgy = TfW + TfX;
            T8z = T4D - T4I;
            T8C = T8A - T8B;
            T8D = T8z - T8C;
            Tbl = T8z + T8C;
        }
        {
            E T8I, T8N, T9j, T9k;
            T8I = T8G - T8H;
            T8N = T8J + T8M;
            T8O = KP707106781 * (T8I - T8N);
            Tbx = KP707106781 * (T8I + T8N);
            T9j = T8J - T8M;
            T9k = T8H + T8G;
            T9l = KP707106781 * (T9j - T9k);
            Tbm = KP707106781 * (T9k + T9j);
        }
        {
            E TdR, TdU, T9g, T9h;
            TdR = T4J - T4U;
            TdU = TdS - TdT;
            TdV = TdR - TdU;
            TeX = TdR + TdU;
            T9g = T9e - T9f;
            T9h = T4O - T4T;
            T9i = T9g + T9h;
            Tbw = T9g - T9h;
        }
    }
    {
        E T36, T7G, T3b, T7H, T3c, Tdq, T3h, T8m, T3m, T8n, T3n, Tdr, T3z, TdI, T7Q;
        E T7T, T3K, TdJ, T7L, T7O;
        {
            E T33, T35, T32, T34;
            T33 = ri[(rs[1])];
            T35 = ii[(rs[1])];
            T32 = W[0];
            T34 = W[1];
            T36 = (((T32) * (T33)) + (T34 * T35));
            T7G = ((T32 * T35) - ((T34) * (T33)));
        }
        {
            E T38, T3a, T37, T39;
            T38 = ri[(rs[33])];
            T3a = ii[(rs[33])];
            T37 = W[64];
            T39 = W[65];
            T3b = (((T37) * (T38)) + (T39 * T3a));
            T7H = ((T37 * T3a) - ((T39) * (T38)));
        }
        T3c = T36 + T3b;
        Tdq = T7G + T7H;
        {
            E T3e, T3g, T3d, T3f;
            T3e = ri[(rs[17])];
            T3g = ii[(rs[17])];
            T3d = W[32];
            T3f = W[33];
            T3h = (((T3d) * (T3e)) + (T3f * T3g));
            T8m = ((T3d * T3g) - ((T3f) * (T3e)));
        }
        {
            E T3j, T3l, T3i, T3k;
            T3j = ri[(rs[49])];
            T3l = ii[(rs[49])];
            T3i = W[96];
            T3k = W[97];
            T3m = (((T3i) * (T3j)) + (T3k * T3l));
            T8n = ((T3i * T3l) - ((T3k) * (T3j)));
        }
        T3n = T3h + T3m;
        Tdr = T8m + T8n;
        {
            E T3t, T7R, T3y, T7S;
            {
                E T3q, T3s, T3p, T3r;
                T3q = ri[(rs[9])];
                T3s = ii[(rs[9])];
                T3p = W[16];
                T3r = W[17];
                T3t = (((T3p) * (T3q)) + (T3r * T3s));
                T7R = ((T3p * T3s) - ((T3r) * (T3q)));
            }
            {
                E T3v, T3x, T3u, T3w;
                T3v = ri[(rs[41])];
                T3x = ii[(rs[41])];
                T3u = W[80];
                T3w = W[81];
                T3y = (((T3u) * (T3v)) + (T3w * T3x));
                T7S = ((T3u * T3x) - ((T3w) * (T3v)));
            }
            T3z = T3t + T3y;
            TdI = T7R + T7S;
            T7Q = T3t - T3y;
            T7T = T7R - T7S;
        }
        {
            E T3E, T7M, T3J, T7N;
            {
                E T3B, T3D, T3A, T3C;
                T3B = ri[(rs[57])];
                T3D = ii[(rs[57])];
                T3A = W[112];
                T3C = W[113];
                T3E = (((T3A) * (T3B)) + (T3C * T3D));
                T7M = ((T3A * T3D) - ((T3C) * (T3B)));
            }
            {
                E T3G, T3I, T3F, T3H;
                T3G = ri[(rs[25])];
                T3I = ii[(rs[25])];
                T3F = W[48];
                T3H = W[49];
                T3J = (((T3F) * (T3G)) + (T3H * T3I));
                T7N = ((T3F * T3I) - ((T3H) * (T3G)));
            }
            T3K = T3E + T3J;
            TdJ = T7M + T7N;
            T7L = T3E - T3J;
            T7O = T7M - T7N;
        }
        {
            E T3o, T3L, TdH, TdK;
            T3o = T3c + T3n;
            T3L = T3z + T3K;
            T3M = T3o + T3L;
            TfL = T3o - T3L;
            TdH = T3c - T3n;
            TdK = TdI - TdJ;
            TdL = TdH - TdK;
            TeQ = TdH + TdK;
        }
        {
            E TfG, TfH, T7I, T7J;
            TfG = Tdq + Tdr;
            TfH = TdI + TdJ;
            TfI = TfG - TfH;
            Tgt = TfG + TfH;
            T7I = T7G - T7H;
            T7J = T3h - T3m;
            T7K = T7I + T7J;
            Tb2 = T7I - T7J;
        }
        {
            E T7P, T7U, T8q, T8r;
            T7P = T7L - T7O;
            T7U = T7Q + T7T;
            T7V = KP707106781 * (T7P - T7U);
            Tbe = KP707106781 * (T7U + T7P);
            T8q = T7T - T7Q;
            T8r = T7L + T7O;
            T8s = KP707106781 * (T8q - T8r);
            Tb3 = KP707106781 * (T8q + T8r);
        }
        {
            E Tds, Tdt, T8l, T8o;
            Tds = Tdq - Tdr;
            Tdt = T3K - T3z;
            Tdu = Tds - Tdt;
            TeT = Tds + Tdt;
            T8l = T36 - T3b;
            T8o = T8m - T8n;
            T8p = T8l - T8o;
            Tbd = T8l + T8o;
        }
    }
    {
        E T3X, TdB, T8a, T8d, T4v, Tdx, T80, T85, T48, TdC, T8b, T8g, T4k, Tdw, T7X;
        E T84;
        {
            E T3R, T88, T3W, T89;
            {
                E T3O, T3Q, T3N, T3P;
                T3O = ri[(rs[5])];
                T3Q = ii[(rs[5])];
                T3N = W[8];
                T3P = W[9];
                T3R = (((T3N) * (T3O)) + (T3P * T3Q));
                T88 = ((T3N * T3Q) - ((T3P) * (T3O)));
            }
            {
                E T3T, T3V, T3S, T3U;
                T3T = ri[(rs[37])];
                T3V = ii[(rs[37])];
                T3S = W[72];
                T3U = W[73];
                T3W = (((T3S) * (T3T)) + (T3U * T3V));
                T89 = ((T3S * T3V) - ((T3U) * (T3T)));
            }
            T3X = T3R + T3W;
            TdB = T88 + T89;
            T8a = T88 - T89;
            T8d = T3R - T3W;
        }
        {
            E T4p, T7Y, T4u, T7Z;
            {
                E T4m, T4o, T4l, T4n;
                T4m = ri[(rs[13])];
                T4o = ii[(rs[13])];
                T4l = W[24];
                T4n = W[25];
                T4p = (((T4l) * (T4m)) + (T4n * T4o));
                T7Y = ((T4l * T4o) - ((T4n) * (T4m)));
            }
            {
                E T4r, T4t, T4q, T4s;
                T4r = ri[(rs[45])];
                T4t = ii[(rs[45])];
                T4q = W[88];
                T4s = W[89];
                T4u = (((T4q) * (T4r)) + (T4s * T4t));
                T7Z = ((T4q * T4t) - ((T4s) * (T4r)));
            }
            T4v = T4p + T4u;
            Tdx = T7Y + T7Z;
            T80 = T7Y - T7Z;
            T85 = T4p - T4u;
        }
        {
            E T42, T8e, T47, T8f;
            {
                E T3Z, T41, T3Y, T40;
                T3Z = ri[(rs[21])];
                T41 = ii[(rs[21])];
                T3Y = W[40];
                T40 = W[41];
                T42 = (((T3Y) * (T3Z)) + (T40 * T41));
                T8e = ((T3Y * T41) - ((T40) * (T3Z)));
            }
            {
                E T44, T46, T43, T45;
                T44 = ri[(rs[53])];
                T46 = ii[(rs[53])];
                T43 = W[104];
                T45 = W[105];
                T47 = (((T43) * (T44)) + (T45 * T46));
                T8f = ((T43 * T46) - ((T45) * (T44)));
            }
            T48 = T42 + T47;
            TdC = T8e + T8f;
            T8b = T42 - T47;
            T8g = T8e - T8f;
        }
        {
            E T4e, T82, T4j, T83;
            {
                E T4b, T4d, T4a, T4c;
                T4b = ri[(rs[61])];
                T4d = ii[(rs[61])];
                T4a = W[120];
                T4c = W[121];
                T4e = (((T4a) * (T4b)) + (T4c * T4d));
                T82 = ((T4a * T4d) - ((T4c) * (T4b)));
            }
            {
                E T4g, T4i, T4f, T4h;
                T4g = ri[(rs[29])];
                T4i = ii[(rs[29])];
                T4f = W[56];
                T4h = W[57];
                T4j = (((T4f) * (T4g)) + (T4h * T4i));
                T83 = ((T4f * T4i) - ((T4h) * (T4g)));
            }
            T4k = T4e + T4j;
            Tdw = T82 + T83;
            T7X = T4e - T4j;
            T84 = T82 - T83;
        }
        {
            E T49, T4w, TdA, TdD;
            T49 = T3X + T48;
            T4w = T4k + T4v;
            T4x = T49 + T4w;
            TfJ = T4w - T49;
            TdA = T3X - T48;
            TdD = TdB - TdC;
            TdE = TdA + TdD;
            TdM = TdD - TdA;
        }
        {
            E TfM, TfN, T81, T86;
            TfM = TdB + TdC;
            TfN = Tdw + Tdx;
            TfO = TfM - TfN;
            Tgu = TfM + TfN;
            T81 = T7X - T80;
            T86 = T84 + T85;
            T87 = ((KP382683432 * T81) - ((KP923879532) * (T86)));
            T8v = (((KP382683432) * (T86)) + (KP923879532 * T81));
        }
        {
            E T8c, T8h, Tb8, Tb9;
            T8c = T8a + T8b;
            T8h = T8d - T8g;
            T8i = (((KP923879532) * (T8c)) + (KP382683432 * T8h));
            T8u = ((KP382683432 * T8c) - ((KP923879532) * (T8h)));
            Tb8 = T8a - T8b;
            Tb9 = T8d + T8g;
            Tba = (((KP382683432) * (Tb8)) + (KP923879532 * Tb9));
            Tbg = ((KP923879532 * Tb8) - ((KP382683432) * (Tb9)));
        }
        {
            E Tdv, Tdy, Tb5, Tb6;
            Tdv = T4k - T4v;
            Tdy = Tdw - Tdx;
            Tdz = Tdv - Tdy;
            TdN = Tdv + Tdy;
            Tb5 = T7X + T80;
            Tb6 = T84 - T85;
            Tb7 = ((KP923879532 * Tb5) - ((KP382683432) * (Tb6)));
            Tbh = (((KP923879532) * (Tb6)) + (KP382683432 * Tb5));
        }
    }
    {
        E T5u, TdW, T8S, T8V, T62, Te3, T94, T99, T5F, TdX, T8T, T8Y, T5R, Te2, T93;
        E T96;
        {
            E T5o, T8Q, T5t, T8R;
            {
                E T5l, T5n, T5k, T5m;
                T5l = ri[(rs[3])];
                T5n = ii[(rs[3])];
                T5k = W[4];
                T5m = W[5];
                T5o = (((T5k) * (T5l)) + (T5m * T5n));
                T8Q = ((T5k * T5n) - ((T5m) * (T5l)));
            }
            {
                E T5q, T5s, T5p, T5r;
                T5q = ri[(rs[35])];
                T5s = ii[(rs[35])];
                T5p = W[68];
                T5r = W[69];
                T5t = (((T5p) * (T5q)) + (T5r * T5s));
                T8R = ((T5p * T5s) - ((T5r) * (T5q)));
            }
            T5u = T5o + T5t;
            TdW = T8Q + T8R;
            T8S = T8Q - T8R;
            T8V = T5o - T5t;
        }
        {
            E T5W, T97, T61, T98;
            {
                E T5T, T5V, T5S, T5U;
                T5T = ri[(rs[11])];
                T5V = ii[(rs[11])];
                T5S = W[20];
                T5U = W[21];
                T5W = (((T5S) * (T5T)) + (T5U * T5V));
                T97 = ((T5S * T5V) - ((T5U) * (T5T)));
            }
            {
                E T5Y, T60, T5X, T5Z;
                T5Y = ri[(rs[43])];
                T60 = ii[(rs[43])];
                T5X = W[84];
                T5Z = W[85];
                T61 = (((T5X) * (T5Y)) + (T5Z * T60));
                T98 = ((T5X * T60) - ((T5Z) * (T5Y)));
            }
            T62 = T5W + T61;
            Te3 = T97 + T98;
            T94 = T5W - T61;
            T99 = T97 - T98;
        }
        {
            E T5z, T8W, T5E, T8X;
            {
                E T5w, T5y, T5v, T5x;
                T5w = ri[(rs[19])];
                T5y = ii[(rs[19])];
                T5v = W[36];
                T5x = W[37];
                T5z = (((T5v) * (T5w)) + (T5x * T5y));
                T8W = ((T5v * T5y) - ((T5x) * (T5w)));
            }
            {
                E T5B, T5D, T5A, T5C;
                T5B = ri[(rs[51])];
                T5D = ii[(rs[51])];
                T5A = W[100];
                T5C = W[101];
                T5E = (((T5A) * (T5B)) + (T5C * T5D));
                T8X = ((T5A * T5D) - ((T5C) * (T5B)));
            }
            T5F = T5z + T5E;
            TdX = T8W + T8X;
            T8T = T5z - T5E;
            T8Y = T8W - T8X;
        }
        {
            E T5L, T91, T5Q, T92;
            {
                E T5I, T5K, T5H, T5J;
                T5I = ri[(rs[59])];
                T5K = ii[(rs[59])];
                T5H = W[116];
                T5J = W[117];
                T5L = (((T5H) * (T5I)) + (T5J * T5K));
                T91 = ((T5H * T5K) - ((T5J) * (T5I)));
            }
            {
                E T5N, T5P, T5M, T5O;
                T5N = ri[(rs[27])];
                T5P = ii[(rs[27])];
                T5M = W[52];
                T5O = W[53];
                T5Q = (((T5M) * (T5N)) + (T5O * T5P));
                T92 = ((T5M * T5P) - ((T5O) * (T5N)));
            }
            T5R = T5L + T5Q;
            Te2 = T91 + T92;
            T93 = T91 - T92;
            T96 = T5L - T5Q;
        }
        {
            E T5G, T63, Te1, Te4;
            T5G = T5u + T5F;
            T63 = T5R + T62;
            T64 = T5G + T63;
            TfZ = T63 - T5G;
            Te1 = T5R - T62;
            Te4 = Te2 - Te3;
            Te5 = Te1 + Te4;
            Ted = Te1 - Te4;
        }
        {
            E TfS, TfT, T8U, T8Z;
            TfS = TdW + TdX;
            TfT = Te2 + Te3;
            TfU = TfS - TfT;
            Tgz = TfS + TfT;
            T8U = T8S + T8T;
            T8Z = T8V - T8Y;
            T90 = ((KP382683432 * T8U) - ((KP923879532) * (T8Z)));
            T9o = (((KP923879532) * (T8U)) + (KP382683432 * T8Z));
        }
        {
            E T95, T9a, Tbr, Tbs;
            T95 = T93 + T94;
            T9a = T96 - T99;
            T9b = (((KP382683432) * (T95)) + (KP923879532 * T9a));
            T9n = ((KP382683432 * T9a) - ((KP923879532) * (T95)));
            Tbr = T93 - T94;
            Tbs = T96 + T99;
            Tbt = (((KP923879532) * (Tbr)) + (KP382683432 * Tbs));
            Tbz = ((KP923879532 * Tbs) - ((KP382683432) * (Tbr)));
        }
        {
            E TdY, TdZ, Tbo, Tbp;
            TdY = TdW - TdX;
            TdZ = T5u - T5F;
            Te0 = TdY - TdZ;
            Tee = TdZ + TdY;
            Tbo = T8S - T8T;
            Tbp = T8V + T8Y;
            Tbq = ((KP923879532 * Tbo) - ((KP382683432) * (Tbp)));
            TbA = (((KP382683432) * (Tbo)) + (KP923879532 * Tbp));
        }
    }
    {
        E T1t, Tgn, TgK, TgL, TgV, Th1, T30, Th0, T66, TgX, Tgw, TgE, TgB, TgF, Tgq;
        E TgM;
        {
            E TH, T1s, TgI, TgJ;
            TH = Tj + TG;
            T1s = T14 + T1r;
            T1t = TH + T1s;
            Tgn = TH - T1s;
            TgI = Tgt + Tgu;
            TgJ = Tgy + Tgz;
            TgK = TgI - TgJ;
            TgL = TgI + TgJ;
        }
        {
            E TgN, TgU, T2e, T2Z;
            TgN = Tfq + Tfr;
            TgU = TgO + TgT;
            TgV = TgN + TgU;
            Th1 = TgU - TgN;
            T2e = T1Q + T2d;
            T2Z = T2B + T2Y;
            T30 = T2e + T2Z;
            Th0 = T2Z - T2e;
        }
        {
            E T4y, T65, Tgs, Tgv;
            T4y = T3M + T4x;
            T65 = T5j + T64;
            T66 = T4y + T65;
            TgX = T65 - T4y;
            Tgs = T3M - T4x;
            Tgv = Tgt - Tgu;
            Tgw = Tgs + Tgv;
            TgE = Tgv - Tgs;
        }
        {
            E Tgx, TgA, Tgo, Tgp;
            Tgx = T5j - T64;
            TgA = Tgy - Tgz;
            TgB = Tgx - TgA;
            TgF = Tgx + TgA;
            Tgo = Tfu + Tfv;
            Tgp = TfA + TfB;
            Tgq = Tgo - Tgp;
            TgM = Tgo + Tgp;
        }
        {
            E T31, TgW, TgH, TgY;
            T31 = T1t + T30;
            ri[(rs[32])] = T31 - T66;
            ri[0] = T31 + T66;
            TgW = TgM + TgV;
            ii[0] = TgL + TgW;
            ii[(rs[32])] = TgW - TgL;
            TgH = T1t - T30;
            ri[(rs[48])] = TgH - TgK;
            ri[(rs[16])] = TgH + TgK;
            TgY = TgV - TgM;
            ii[(rs[16])] = TgX + TgY;
            ii[(rs[48])] = TgY - TgX;
        }
        {
            E Tgr, TgC, TgZ, Th2;
            Tgr = Tgn + Tgq;
            TgC = KP707106781 * (Tgw + TgB);
            ri[(rs[40])] = Tgr - TgC;
            ri[(rs[8])] = Tgr + TgC;
            TgZ = KP707106781 * (TgE + TgF);
            Th2 = Th0 + Th1;
            ii[(rs[8])] = TgZ + Th2;
            ii[(rs[40])] = Th2 - TgZ;
        }
        {
            E TgD, TgG, Th3, Th4;
            TgD = Tgn - Tgq;
            TgG = KP707106781 * (TgE - TgF);
            ri[(rs[56])] = TgD - TgG;
            ri[(rs[24])] = TgD + TgG;
            Th3 = KP707106781 * (TgB - Tgw);
            Th4 = Th1 - Th0;
            ii[(rs[24])] = Th3 + Th4;
            ii[(rs[56])] = Th4 - Th3;
        }
    }
    {
        E Tft, Tg7, Tgh, Tgl, Th9, Thf, TfE, Th6, TfQ, Tg4, Tga, The, Tge, Tgk, Tg1;
        E Tg5;
        {
            E Tfp, Tfs, Tgf, Tgg;
            Tfp = Tj - TG;
            Tfs = Tfq - Tfr;
            Tft = Tfp - Tfs;
            Tg7 = Tfp + Tfs;
            Tgf = TfR + TfU;
            Tgg = TfY + TfZ;
            Tgh = ((KP923879532 * Tgf) - ((KP382683432) * (Tgg)));
            Tgl = (((KP923879532) * (Tgg)) + (KP382683432 * Tgf));
        }
        {
            E Th7, Th8, Tfy, TfD;
            Th7 = T1r - T14;
            Th8 = TgT - TgO;
            Th9 = Th7 + Th8;
            Thf = Th8 - Th7;
            Tfy = Tfw - Tfx;
            TfD = Tfz + TfC;
            TfE = KP707106781 * (Tfy - TfD);
            Th6 = KP707106781 * (Tfy + TfD);
        }
        {
            E TfK, TfP, Tg8, Tg9;
            TfK = TfI - TfJ;
            TfP = TfL - TfO;
            TfQ = (((KP923879532) * (TfK)) + (KP382683432 * TfP));
            Tg4 = ((KP382683432 * TfK) - ((KP923879532) * (TfP)));
            Tg8 = Tfx + Tfw;
            Tg9 = Tfz - TfC;
            Tga = KP707106781 * (Tg8 + Tg9);
            The = KP707106781 * (Tg9 - Tg8);
        }
        {
            E Tgc, Tgd, TfV, Tg0;
            Tgc = TfI + TfJ;
            Tgd = TfL + TfO;
            Tge = (((KP382683432) * (Tgc)) + (KP923879532 * Tgd));
            Tgk = ((KP923879532 * Tgc) - ((KP382683432) * (Tgd)));
            TfV = TfR - TfU;
            Tg0 = TfY - TfZ;
            Tg1 = ((KP382683432 * TfV) - ((KP923879532) * (Tg0)));
            Tg5 = (((KP382683432) * (Tg0)) + (KP923879532 * TfV));
        }
        {
            E TfF, Tg2, Thd, Thg;
            TfF = Tft + TfE;
            Tg2 = TfQ + Tg1;
            ri[(rs[44])] = TfF - Tg2;
            ri[(rs[12])] = TfF + Tg2;
            Thd = Tg4 + Tg5;
            Thg = The + Thf;
            ii[(rs[12])] = Thd + Thg;
            ii[(rs[44])] = Thg - Thd;
        }
        {
            E Tg3, Tg6, Thh, Thi;
            Tg3 = Tft - TfE;
            Tg6 = Tg4 - Tg5;
            ri[(rs[60])] = Tg3 - Tg6;
            ri[(rs[28])] = Tg3 + Tg6;
            Thh = Tg1 - TfQ;
            Thi = Thf - The;
            ii[(rs[28])] = Thh + Thi;
            ii[(rs[60])] = Thi - Thh;
        }
        {
            E Tgb, Tgi, Th5, Tha;
            Tgb = Tg7 + Tga;
            Tgi = Tge + Tgh;
            ri[(rs[36])] = Tgb - Tgi;
            ri[(rs[4])] = Tgb + Tgi;
            Th5 = Tgk + Tgl;
            Tha = Th6 + Th9;
            ii[(rs[4])] = Th5 + Tha;
            ii[(rs[36])] = Tha - Th5;
        }
        {
            E Tgj, Tgm, Thb, Thc;
            Tgj = Tg7 - Tga;
            Tgm = Tgk - Tgl;
            ri[(rs[52])] = Tgj - Tgm;
            ri[(rs[20])] = Tgj + Tgm;
            Thb = Tgh - Tge;
            Thc = Th9 - Th6;
            ii[(rs[20])] = Thb + Thc;
            ii[(rs[52])] = Thc - Thb;
        }
    }
    {
        E Td1, Ten, Tdo, ThA, ThD, ThJ, Teq, ThI, Teh, TeB, Tel, Tex, TdQ, TeA, Tek;
        E Teu;
        {
            E TcP, Td0, Teo, Tep;
            TcP = TcL - TcO;
            Td0 = KP707106781 * (TcU - TcZ);
            Td1 = TcP - Td0;
            Ten = TcP + Td0;
            {
                E Tdc, Tdn, ThB, ThC;
                Tdc = ((KP382683432 * Td6) - ((KP923879532) * (Tdb)));
                Tdn = (((KP382683432) * (Tdh)) + (KP923879532 * Tdm));
                Tdo = Tdc - Tdn;
                ThA = Tdc + Tdn;
                ThB = KP707106781 * (TeF - TeE);
                ThC = Thn - Thm;
                ThD = ThB + ThC;
                ThJ = ThC - ThB;
            }
            Teo = (((KP923879532) * (Td6)) + (KP382683432 * Tdb));
            Tep = ((KP382683432 * Tdm) - ((KP923879532) * (Tdh)));
            Teq = Teo + Tep;
            ThI = Tep - Teo;
            {
                E Te7, Tev, Teg, Tew, Te6, Tef;
                Te6 = KP707106781 * (Te0 - Te5);
                Te7 = TdV - Te6;
                Tev = TdV + Te6;
                Tef = KP707106781 * (Ted - Tee);
                Teg = Tec - Tef;
                Tew = Tec + Tef;
                Teh = ((KP195090322 * Te7) - ((KP980785280) * (Teg)));
                TeB = (((KP831469612) * (Tew)) + (KP555570233 * Tev));
                Tel = (((KP195090322) * (Teg)) + (KP980785280 * Te7));
                Tex = ((KP831469612 * Tev) - ((KP555570233) * (Tew)));
            }
            {
                E TdG, Tes, TdP, Tet, TdF, TdO;
                TdF = KP707106781 * (Tdz - TdE);
                TdG = Tdu - TdF;
                Tes = Tdu + TdF;
                TdO = KP707106781 * (TdM - TdN);
                TdP = TdL - TdO;
                Tet = TdL + TdO;
                TdQ = (((KP980785280) * (TdG)) + (KP195090322 * TdP));
                TeA = ((KP831469612 * Tes) - ((KP555570233) * (Tet)));
                Tek = ((KP195090322 * TdG) - ((KP980785280) * (TdP)));
                Teu = (((KP555570233) * (Tes)) + (KP831469612 * Tet));
            }
        }
        {
            E Tdp, Tei, ThH, ThK;
            Tdp = Td1 + Tdo;
            Tei = TdQ + Teh;
            ri[(rs[46])] = Tdp - Tei;
            ri[(rs[14])] = Tdp + Tei;
            ThH = Tek + Tel;
            ThK = ThI + ThJ;
            ii[(rs[14])] = ThH + ThK;
            ii[(rs[46])] = ThK - ThH;
        }
        {
            E Tej, Tem, ThL, ThM;
            Tej = Td1 - Tdo;
            Tem = Tek - Tel;
            ri[(rs[62])] = Tej - Tem;
            ri[(rs[30])] = Tej + Tem;
            ThL = Teh - TdQ;
            ThM = ThJ - ThI;
            ii[(rs[30])] = ThL + ThM;
            ii[(rs[62])] = ThM - ThL;
        }
        {
            E Ter, Tey, Thz, ThE;
            Ter = Ten + Teq;
            Tey = Teu + Tex;
            ri[(rs[38])] = Ter - Tey;
            ri[(rs[6])] = Ter + Tey;
            Thz = TeA + TeB;
            ThE = ThA + ThD;
            ii[(rs[6])] = Thz + ThE;
            ii[(rs[38])] = ThE - Thz;
        }
        {
            E Tez, TeC, ThF, ThG;
            Tez = Ten - Teq;
            TeC = TeA - TeB;
            ri[(rs[54])] = Tez - TeC;
            ri[(rs[22])] = Tez + TeC;
            ThF = Tex - Teu;
            ThG = ThD - ThA;
            ii[(rs[22])] = ThF + ThG;
            ii[(rs[54])] = ThG - ThF;
        }
    }
    {
        E TeH, Tf9, TeO, Thk, Thp, Thv, Tfc, Thu, Tf3, Tfn, Tf7, Tfj, TeW, Tfm, Tf6;
        E Tfg;
        {
            E TeD, TeG, Tfa, Tfb;
            TeD = TcL + TcO;
            TeG = KP707106781 * (TeE + TeF);
            TeH = TeD - TeG;
            Tf9 = TeD + TeG;
            {
                E TeK, TeN, Thl, Tho;
                TeK = ((KP923879532 * TeI) - ((KP382683432) * (TeJ)));
                TeN = (((KP923879532) * (TeL)) + (KP382683432 * TeM));
                TeO = TeK - TeN;
                Thk = TeK + TeN;
                Thl = KP707106781 * (TcU + TcZ);
                Tho = Thm + Thn;
                Thp = Thl + Tho;
                Thv = Tho - Thl;
            }
            Tfa = (((KP382683432) * (TeI)) + (KP923879532 * TeJ));
            Tfb = ((KP923879532 * TeM) - ((KP382683432) * (TeL)));
            Tfc = Tfa + Tfb;
            Thu = Tfb - Tfa;
            {
                E TeZ, Tfh, Tf2, Tfi, TeY, Tf1;
                TeY = KP707106781 * (Tee + Ted);
                TeZ = TeX - TeY;
                Tfh = TeX + TeY;
                Tf1 = KP707106781 * (Te0 + Te5);
                Tf2 = Tf0 - Tf1;
                Tfi = Tf0 + Tf1;
                Tf3 = ((KP555570233 * TeZ) - ((KP831469612) * (Tf2)));
                Tfn = (((KP195090322) * (Tfh)) + (KP980785280 * Tfi));
                Tf7 = (((KP831469612) * (TeZ)) + (KP555570233 * Tf2));
                Tfj = ((KP980785280 * Tfh) - ((KP195090322) * (Tfi)));
            }
            {
                E TeS, Tfe, TeV, Tff, TeR, TeU;
                TeR = KP707106781 * (TdE + Tdz);
                TeS = TeQ - TeR;
                Tfe = TeQ + TeR;
                TeU = KP707106781 * (TdM + TdN);
                TeV = TeT - TeU;
                Tff = TeT + TeU;
                TeW = (((KP555570233) * (TeS)) + (KP831469612 * TeV));
                Tfm = ((KP980785280 * Tff) - ((KP195090322) * (Tfe)));
                Tf6 = ((KP555570233 * TeV) - ((KP831469612) * (TeS)));
                Tfg = (((KP980785280) * (Tfe)) + (KP195090322 * Tff));
            }
        }
        {
            E TeP, Tf4, Tht, Thw;
            TeP = TeH + TeO;
            Tf4 = TeW + Tf3;
            ri[(rs[42])] = TeP - Tf4;
            ri[(rs[10])] = TeP + Tf4;
            Tht = Tf6 + Tf7;
            Thw = Thu + Thv;
            ii[(rs[10])] = Tht + Thw;
            ii[(rs[42])] = Thw - Tht;
        }
        {
            E Tf5, Tf8, Thx, Thy;
            Tf5 = TeH - TeO;
            Tf8 = Tf6 - Tf7;
            ri[(rs[58])] = Tf5 - Tf8;
            ri[(rs[26])] = Tf5 + Tf8;
            Thx = Tf3 - TeW;
            Thy = Thv - Thu;
            ii[(rs[26])] = Thx + Thy;
            ii[(rs[58])] = Thy - Thx;
        }
        {
            E Tfd, Tfk, Thj, Thq;
            Tfd = Tf9 + Tfc;
            Tfk = Tfg + Tfj;
            ri[(rs[34])] = Tfd - Tfk;
            ri[(rs[2])] = Tfd + Tfk;
            Thj = Tfm + Tfn;
            Thq = Thk + Thp;
            ii[(rs[2])] = Thj + Thq;
            ii[(rs[34])] = Thq - Thj;
        }
        {
            E Tfl, Tfo, Thr, Ths;
            Tfl = Tf9 - Tfc;
            Tfo = Tfm - Tfn;
            ri[(rs[50])] = Tfl - Tfo;
            ri[(rs[18])] = Tfl + Tfo;
            Thr = Tfj - Tfg;
            Ths = Thp - Thk;
            ii[(rs[18])] = Thr + Ths;
            ii[(rs[50])] = Ths - Thr;
        }
    }
    {
        E T6L, T9x, TiD, TiJ, T7E, TiI, T9A, TiA, T8y, T9K, T9u, T9E, T9r, T9L, T9v;
        E T9H;
        {
            E T6n, T6K, TiB, TiC;
            T6n = T6b - T6m;
            T6K = T6y - T6J;
            T6L = T6n - T6K;
            T9x = T6n + T6K;
            TiB = T9P - T9O;
            TiC = Tin - Tim;
            TiD = TiB + TiC;
            TiJ = TiC - TiB;
        }
        {
            E T7c, T9y, T7D, T9z;
            {
                E T72, T7b, T7t, T7C;
                T72 = T6Q - T71;
                T7b = T77 - T7a;
                T7c = ((KP195090322 * T72) - ((KP980785280) * (T7b)));
                T9y = (((KP980785280) * (T72)) + (KP195090322 * T7b));
                T7t = T7h - T7s;
                T7C = T7y - T7B;
                T7D = (((KP195090322) * (T7t)) + (KP980785280 * T7C));
                T9z = ((KP195090322 * T7C) - ((KP980785280) * (T7t)));
            }
            T7E = T7c - T7D;
            TiI = T9z - T9y;
            T9A = T9y + T9z;
            TiA = T7c + T7D;
        }
        {
            E T8k, T9C, T8x, T9D;
            {
                E T7W, T8j, T8t, T8w;
                T7W = T7K - T7V;
                T8j = T87 - T8i;
                T8k = T7W - T8j;
                T9C = T7W + T8j;
                T8t = T8p - T8s;
                T8w = T8u - T8v;
                T8x = T8t - T8w;
                T9D = T8t + T8w;
            }
            T8y = (((KP995184726) * (T8k)) + (KP098017140 * T8x));
            T9K = ((KP773010453 * T9C) - ((KP634393284) * (T9D)));
            T9u = ((KP098017140 * T8k) - ((KP995184726) * (T8x)));
            T9E = (((KP634393284) * (T9C)) + (KP773010453 * T9D));
        }
        {
            E T9d, T9F, T9q, T9G;
            {
                E T8P, T9c, T9m, T9p;
                T8P = T8D - T8O;
                T9c = T90 - T9b;
                T9d = T8P - T9c;
                T9F = T8P + T9c;
                T9m = T9i - T9l;
                T9p = T9n - T9o;
                T9q = T9m - T9p;
                T9G = T9m + T9p;
            }
            T9r = ((KP098017140 * T9d) - ((KP995184726) * (T9q)));
            T9L = (((KP773010453) * (T9G)) + (KP634393284 * T9F));
            T9v = (((KP098017140) * (T9q)) + (KP995184726 * T9d));
            T9H = ((KP773010453 * T9F) - ((KP634393284) * (T9G)));
        }
        {
            E T7F, T9s, TiH, TiK;
            T7F = T6L + T7E;
            T9s = T8y + T9r;
            ri[(rs[47])] = T7F - T9s;
            ri[(rs[15])] = T7F + T9s;
            TiH = T9u + T9v;
            TiK = TiI + TiJ;
            ii[(rs[15])] = TiH + TiK;
            ii[(rs[47])] = TiK - TiH;
        }
        {
            E T9t, T9w, TiL, TiM;
            T9t = T6L - T7E;
            T9w = T9u - T9v;
            ri[(rs[63])] = T9t - T9w;
            ri[(rs[31])] = T9t + T9w;
            TiL = T9r - T8y;
            TiM = TiJ - TiI;
            ii[(rs[31])] = TiL + TiM;
            ii[(rs[63])] = TiM - TiL;
        }
        {
            E T9B, T9I, Tiz, TiE;
            T9B = T9x + T9A;
            T9I = T9E + T9H;
            ri[(rs[39])] = T9B - T9I;
            ri[(rs[7])] = T9B + T9I;
            Tiz = T9K + T9L;
            TiE = TiA + TiD;
            ii[(rs[7])] = Tiz + TiE;
            ii[(rs[39])] = TiE - Tiz;
        }
        {
            E T9J, T9M, TiF, TiG;
            T9J = T9x - T9A;
            T9M = T9K - T9L;
            ri[(rs[55])] = T9J - T9M;
            ri[(rs[23])] = T9J + T9M;
            TiF = T9H - T9E;
            TiG = TiD - TiA;
            ii[(rs[23])] = TiF + TiG;
            ii[(rs[55])] = TiG - TiF;
        }
    }
    {
        E TaL, TbJ, Ti9, Tif, Tb0, Tie, TbM, Ti6, Tbk, TbW, TbG, TbQ, TbD, TbX, TbH;
        E TbT;
        {
            E TaD, TaK, Ti7, Ti8;
            TaD = Taz - TaC;
            TaK = TaG - TaJ;
            TaL = TaD - TaK;
            TbJ = TaD + TaK;
            Ti7 = Tc1 - Tc0;
            Ti8 = ThT - ThQ;
            Ti9 = Ti7 + Ti8;
            Tif = Ti8 - Ti7;
        }
        {
            E TaS, TbK, TaZ, TbL;
            {
                E TaO, TaR, TaV, TaY;
                TaO = TaM - TaN;
                TaR = TaP - TaQ;
                TaS = ((KP555570233 * TaO) - ((KP831469612) * (TaR)));
                TbK = (((KP555570233) * (TaR)) + (KP831469612 * TaO));
                TaV = TaT - TaU;
                TaY = TaW - TaX;
                TaZ = (((KP831469612) * (TaV)) + (KP555570233 * TaY));
                TbL = ((KP555570233 * TaV) - ((KP831469612) * (TaY)));
            }
            Tb0 = TaS - TaZ;
            Tie = TbL - TbK;
            TbM = TbK + TbL;
            Ti6 = TaS + TaZ;
        }
        {
            E Tbc, TbO, Tbj, TbP;
            {
                E Tb4, Tbb, Tbf, Tbi;
                Tb4 = Tb2 - Tb3;
                Tbb = Tb7 - Tba;
                Tbc = Tb4 - Tbb;
                TbO = Tb4 + Tbb;
                Tbf = Tbd - Tbe;
                Tbi = Tbg - Tbh;
                Tbj = Tbf - Tbi;
                TbP = Tbf + Tbi;
            }
            Tbk = (((KP956940335) * (Tbc)) + (KP290284677 * Tbj));
            TbW = ((KP881921264 * TbO) - ((KP471396736) * (TbP)));
            TbG = ((KP290284677 * Tbc) - ((KP956940335) * (Tbj)));
            TbQ = (((KP471396736) * (TbO)) + (KP881921264 * TbP));
        }
        {
            E Tbv, TbR, TbC, TbS;
            {
                E Tbn, Tbu, Tby, TbB;
                Tbn = Tbl - Tbm;
                Tbu = Tbq - Tbt;
                Tbv = Tbn - Tbu;
                TbR = Tbn + Tbu;
                Tby = Tbw - Tbx;
                TbB = Tbz - TbA;
                TbC = Tby - TbB;
                TbS = Tby + TbB;
            }
            TbD = ((KP290284677 * Tbv) - ((KP956940335) * (TbC)));
            TbX = (((KP881921264) * (TbS)) + (KP471396736 * TbR));
            TbH = (((KP290284677) * (TbC)) + (KP956940335 * Tbv));
            TbT = ((KP881921264 * TbR) - ((KP471396736) * (TbS)));
        }
        {
            E Tb1, TbE, Tid, Tig;
            Tb1 = TaL + Tb0;
            TbE = Tbk + TbD;
            ri[(rs[45])] = Tb1 - TbE;
            ri[(rs[13])] = Tb1 + TbE;
            Tid = TbG + TbH;
            Tig = Tie + Tif;
            ii[(rs[13])] = Tid + Tig;
            ii[(rs[45])] = Tig - Tid;
        }
        {
            E TbF, TbI, Tih, Tii;
            TbF = TaL - Tb0;
            TbI = TbG - TbH;
            ri[(rs[61])] = TbF - TbI;
            ri[(rs[29])] = TbF + TbI;
            Tih = TbD - Tbk;
            Tii = Tif - Tie;
            ii[(rs[29])] = Tih + Tii;
            ii[(rs[61])] = Tii - Tih;
        }
        {
            E TbN, TbU, Ti5, Tia;
            TbN = TbJ + TbM;
            TbU = TbQ + TbT;
            ri[(rs[37])] = TbN - TbU;
            ri[(rs[5])] = TbN + TbU;
            Ti5 = TbW + TbX;
            Tia = Ti6 + Ti9;
            ii[(rs[5])] = Ti5 + Tia;
            ii[(rs[37])] = Tia - Ti5;
        }
        {
            E TbV, TbY, Tib, Tic;
            TbV = TbJ - TbM;
            TbY = TbW - TbX;
            ri[(rs[53])] = TbV - TbY;
            ri[(rs[21])] = TbV + TbY;
            Tib = TbT - TbQ;
            Tic = Ti9 - Ti6;
            ii[(rs[21])] = Tib + Tic;
            ii[(rs[53])] = Tic - Tib;
        }
    }
    {
        E Tc3, Tcv, ThV, Ti1, Tca, Ti0, Tcy, ThO, Tci, TcI, Tcs, TcC, Tcp, TcJ, Tct;
        E TcF;
        {
            E TbZ, Tc2, ThP, ThU;
            TbZ = Taz + TaC;
            Tc2 = Tc0 + Tc1;
            Tc3 = TbZ - Tc2;
            Tcv = TbZ + Tc2;
            ThP = TaG + TaJ;
            ThU = ThQ + ThT;
            ThV = ThP + ThU;
            Ti1 = ThU - ThP;
        }
        {
            E Tc6, Tcw, Tc9, Tcx;
            {
                E Tc4, Tc5, Tc7, Tc8;
                Tc4 = TaM + TaN;
                Tc5 = TaP + TaQ;
                Tc6 = ((KP980785280 * Tc4) - ((KP195090322) * (Tc5)));
                Tcw = (((KP980785280) * (Tc5)) + (KP195090322 * Tc4));
                Tc7 = TaT + TaU;
                Tc8 = TaW + TaX;
                Tc9 = (((KP195090322) * (Tc7)) + (KP980785280 * Tc8));
                Tcx = ((KP980785280 * Tc7) - ((KP195090322) * (Tc8)));
            }
            Tca = Tc6 - Tc9;
            Ti0 = Tcx - Tcw;
            Tcy = Tcw + Tcx;
            ThO = Tc6 + Tc9;
        }
        {
            E Tce, TcA, Tch, TcB;
            {
                E Tcc, Tcd, Tcf, Tcg;
                Tcc = Tbd + Tbe;
                Tcd = Tba + Tb7;
                Tce = Tcc - Tcd;
                TcA = Tcc + Tcd;
                Tcf = Tb2 + Tb3;
                Tcg = Tbg + Tbh;
                Tch = Tcf - Tcg;
                TcB = Tcf + Tcg;
            }
            Tci = (((KP634393284) * (Tce)) + (KP773010453 * Tch));
            TcI = ((KP995184726 * TcB) - ((KP098017140) * (TcA)));
            Tcs = ((KP634393284 * Tch) - ((KP773010453) * (Tce)));
            TcC = (((KP995184726) * (TcA)) + (KP098017140 * TcB));
        }
        {
            E Tcl, TcD, Tco, TcE;
            {
                E Tcj, Tck, Tcm, Tcn;
                Tcj = Tbl + Tbm;
                Tck = TbA + Tbz;
                Tcl = Tcj - Tck;
                TcD = Tcj + Tck;
                Tcm = Tbw + Tbx;
                Tcn = Tbq + Tbt;
                Tco = Tcm - Tcn;
                TcE = Tcm + Tcn;
            }
            Tcp = ((KP634393284 * Tcl) - ((KP773010453) * (Tco)));
            TcJ = (((KP098017140) * (TcD)) + (KP995184726 * TcE));
            Tct = (((KP773010453) * (Tcl)) + (KP634393284 * Tco));
            TcF = ((KP995184726 * TcD) - ((KP098017140) * (TcE)));
        }
        {
            E Tcb, Tcq, ThZ, Ti2;
            Tcb = Tc3 + Tca;
            Tcq = Tci + Tcp;
            ri[(rs[41])] = Tcb - Tcq;
            ri[(rs[9])] = Tcb + Tcq;
            ThZ = Tcs + Tct;
            Ti2 = Ti0 + Ti1;
            ii[(rs[9])] = ThZ + Ti2;
            ii[(rs[41])] = Ti2 - ThZ;
        }
        {
            E Tcr, Tcu, Ti3, Ti4;
            Tcr = Tc3 - Tca;
            Tcu = Tcs - Tct;
            ri[(rs[57])] = Tcr - Tcu;
            ri[(rs[25])] = Tcr + Tcu;
            Ti3 = Tcp - Tci;
            Ti4 = Ti1 - Ti0;
            ii[(rs[25])] = Ti3 + Ti4;
            ii[(rs[57])] = Ti4 - Ti3;
        }
        {
            E Tcz, TcG, ThN, ThW;
            Tcz = Tcv + Tcy;
            TcG = TcC + TcF;
            ri[(rs[33])] = Tcz - TcG;
            ri[(rs[1])] = Tcz + TcG;
            ThN = TcI + TcJ;
            ThW = ThO + ThV;
            ii[(rs[1])] = ThN + ThW;
            ii[(rs[33])] = ThW - ThN;
        }
        {
            E TcH, TcK, ThX, ThY;
            TcH = Tcv - Tcy;
            TcK = TcI - TcJ;
            ri[(rs[49])] = TcH - TcK;
            ri[(rs[17])] = TcH + TcK;
            ThX = TcF - TcC;
            ThY = ThV - ThO;
            ii[(rs[17])] = ThX + ThY;
            ii[(rs[49])] = ThY - ThX;
        }
    }
    {
        E T9R, Taj, Tip, Tiv, T9Y, Tiu, Tam, Tik, Ta6, Taw, Tag, Taq, Tad, Tax, Tah;
        E Tat;
        {
            E T9N, T9Q, Til, Tio;
            T9N = T6b + T6m;
            T9Q = T9O + T9P;
            T9R = T9N - T9Q;
            Taj = T9N + T9Q;
            Til = T6y + T6J;
            Tio = Tim + Tin;
            Tip = Til + Tio;
            Tiv = Tio - Til;
        }
        {
            E T9U, Tak, T9X, Tal;
            {
                E T9S, T9T, T9V, T9W;
                T9S = T6Q + T71;
                T9T = T77 + T7a;
                T9U = ((KP831469612 * T9S) - ((KP555570233) * (T9T)));
                Tak = (((KP555570233) * (T9S)) + (KP831469612 * T9T));
                T9V = T7h + T7s;
                T9W = T7y + T7B;
                T9X = (((KP831469612) * (T9V)) + (KP555570233 * T9W));
                Tal = ((KP831469612 * T9W) - ((KP555570233) * (T9V)));
            }
            T9Y = T9U - T9X;
            Tiu = Tal - Tak;
            Tam = Tak + Tal;
            Tik = T9U + T9X;
        }
        {
            E Ta2, Tao, Ta5, Tap;
            {
                E Ta0, Ta1, Ta3, Ta4;
                Ta0 = T8p + T8s;
                Ta1 = T8i + T87;
                Ta2 = Ta0 - Ta1;
                Tao = Ta0 + Ta1;
                Ta3 = T7K + T7V;
                Ta4 = T8u + T8v;
                Ta5 = Ta3 - Ta4;
                Tap = Ta3 + Ta4;
            }
            Ta6 = (((KP471396736) * (Ta2)) + (KP881921264 * Ta5));
            Taw = ((KP956940335 * Tap) - ((KP290284677) * (Tao)));
            Tag = ((KP471396736 * Ta5) - ((KP881921264) * (Ta2)));
            Taq = (((KP956940335) * (Tao)) + (KP290284677 * Tap));
        }
        {
            E Ta9, Tar, Tac, Tas;
            {
                E Ta7, Ta8, Taa, Tab;
                Ta7 = T8D + T8O;
                Ta8 = T9o + T9n;
                Ta9 = Ta7 - Ta8;
                Tar = Ta7 + Ta8;
                Taa = T9i + T9l;
                Tab = T90 + T9b;
                Tac = Taa - Tab;
                Tas = Taa + Tab;
            }
            Tad = ((KP471396736 * Ta9) - ((KP881921264) * (Tac)));
            Tax = (((KP290284677) * (Tar)) + (KP956940335 * Tas));
            Tah = (((KP881921264) * (Ta9)) + (KP471396736 * Tac));
            Tat = ((KP956940335 * Tar) - ((KP290284677) * (Tas)));
        }
        {
            E T9Z, Tae, Tit, Tiw;
            T9Z = T9R + T9Y;
            Tae = Ta6 + Tad;
            ri[(rs[43])] = T9Z - Tae;
            ri[(rs[11])] = T9Z + Tae;
            Tit = Tag + Tah;
            Tiw = Tiu + Tiv;
            ii[(rs[11])] = Tit + Tiw;
            ii[(rs[43])] = Tiw - Tit;
        }
        {
            E Taf, Tai, Tix, Tiy;
            Taf = T9R - T9Y;
            Tai = Tag - Tah;
            ri[(rs[59])] = Taf - Tai;
            ri[(rs[27])] = Taf + Tai;
            Tix = Tad - Ta6;
            Tiy = Tiv - Tiu;
            ii[(rs[27])] = Tix + Tiy;
            ii[(rs[59])] = Tiy - Tix;
        }
        {
            E Tan, Tau, Tij, Tiq;
            Tan = Taj + Tam;
            Tau = Taq + Tat;
            ri[(rs[35])] = Tan - Tau;
            ri[(rs[3])] = Tan + Tau;
            Tij = Taw + Tax;
            Tiq = Tik + Tip;
            ii[(rs[3])] = Tij + Tiq;
            ii[(rs[35])] = Tiq - Tij;
        }
        {
            E Tav, Tay, Tir, Tis;
            Tav = Taj - Tam;
            Tay = Taw - Tax;
            ri[(rs[51])] = Tav - Tay;
            ri[(rs[19])] = Tav + Tay;
            Tir = Tat - Taq;
            Tis = Tip - Tik;
            ii[(rs[19])] = Tir + Tis;
            ii[(rs[51])] = Tis - Tir;
        }
    }
}

}
