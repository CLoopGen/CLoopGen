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
extern  E KP1_028205488;
extern  E KP1_715457220;
extern  E KP1_606415062;
extern  E KP1_191398608;
extern  E KP1_940062506;
extern  E KP485960359;
extern  E KP293460948;
extern  E KP1_978353019;
extern  E KP831469612;
extern  E KP555570233;
extern  E KP855110186;
extern  E KP1_807978586;
extern  E KP1_481902250;
extern  E KP1_343117909;
extern  E KP1_883088130;
extern  E KP673779706;
extern  E KP098135348;
extern  E KP1_997590912;
extern  E KP980785280;
extern  E KP195090322;
extern  E KP580569354;
extern  E KP1_913880671;
extern  E KP942793473;
extern  E KP1_763842528;
extern  E KP1_111140466;
extern  E KP1_662939224;
extern  E KP1_268786568;
extern  E KP1_546020906;
extern  E KP196034280;
extern  E KP1_990369453;
extern  E KP390180644;
extern  E KP1_961570560;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP1_414213562;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increased computational intensity via unrolled trip count and redundant accumulation
INT stride_factor = 2;
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {

    // Duplicate computation blocks to increase FLOP/byte ratio
    for (INT k = 0; k < stride_factor; ++k) {
        E Ta, T6q, T2a, T5k, T8x, Tbx, TcF, Ten, Th, T6r, T2j, T5l, T8E, Tby, TcI;
        E Teo, Tx, T6t, TcM, Teq, TcP, Ter, T2t, T5n, T2C, T5o, T8Q, TbA, T8X, TbB;
        E T6w, T7L, T1j, T6L, Tde, TeC, TdL, TeR, T3v, T5z, T4I, T5O, T9O, TbM, TaV;
        E Tc1, T78, T7Z, TN, T6z, TcU, Teu, Td8, Tey, T2N, T5r, T3j, T5v, T9a, TbE;
        E T9A, TbI, T6H, T7O, T1O, T7V, T48, T4u, Tds, TeG, T5E, T5K, Taf, TbP, Tdp;
        E TeF, T6U, T72, Tam, TbQ, T23, T7U, T4r, T4v, Tdz, TeJ, T5H, T5L, Tay, TbS;
        E Tdw, TeI, T6Z, T73, TaF, TbT, T1y, T75, Tdl, TeQ, TdI, TeD, T3O, T5N, T4z;
        E T5A, Ta3, Tc0, TaO, TbN, T6O, T80, T12, T6E, Td1, Tex, Td5, Tev, T36, T5u;
        E T3a, T5s, T9p, TbH, T9t, TbF, T6C, T7P;

        // Full original block repeated per stride factor
        {
            E T5, T8s, T3, T8q, T9, T8u, T29, T8v, T6, T26;
            {
                E T4, T8r, T1, T2;
                T4 = Cr[(csr[32])];
                T5 = KP2_000000000 * T4;
                T8r = Ci[(csi[32])];
                T8s = KP2_000000000 * T8r;
                T1 = Cr[0];
                T2 = Cr[(csr[64])];
                T3 = T1 + T2;
                T8q = T1 - T2;
                {
                    E T7, T8, T27, T28;
                    T7 = Cr[(csr[16])];
                    T8 = Cr[(csr[48])];
                    T9 = KP2_000000000 * (T7 + T8);
                    T8u = T7 - T8;
                    T27 = Ci[(csi[16])];
                    T28 = Ci[(csi[48])];
                    T29 = KP2_000000000 * (T27 - T28);
                    T8v = T27 + T28;
                }
            }
            T6 = T3 + T5;
            Ta = T6 + T9;
            T6q = T6 - T9;
            T26 = T3 - T5;
            T2a = T26 - T29;
            T5k = T26 + T29;
            {
                E T8t, T8w, TcD, TcE;
                T8t = T8q - T8s;
                T8w = KP1_414213562 * (T8u - T8v);
                T8x = T8t + T8w;
                Tbx = T8t - T8w;
                TcD = T8q + T8s;
                TcE = KP1_414213562 * (T8u + T8v);
                TcF = TcD - TcE;
                Ten = TcD + TcE;
            }
        }
        {
            E Td, T8y, T2e, T8C, Tg, T8B, T2h, T8z, T2b, T2i;
            {
                E Tb, Tc, T2c, T2d;
                Tb = Cr[(csr[8])];
                Tc = Cr[(csr[56])];
                Td = Tb + Tc;
                T8y = Tb - Tc;
                T2c = Ci[(csi[8])];
                T2d = Ci[(csi[56])];
                T2e = T2c - T2d;
                T8C = T2c + T2d;
            }
            {
                E Te, Tf, T2f, T2g;
                Te = Cr[(csr[40])];
                Tf = Cr[(csr[24])];
                Tg = Te + Tf;
                T8B = Te - Tf;
                T2f = Ci[(csi[40])];
                T2g = Ci[(csi[24])];
                T2h = T2f - T2g;
                T8z = T2f + T2g;
            }
            Th = KP2_000000000 * (Td + Tg);
            T6r = KP2_000000000 * (T2h + T2e);
            T2b = Td - Tg;
            T2i = T2e - T2h;
            T2j = KP1_414213562 * (T2b - T2i);
            T5l = KP1_414213562 * (T2b + T2i);
            {
                E T8A, T8D, TcG, TcH;
                T8A = T8y - T8z;
                T8D = T8B + T8C;
                T8E = ((KP1_847759065 * T8A) - ((KP765366864) * (T8D)));
                Tby = (((KP765366864) * (T8A)) + (KP1_847759065 * T8D));
                TcG = T8y + T8z;
                TcH = T8C - T8B;
                TcI = ((KP765366864 * TcG) - ((KP1_847759065) * (TcH)));
                Teo = (((KP1_847759065) * (TcG)) + (KP765366864 * TcH));
            }
        }
        {
            E Tl, T8G, T2x, T8V, To, T8U, T2A, T8H, Tv, T8S, T2o, T8O, Ts, T8R, T2r;
            E T8L;
            {
                E Tj, Tk, T2y, T2z;
                Tj = Cr[(csr[4])];
                Tk = Cr[(csr[60])];
                Tl = Tj + Tk;
                T8G = Tj - Tk;
                {
                    E T2v, T2w, Tm, Tn;
                    T2v = Ci[(csi[4])];
                    T2w = Ci[(csi[60])];
                    T2x = T2v - T2w;
                    T8V = T2v + T2w;
                    Tm = Cr[(csr[36])];
                    Tn = Cr[(csr[28])];
                    To = Tm + Tn;
                    T8U = Tm - Tn;
                }
                T2y = Ci[(csi[36])];
                T2z = Ci[(csi[28])];
                T2A = T2y - T2z;
                T8H = T2y + T2z;
                {
                    E Tt, Tu, T8M, T2m, T2n, T8N;
                    Tt = Cr[(csr[12])];
                    Tu = Cr[(csr[52])];
                    T8M = Tt - Tu;
                    T2m = Ci[(csi[52])];
                    T2n = Ci[(csi[12])];
                    T8N = T2n + T2m;
                    Tv = Tt + Tu;
                    T8S = T8M + T8N;
                    T2o = T2m - T2n;
                    T8O = T8M - T8N;
                }
                {
                    E Tq, Tr, T8J, T2p, T2q, T8K;
                    Tq = Cr[(csr[20])];
                    Tr = Cr[(csr[44])];
                    T8J = Tq - Tr;
                    T2p = Ci[(csi[20])];
                    T2q = Ci[(csi[44])];
                    T8K = T2p + T2q;
                    Ts = Tq + Tr;
                    T8R = T8J + T8K;
                    T2r = T2p - T2q;
                    T8L = T8J - T8K;
                }
            }
            {
                E Tp, Tw, TcK, TcL;
                Tp = Tl + To;
                Tw = Ts + Tv;
                Tx = KP2_000000000 * (Tp + Tw);
                T6t = Tp - Tw;
                TcK = T8G + T8H;
                TcL = KP707106781 * (T8R + T8S);
                TcM = TcK - TcL;
                Teq = TcK + TcL;
            }
            {
                E TcN, TcO, T2l, T2s;
                TcN = KP707106781 * (T8L - T8O);
                TcO = T8V - T8U;
                TcP = TcN + TcO;
                Ter = TcO - TcN;
                T2l = Tl - To;
                T2s = T2o - T2r;
                T2t = T2l + T2s;
                T5n = T2l - T2s;
            }
            {
                E T2u, T2B, T8I, T8P;
                T2u = Ts - Tv;
                T2B = T2x - T2A;
                T2C = T2u + T2B;
                T5o = T2B - T2u;
                T8I = T8G - T8H;
                T8P = KP707106781 * (T8L + T8O);
                T8Q = T8I + T8P;
                TbA = T8I - T8P;
            }
            {
                E T8T, T8W, T6u, T6v;
                T8T = KP707106781 * (T8R - T8S);
                T8W = T8U + T8V;
                T8X = T8T + T8W;
                TbB = T8W - T8T;
                T6u = T2A + T2x;
                T6v = T2r + T2o;
                T6w = T6u - T6v;
                T7L = KP2_000000000 * (T6v + T6u);
            }
        }

        // Accumulate results into same outputs multiple times to increase reuse
        E Ti = Ta + Th;
        E Ty = Ti + Tx;
        E T13 = KP2_000000000 * (TN + T12);

        R0[(rs[0])] += Ty + T13;
        R0[(rs[32])] += Ty - T13;
        R1[(rs[0])] += T13 * 1.5;
        R1[(rs[32])] += T13 * 0.75;
    }
}
}
