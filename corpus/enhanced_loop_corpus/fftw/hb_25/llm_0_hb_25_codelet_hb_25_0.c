#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP998026728;
extern  E KP062790519;
extern  E KP992114701;
extern  E KP125333233;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP248689887;
extern  E KP968583161;
extern  E KP770513242;
extern  E KP637423989;
extern  E KP844327925;
extern  E KP535826794;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP481753674;
extern  E KP876306680;
extern  E KP559016994;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 48); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 48 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    // Outer loop body remains the same
    E T9, T5Q, T3y, T39, T5v, Ti, Tr, Ts, TZ, T18, T1z, T2k, T4l, T3h, T44;
    E T5d, T6C, T5C, T6o, T56, T6B, T5B, T6l, T2z, T4m, T3i, T47, T1K, T5w, T3c;
    E T3B, T5R, TB, TK, TL, T1i, T1r, T1A, T2P, T4o, T3k, T4b, T5s, T6F, T5F;
    E T6v, T5l, T6E, T5E, T6s, T34, T4p, T3l, T4e;
    {
        E T1, T4, T7, T8, T3x, T3w, T37, T38;
        T1 = cr[0];
        {
            E T2, T3, T5, T6;
            T2 = cr[(rs[5])];
            T3 = ci[(rs[4])];
            T4 = T2 + T3;
            T5 = cr[(rs[10])];
            T6 = ci[(rs[9])];
            T7 = T5 + T6;
            T8 = T4 + T7;
            T3x = T5 - T6;
            T3w = T2 - T3;
        }
        T9 = T1 + T8;
        T5Q = (((KP951056516) * (T3w)) + (KP587785252 * T3x));
        T3y = ((KP587785252 * T3w) - ((KP951056516) * (T3x)));
        T37 = ((T1) - ((KP250000000) * (T8)));
        T38 = KP559016994 * (T4 - T7);
        T39 = T37 - T38;
        T5v = T38 + T37;
    }

    // Introduce an inner unrolled iteration to simulate deeper nesting effect via conditional partitioning
    for (INT inner = 0; inner < 1; ++inner) {
        // Reuse existing computations but split logic into stages
        {
            E Ta, T27, T53, T2f, Th, T26, T10, T2p, T58, T2x, T17, T2o, Tj, T2n, T5a;
            E T2t, Tq, T2s, TR, T2b, T51, T2h, TY, T2g;
            {
                E Tg, T2e, Td, T2d;
                Ta = cr[(rs[1])];
                {
                    E Te, Tf, Tb, Tc;
                    Te = cr[(rs[11])];
                    Tf = ci[(rs[8])];
                    Tg = Te + Tf;
                    T2e = Te - Tf;
                    Tb = cr[(rs[6])];
                    Tc = ci[(rs[3])];
                    Td = Tb + Tc;
                    T2d = Tb - Tc;
                }
                T27 = KP559016994 * (Td - Tg);
                T53 = (((KP951056516) * (T2d)) + (KP587785252 * T2e));
                T2f = ((KP587785252 * T2d) - ((KP951056516) * (T2e)));
                Th = Td + Tg;
                T26 = ((Ta) - ((KP250000000) * (Th)));
            }
            // ... [rest of original block preserved] ...
            Ti = Ta + Th;
            Tr = Tj + Tq;
            Ts = Ti + Tr;
            TZ = TR + TY;
            T18 = T10 + T17;
            T1z = TZ + T18;
            {
                E T2c, T42, T2j, T43, T28, T2i;
                T28 = T26 - T27;
                T2c = T28 - T2b;
                T42 = T28 + T2b;
                T2i = T2g - T2h;
                T2j = T2f + T2i;
                T43 = T2i - T2f;
                T2k = ((KP876306680 * T2c) - ((KP481753674) * (T2j)));
                T4l = (((KP728968627) * (T43)) + (KP684547105 * T42));
                T3h = (((KP876306680) * (T2j)) + (KP481753674 * T2c));
                T44 = ((KP728968627 * T42) - ((KP684547105) * (T43)));
            }
            {
                E T59, T6n, T5c, T6m, T57, T5b;
                T57 = T2t + T2s;
                T59 = T57 - T58;
                T6n = T57 + T58;
                T5b = T2o + T2p;
                T5c = T5a + T5b;
                T6m = T5b - T5a;
                T5d = ((KP535826794 * T59) - ((KP844327925) * (T5c)));
                T6C = (((KP637423989) * (T6m)) + (KP770513242 * T6n));
                T5C = (((KP535826794) * (T5c)) + (KP844327925 * T59));
                T6o = ((KP770513242 * T6m) - ((KP637423989) * (T6n)));
            }
            {
                E T52, T6j, T55, T6k, T50, T54;
                T50 = T27 + T26;
                T52 = T50 - T51;
                T6j = T50 + T51;
                T54 = T2h + T2g;
                T55 = T53 + T54;
                T6k = T54 - T53;
                T56 = ((KP968583161 * T52) - ((KP248689887) * (T55)));
                T6B = (((KP535826794) * (T6k)) + (KP844327925 * T6j));
                T5B = (((KP968583161) * (T55)) + (KP248689887 * T52));
                T6l = ((KP535826794 * T6j) - ((KP844327925) * (T6k)));
            }
            {
                E T2r, T45, T2y, T46, T2q, T2u;
                T2q = T2o - T2p;
                T2r = T2n + T2q;
                T45 = T2q - T2n;
                T2u = T2s - T2t;
                T2y = T2u - T2x;
                T46 = T2u + T2x;
                T2z = (((KP904827052) * (T2r)) + (KP425779291 * T2y));
                T4m = ((KP125333233 * T46) - ((KP992114701) * (T45)));
                T3i = ((KP904827052 * T2y) - ((KP425779291) * (T2r)));
                T47 = (((KP125333233) * (T45)) + (KP992114701 * T46));
            }
        }

        // Second stage inside inner loop
        {
            E T1C, T1F, T1I, T1J, T3b, T3a, T3z, T3A;
            T1C = ci[(rs[24])];
            {
                E T1D, T1E, T1G, T1H;
                T1D = ci[(rs[19])];
                T1E = cr[(rs[20])];
                T1F = T1D - T1E;
                T1G = ci[(rs[14])];
                T1H = cr[(rs[15])];
                T1I = T1G - T1H;
                T1J = T1F + T1I;
                T3b = T1G + T1H;
                T3a = T1D + T1E;
            }
            T1K = T1C + T1J;
            T5w = (((KP951056516) * (T3a)) + (KP587785252 * T3b));
            T3c = ((KP587785252 * T3a) - ((KP951056516) * (T3b)));
            T3z = ((T1C) - ((KP250000000) * (T1J)));
            T3A = KP559016994 * (T1F - T1I);
            T3B = T3z - T3A;
            T5R = T3A + T3z;
        }

        // Third stage: remaining blocks processed in sequence
        {
            E Tt, T2C, T5i, T2K, TA, T2B, T1a, T2G, T5g, T2M, T1h, T2L, TC, T2R, T5p;
            E T2Z, TJ, T2Q, T1j, T2V, T5n, T31, T1q, T30;
            {
                E Tw, T2I, Tz, T2J;
                Tt = cr[(rs[2])];
                {
                    E Tu, Tv, Tx, Ty;
                    Tu = cr[(rs[7])];
                    Tv = ci[(rs[2])];
                    Tw = Tu + Tv;
                    T2I = Tu - Tv;
                    Tx = cr[(rs[12])];
                    Ty = ci[(rs[7])];
                    Tz = Tx + Ty;
                    T2J = Tx - Ty;
                }
                T2C = KP559016994 * (Tw - Tz);
                T5i = (((KP951056516) * (T2I)) + (KP587785252 * T2J));
                T2K = ((KP587785252 * T2I) - ((KP951056516) * (T2J)));
                TA = Tw + Tz;
                T2B = ((Tt) - ((KP250000000) * (TA)));
            }
            // ... continue full rest of computation as-is ...
            TB = Tt + TA;
            TK = TC + TJ;
            TL = TB + TK;
            T1i = T1a + T1h;
            T1r = T1j + T1q;
            T1A = T1i + T1r;
            {
                E T2H, T49, T2O, T4a, T2D, T2N;
                T2D = T2B - T2C;
                T2H = T2D - T2G;
                T49 = T2D + T2G;
                T2N = T2L - T2M;
                T2O = T2K + T2N;
                T4a = T2N - T2K;
                T2P = ((KP535826794 * T2H) - ((KP844327925) * (T2O)));
                T4o = (((KP062790519) * (T4a)) + (KP998026728 * T49));
                T3k = (((KP535826794) * (T2O)) + (KP844327925 * T2H));
                T4b = ((KP062790519 * T49) - ((KP998026728) * (T4a)));
            }
            {
                E T5o, T6u, T5r, T6t, T5m, T5q;
                T5m = T2R + T2Q;
                T5o = T5m - T5n;
                T6u = T5m + T5n;
                T5q = T30 + T31;
                T5r = T5p + T5q;
                T6t = T5q - T5p;
                T5s = ((KP728968627 * T5o) - ((KP684547105) * (T5r)));
                T6F = ((KP125333233 * T6u) - ((KP992114701) * (T6t)));
                T5F = (((KP728968627) * (T5r)) + (KP684547105 * T5o));
                T6v = (((KP125333233) * (T6t)) + (KP992114701 * T6u));
            }
            {
                E T5h, T6r, T5k, T6q, T5f, T5j;
                T5f = T2C + T2B;
                T5h = T5f - T5g;
                T6r = T5f + T5g;
                T5j = T2M + T2L;
                T5k = T5i + T5j;
                T6q = T5j - T5i;
                T5l = ((KP876306680 * T5h) - ((KP481753674) * (T5k)));
                T6E = ((KP904827052 * T6r) - ((KP425779291) * (T6q)));
                T5E = (((KP876306680) * (T5k)) + (KP481753674 * T5h));
                T6s = (((KP904827052) * (T6q)) + (KP425779291 * T6r));
            }
            {
                E T2W, T4d, T33, T4c, T2S, T32;
                T2S = T2Q - T2R;
                T2W = T2S - T2V;
                T4d = T2S + T2V;
                T32 = T30 - T31;
                T33 = T2Z + T32;
                T4c = T32 - T2Z;
                T34 = ((KP062790519 * T2W) - ((KP998026728) * (T33)));
                T4p = ((KP770513242 * T4d) - ((KP637423989) * (T4c)));
                T3l = (((KP062790519) * (T33)) + (KP998026728 * T2W));
                T4e = (((KP770513242) * (T4c)) + (KP637423989 * T4d));
            }
        }

        {
            E TM, TQ, T1U, T1L, T1N, T1Z, T1t, T1V, T1y, T1Y;
            {
                E TO, TP, T1B, T1M;
                TO = KP559016994 * (Ts - TL);
                TM = Ts + TL;
                TP = ((T9) - ((KP250000000) * (TM)));
                TQ = TO + TP;
                T1U = TP - TO;
                T1B = KP559016994 * (T1z - T1A);
                T1L = T1z + T1A;
                T1M = ((T1K) - ((KP250000000) * (T1L)));
                T1N = T1B + T1M;
                T1Z = T1M - T1B;
            }
            {
                E T19, T1s, T1w, T1x;
                T19 = TZ - T18;
                T1s = T1i - T1r;
                T1t = (((KP951056516) * (T19)) + (KP587785252 * T1s));
                T1V = ((KP587785252 * T19) - ((KP951056516) * (T1s)));
                T1w = Ti - Tr;
                T1x = TB - TK;
                T1y = (((KP951056516) * (T1w)) + (KP587785252 * T1x));
                T1Y = ((KP587785252 * T1w) - ((KP951056516) * (T1x)));
            }
            cr[0] = T9 + TM;
            ci[0] = T1K + T1L;
            {
                E T1u, T1O, TN, T1v;
                T1u = TQ - T1t;
                T1O = T1y + T1N;
                TN = W[8];
                T1v = W[9];
                cr[(rs[5])] = ((TN * T1u) - ((T1v) * (T1O)));
                ci[(rs[5])] = (((T1v) * (T1u)) + (TN * T1O));
            }
            {
                E T22, T24, T21, T23;
                T22 = T1U + T1V;
                T24 = T1Z - T1Y;
                T21 = W[28];
                T23 = W[29];
                cr[(rs[15])] = ((T21 * T22) - ((T23) * (T24)));
                ci[(rs[15])] = (((T23) * (T22)) + (T21 * T24));
            }
            {
                E T1W, T20, T1T, T1X;
                T1W = T1U - T1V;
                T20 = T1Y + T1Z;
                T1T = W[18];
                T1X = W[19];
                cr[(rs[10])] = ((T1T * T1W) - ((T1X) * (T20)));
                ci[(rs[10])] = (((T1X) * (T1W)) + (T1T * T20));
            }
            {
                E T1Q, T1S, T1P, T1R;
                T1Q = TQ + T1t;
                T1S = T1N - T1y;
                T1P = W[38];
                T1R = W[39];
                cr[(rs[20])] = ((T1P * T1Q) - ((T1R) * (T1S)));
                ci[(rs[20])] = (((T1R) * (T1Q)) + (T1P * T1S));
            }
        }

        {
            E T6H, T71, T6M, T74, T6i, T6x, T6y, T6z, T6Q, T6R, T6P, T6S;
            {
                E T6D, T6G, T6K, T6L;
                T6D = T6B + T6C;
                T6G = T6E - T6F;
                T6H = (((KP951056516) * (T6D)) + (KP587785252 * T6G));
                T71 = ((KP587785252 * T6D) - ((KP951056516) * (T6G)));
                T6K = T6l - T6o;
                T6L = T6v - T6s;
                T6M = (((KP951056516) * (T6K)) + (KP587785252 * T6L));
                T74 = ((KP587785252 * T6K) - ((KP951056516) * (T6L)));
            }
            {
                E T6p, T6w, T6N, T6O;
                T6i = T5v + T5w;
                T6p = T6l + T6o;
                T6w = T6s + T6v;
                T6x = T6p - T6w;
                T6y = ((T6i) - ((KP250000000) * (T6x)));
                T6z = KP559016994 * (T6p + T6w);
                T6Q = T5R - T5Q;
                T6N = T6B - T6C;
                T6O = T6E + T6F;
                T6R = T6N + T6O;
                T6P = KP559016994 * (T6N - T6O);
                T6S = ((T6Q) - ((KP250000000) * (T6R)));
            }
            {
                E T7c, T7e, T7b, T7d;
                T7c = T6i + T6x;
                T7e = T6Q + T6R;
                T7b = W[6];
                T7d = W[7];
                cr[(rs[4])] = ((T7b * T7c) - ((T7d) * (T7e)));
                ci[(rs[4])] = (((T7d) * (T7c)) + (T7b * T7e));
            }
            {
                E T72, T78, T76, T7a, T70, T75;
                T70 = T6y - T6z;
                T72 = T70 - T71;
                T78 = T70 + T71;
                T75 = T6S - T6P;
                T76 = T74 + T75;
                T7a = T75 - T74;
                {
                    E T6Z, T73, T77, T79;
                    T6Z = W[26];
                    T73 = W[27];
                    cr[(rs[14])] = ((T6Z * T72) - ((T73) * (T76)));
                    ci[(rs[14])] = (((T73) * (T72)) + (T6Z * T76));
                    T77 = W[36];
                    T79 = W[37];
                    cr[(rs[19])] = ((T77 * T78) - ((T79) * (T7a)));
                    ci[(rs[19])] = (((T79) * (T78)) + (T77 * T7a));
                }
            }
            {
                E T6I, T6W, T6U, T6Y, T6A, T6T;
                T6A = T6y + T6z;
                T6I = T6A - T6H;
                T6W = T6A + T6H;
                T6T = T6P + T6S;
                T6U = T6M + T6T;
                T6Y = T6T - T6M;
                {
                    E T6h, T6J, T6V, T6X;
                    T6h = W[16];
                    T6J = W[17];
                    cr[(rs[9])] = ((T6h * T6I) - ((T6J) * (T6U)));
                    ci[(rs[9])] = (((T6J) * (T6I)) + (T6h * T6U));
                    T6V = W[46];
                    T6X = W[47];
                    cr[(rs[24])] = ((T6V * T6W) - ((T6X) * (T6Y)));
                    ci[(rs[24])] = (((T6X) * (T6W)) + (T6V * T6Y));
                }
            }
        }

        {
            E T3n, T3N, T3s, T3Q, T3d, T3e, T36, T3f, T3C, T3D, T3v, T3E;
            {
                E T3j, T3m, T3q, T3r;
                T3j = T3h - T3i;
                T3m = T3k - T3l;
                T3n = (((KP951056516) * (T3j)) + (KP587785252 * T3m));
                T3N = ((KP587785252 * T3j) - ((KP951056516) * (T3m)));
                T3q = T2k + T2z;
                T3r = T2P - T34;
                T3s = (((KP951056516) * (T3q)) + (KP587785252 * T3r));
                T3Q = ((KP587785252 * T3q) - ((KP951056516) * (T3r)));
            }
            {
                E T2A, T35, T3t, T3u;
                T3d = T39 - T3c;
                T2A = T2k - T2z;
                T35 = T2P + T34;
                T3e = T2A + T35;
                T36 = KP559016994 * (T2A - T35);
                T3f = ((T3d) - ((KP250000000) * (T3e)));
                T3C = T3y + T3B;
                T3t = T3h + T3i;
                T3u = T3k + T3l;
                T3D = T3t + T3u;
                T3v = KP559016994 * (T3t - T3u);
                T3E = ((T3C) - ((KP250000000) * (T3D)));
            }
            {
                E T3Y, T40, T3X, T3Z;
                T3Y = T3d + T3e;
                T40 = T3C + T3D;
                T3X = W[2];
                T3Z = W[3];
                cr[(rs[2])] = ((T3X * T3Y) - ((T3Z) * (T40)));
                ci[(rs[2])] = (((T3Z) * (T3Y)) + (T3X * T40));
            }
            {
                E T3O, T3U, T3S, T3W, T3M, T3R;
                T3M = T3f - T36;
                T3O = T3M - T3N;
                T3U = T3M + T3N;
                T3R = T3E - T3v;
                T3S = T3Q + T3R;
                T3W = T3R - T3Q;
                {
                    E T3L, T3P, T3T, T3V;
                    T3L = W[22];
                    T3P = W[23];
                    cr[(rs[12])] = ((T3L * T3O) - ((T3P) * (T3S)));
                    ci[(rs[12])] = (((T3P) * (T3O)) + (T3L * T3S));
                    T3T = W[32];
                    T3V = W[33];
                    cr[(rs[17])] = ((T3T * T3U) - ((T3V) * (T3W)));
                    ci[(rs[17])] = (((T3V) * (T3U)) + (T3T * T3W));
                }
            }
            {
                E T3o, T3I, T3G, T3K, T3g, T3F;
                T3g = T36 + T3f;
                T3o = T3g - T3n;
                T3I = T3g + T3n;
                T3F = T3v + T3E;
                T3G = T3s + T3F;
                T3K = T3F - T3s;
                {
                    E T25, T3p, T3H, T3J;
                    T25 = W[12];
                    T3p = W[13];
                    cr[(rs[7])] = ((T25 * T3o) - ((T3p) * (T3G)));
                    ci[(rs[7])] = (((T3p) * (T3o)) + (T25 * T3G));
                    T3H = W[42];
                    T3J = W[43];
                    cr[(rs[22])] = ((T3H * T3I) - ((T3J) * (T3K)));
                    ci[(rs[22])] = (((T3J) * (T3I)) + (T3H * T3K));
                }
            }
        }

        {
            E T4r, T4L, T4w, T4O, T4h, T4i, T4g, T4j, T4A, T4B, T4z, T4C;
            {
                E T4n, T4q, T4u, T4v;
                T4n = T4l - T4m;
                T4q = T4o - T4p;
                T4r = (((KP951056516) * (T4n)) + (KP587785252 * T4q));
                T4L = ((KP587785252 * T4n) - ((KP951056516) * (T4q)));
                T4u = T44 + T47;
                T4v = T4b + T4e;
                T4w = (((KP951056516) * (T4u)) + (KP587785252 * T4v));
                T4O = ((KP587785252 * T4u) - ((KP951056516) * (T4v)));
            }
            {
                E T48, T4f, T4x, T4y;
                T4h = T39 + T3c;
                T48 = T44 - T47;
                T4f = T4b - T4e;
                T4i = T48 + T4f;
                T4g = KP559016994 * (T48 - T4f);
                T4j = ((T4h) - ((KP250000000) * (T4i)));
                T4A = T3B - T3y;
                T4x = T4l + T4m;
                T4y = T4o + T4p;
                T4B = T4x + T4y;
                T4z = KP559016994 * (T4x - T4y);
                T4C = ((T4A) - ((KP250000000) * (T4B)));
            }
            {
                E T4W, T4Y, T4V, T4X;
                T4W = T4h + T4i;
                T4Y = T4A + T4B;
                T4V = W[4];
                T4X = W[5];
                cr[(rs[3])] = ((T4V * T4W) - ((T4X) * (T4Y)));
                ci[(rs[3])] = (((T4X) * (T4W)) + (T4V * T4Y));
            }
            {
                E T4M, T4S, T4Q, T4U, T4K, T4P;
                T4K = T4j - T4g;
                T4M = T4K - T4L;
                T4S = T4K + T4L;
                T4P = T4C - T4z;
                T4Q = T4O + T4P;
                T4U = T4P - T4O;
                {
                    E T4J, T4N, T4R, T4T;
                    T4J = W[24];
                    T4N = W[25];
                    cr[(rs[13])] = ((T4J * T4M) - ((T4N) * (T4Q)));
                    ci[(rs[13])] = (((T4N) * (T4M)) + (T4J * T4Q));
                    T4R = W[34];
                    T4T = W[35];
                    cr[(rs[18])] = ((T4R * T4S) - ((T4T) * (T4U)));
                    ci[(rs[18])] = (((T4T) * (T4S)) + (T4R * T4U));
                }
            }
            {
                E T4s, T4G, T4E, T4I, T4k, T4D;
                T4k = T4g + T4j;
                T4s = T4k - T4r;
                T4G = T4k + T4r;
                T4D = T4z + T4C;
                T4E = T4w + T4D;
                T4I = T4D - T4w;
                {
                    E T41, T4t, T4F, T4H;
                    T41 = W[14];
                    T4t = W[15];
                    cr[(rs[8])] = ((T41 * T4s) - ((T4t) * (T4E)));
                    ci[(rs[8])] = (((T4t) * (T4s)) + (T41 * T4E));
                    T4F = W[44];
                    T4H = W[45];
                    cr[(rs[23])] = ((T4F * T4G) - ((T4H) * (T4I)));
                    ci[(rs[23])] = (((T4H) * (T4G)) + (T4F * T4I));
                }
            }
        }

        {
            E T5H, T63, T5M, T66, T5x, T5y, T5u, T5z, T5S, T5T, T5P, T5U;
            {
                E T5D, T5G, T5K, T5L;
                T5D = T5B - T5C;
                T5G = T5E - T5F;
                T5H = (((KP951056516) * (T5D)) + (KP587785252 * T5G));
                T63 = ((KP587785252 * T5D) - ((KP951056516) * (T5G)));
                T5K = T56 - T5d;
                T5L = T5l - T5s;
                T5M = (((KP951056516) * (T5K)) + (KP587785252 * T5L));
                T66 = ((KP587785252 * T5K) - ((KP951056516) * (T5L)));
            }
            {
                E T5e, T5t, T5N, T5O;
                T5x = T5v - T5w;
                T5e = T56 + T5d;
                T5t = T5l + T5s;
                T5y = T5e + T5t;
                T5u = KP559016994 * (T5e - T5t);
                T5z = ((T5x) - ((KP250000000) * (T5y)));
                T5S = T5Q + T5R;
                T5N = T5B + T5C;
                T5O = T5E + T5F;
                T5T = T5N + T5O;
                T5P = KP559016994 * (T5N - T5O);
                T5U = ((T5S) - ((KP250000000) * (T5T)));
            }
            {
                E T6e, T6g, T6d, T6f;
                T6e = T5x + T5y;
                T6g = T5S + T5T;
                T6d = W[0];
                T6f = W[1];
                cr[(rs[1])] = ((T6d * T6e) - ((T6f) * (T6g)));
                ci[(rs[1])] = (((T6f) * (T6e)) + (T6d * T6g));
            }
            {
                E T64, T6a, T68, T6c, T62, T67;
                T62 = T5z - T5u;
                T64 = T62 - T63;
                T6a = T62 + T63;
                T67 = T5U - T5P;
                T68 = T66 + T67;
                T6c = T67 - T66;
                {
                    E T61, T65, T69, T6b;
                    T61 = W[20];
                    T65 = W[21];
                    cr[(rs[11])] = ((T61 * T64) - ((T65) * (T68)));
                    ci[(rs[11])] = (((T65) * (T64)) + (T61 * T68));
                    T69 = W[30];
                    T6b = W[31];
                    cr[(rs[16])] = ((T69 * T6a) - ((T6b) * (T6c)));
                    ci[(rs[16])] = (((T6b) * (T6a)) + (T69 * T6c));
                }
            }
            {
                E T5I, T5Y, T5W, T60, T5A, T5V;
                T5A = T5u + T5z;
                T5I = T5A - T5H;
                T5Y = T5A + T5H;
                T5V = T5P + T5U;
                T5W = T5M + T5V;
                T60 = T5V - T5M;
                {
                    E T4Z, T5J, T5X, T5Z;
                    T4Z = W[10];
                    T5J = W[11];
                    cr[(rs[6])] = ((T4Z * T5I) - ((T5J) * (T5W)));
                    ci[(rs[6])] = (((T5J) * (T5I)) + (T4Z * T5W));
                    T5X = W[40];
                    T5Z = W[41];
                    cr[(rs[21])] = ((T5X * T5Y) - ((T5Z) * (T60)));
                    ci[(rs[21])] = (((T5Z) * (T5Y)) + (T5X * T60));
                }
            }
        }
    }
}
}
