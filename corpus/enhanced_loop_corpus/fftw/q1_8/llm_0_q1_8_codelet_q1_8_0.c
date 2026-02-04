#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef R E;

typedef ptrdiff_t INT;

typedef INT *stride;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 14); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 14 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T14, T1g, Tk, TC, TQ, T10, TM, T1w, T2p, T2z, T1H, T1M, T1W, T2j;
    E T1V, T7R, T8O, T90, T84, T8m, T8A, T8K, T8w, T9g, Ta9, Taj, T9r, T9w, T9G;
    E Ta3, T9F, Te, T17, T1h, Tp, Tu, TE, T11, TD, T1p, T2m, T2y, T1C, T1U;
    E T28, T2i, T24, T7Y, T8R, T91, T89, T8e, T8o, T8L, T8n, T99, Ta6, Tai, T9m;
    E T9E, T9S, Ta2, T9O, T2H, T3E, T3Q, T2U, T3c, T3q, T3A, T3m, T46, T4Z, T59;
    E T4h, T4m, T4w, T4T, T4v, T5h, T6e, T6q, T5u, T5M, T60, T6a, T5W, T6G, T7z;
    E T7J, T6R, T6W, T76, T7t, T75, T2O, T3H, T3R, T2Z, T34, T3e, T3B, T3d, T3Z;
    E T4W, T58, T4c, T4u, T4I, T4S, T4E, T5o, T6h, T6r, T5z, T5E, T5O, T6b, T5N;
    E T6z, T7w, T7I, T6M, T74, T7i, T7s, T7e;
    {
        E T3, Ty, Tj, TY, T6, Tg, TB, TZ;
        {
            E T1, T2, Th, Ti;
            T1 = rio[0];
            T2 = rio[(rs[4])];
            T3 = T1 + T2;
            Ty = T1 - T2;
            Th = iio[0];
            Ti = iio[(rs[4])];
            Tj = Th - Ti;
            TY = Th + Ti;
        }
        {
            E T4, T5, Tz, TA;
            T4 = rio[(rs[2])];
            T5 = rio[(rs[6])];
            T6 = T4 + T5;
            Tg = T4 - T5;
            Tz = iio[(rs[2])];
            TA = iio[(rs[6])];
            TB = Tz - TA;
            TZ = Tz + TA;
        }
        T7 = T3 + T6;
        T14 = T3 - T6;
        T1g = TY + TZ;
        Tk = Tg + Tj;
        TC = Ty - TB;
        TQ = Tj - Tg;
        T10 = TY - TZ;
        TM = Ty + TB;
    }
    {
        E T1s, T1I, T1L, T2n, T1v, T1D, T1G, T2o;
        {
            E T1q, T1r, T1J, T1K;
            T1q = rio[(vs[1]) + (rs[1])];
            T1r = rio[(vs[1]) + (rs[5])];
            T1s = T1q + T1r;
            T1I = T1q - T1r;
            T1J = iio[(vs[1]) + (rs[1])];
            T1K = iio[(vs[1]) + (rs[5])];
            T1L = T1J - T1K;
            T2n = T1J + T1K;
        }
        {
            E T1t, T1u, T1E, T1F;
            T1t = rio[(vs[1]) + (rs[7])];
            T1u = rio[(vs[1]) + (rs[3])];
            T1v = T1t + T1u;
            T1D = T1t - T1u;
            T1E = iio[(vs[1]) + (rs[7])];
            T1F = iio[(vs[1]) + (rs[3])];
            T1G = T1E - T1F;
            T2o = T1E + T1F;
        }
        T1w = T1s + T1v;
        T2p = T2n - T2o;
        T2z = T2n + T2o;
        T1H = T1D - T1G;
        T1M = T1I + T1L;
        T1W = T1D + T1G;
        T2j = T1v - T1s;
        T1V = T1L - T1I;
    }
    {
        E T7N, T8i, T83, T8I, T7Q, T80, T8l, T8J;
        {
            E T7L, T7M, T81, T82;
            T7L = rio[(vs[6])];
            T7M = rio[(vs[6]) + (rs[4])];
            T7N = T7L + T7M;
            T8i = T7L - T7M;
            T81 = iio[(vs[6])];
            T82 = iio[(vs[6]) + (rs[4])];
            T83 = T81 - T82;
            T8I = T81 + T82;
        }
        {
            E T7O, T7P, T8j, T8k;
            T7O = rio[(vs[6]) + (rs[2])];
            T7P = rio[(vs[6]) + (rs[6])];
            T7Q = T7O + T7P;
            T80 = T7O - T7P;
            T8j = iio[(vs[6]) + (rs[2])];
            T8k = iio[(vs[6]) + (rs[6])];
            T8l = T8j - T8k;
            T8J = T8j + T8k;
        }
        T7R = T7N + T7Q;
        T8O = T7N - T7Q;
        T90 = T8I + T8J;
        T84 = T80 + T83;
        T8m = T8i - T8l;
        T8A = T83 - T80;
        T8K = T8I - T8J;
        T8w = T8i + T8l;
    }
    {
        E T9c, T9s, T9v, Ta7, T9f, T9n, T9q, Ta8;
        {
            E T9a, T9b, T9t, T9u;
            T9a = rio[(vs[7]) + (rs[1])];
            T9b = rio[(vs[7]) + (rs[5])];
            T9c = T9a + T9b;
            T9s = T9a - T9b;
            T9t = iio[(vs[7]) + (rs[1])];
            T9u = iio[(vs[7]) + (rs[5])];
            T9v = T9t - T9u;
            Ta7 = T9t + T9u;
        }
        {
            E T9d, T9e, T9o, T9p;
            T9d = rio[(vs[7]) + (rs[7])];
            T9e = rio[(vs[7]) + (rs[3])];
            T9f = T9d + T9e;
            T9n = T9d - T9e;
            T9o = iio[(vs[7]) + (rs[7])];
            T9p = iio[(vs[7]) + (rs[3])];
            T9q = T9o - T9p;
            Ta8 = T9o + T9p;
        }
        T9g = T9c + T9f;
        Ta9 = Ta7 - Ta8;
        Taj = Ta7 + Ta8;
        T9r = T9n - T9q;
        T9w = T9s + T9v;
        T9G = T9n + T9q;
        Ta3 = T9f - T9c;
        T9F = T9v - T9s;
    }
    {
        E Ta, Tq, Tt, T15, Td, Tl, To, T16;
        {
            E T8, T9, Tr, Ts;
            T8 = rio[(rs[1])];
            T9 = rio[(rs[5])];
            Ta = T8 + T9;
            Tq = T8 - T9;
            Tr = iio[(rs[1])];
            Ts = iio[(rs[5])];
            Tt = Tr - Ts;
            T15 = Tr + Ts;
        }
        {
            E Tb, Tc, Tm, Tn;
            Tb = rio[(rs[7])];
            Tc = rio[(rs[3])];
            Td = Tb + Tc;
            Tl = Tb - Tc;
            Tm = iio[(rs[7])];
            Tn = iio[(rs[3])];
            To = Tm - Tn;
            T16 = Tm + Tn;
        }
        Te = Ta + Td;
        T17 = T15 - T16;
        T1h = T15 + T16;
        Tp = Tl - To;
        Tu = Tq + Tt;
        TE = Tl + To;
        T11 = Td - Ta;
        TD = Tt - Tq;
    }
    {
        E T1l, T1Q, T1B, T2g, T1o, T1y, T1T, T2h;
        {
            E T1j, T1k, T1z, T1A;
            T1j = rio[(vs[1])];
            T1k = rio[(vs[1]) + (rs[4])];
            T1l = T1j + T1k;
            T1Q = T1j - T1k;
            T1z = iio[(vs[1])];
            T1A = iio[(vs[1]) + (rs[4])];
            T1B = T1z - T1A;
            T2g = T1z + T1A;
        }
        {
            E T1m, T1n, T1R, T1S;
            T1m = rio[(vs[1]) + (rs[2])];
            T1n = rio[(vs[1]) + (rs[6])];
            T1o = T1m + T1n;
            T1y = T1m - T1n;
            T1R = iio[(vs[1]) + (rs[2])];
            T1S = iio[(vs[1]) + (rs[6])];
            T1T = T1R - T1S;
            T2h = T1R + T1S;
        }
        T1p = T1l + T1o;
        T2m = T1l - T1o;
        T2y = T2g + T2h;
        T1C = T1y + T1B;
        T1U = T1Q - T1T;
        T28 = T1B - T1y;
        T2i = T2g - T2h;
        T24 = T1Q + T1T;
    }
    {
        E T7U, T8a, T8d, T8P, T7X, T85, T88, T8Q;
        {
            E T7S, T7T, T8b, T8c;
            T7S = rio[(vs[6]) + (rs[1])];
            T7T = rio[(vs[6]) + (rs[5])];
            T7U = T7S + T7T;
            T8a = T7S - T7T;
            T8b = iio[(vs[6]) + (rs[1])];
            T8c = iio[(vs[6]) + (rs[5])];
            T8d = T8b - T8c;
            T8P = T8b + T8c;
        }
        {
            E T7V, T7W, T86, T87;
            T7V = rio[(vs[6]) + (rs[7])];
            T7W = rio[(vs[6]) + (rs[3])];
            T7X = T7V + T7W;
            T85 = T7V - T7W;
            T86 = iio[(vs[6]) + (rs[7])];
            T87 = iio[(vs[6]) + (rs[3])];
            T88 = T86 - T87;
            T8Q = T86 + T87;
        }
        T7Y = T7U + T7X;
        T8R = T8P - T8Q;
        T91 = T8P + T8Q;
        T89 = T85 - T88;
        T8e = T8a + T8d;
        T8o = T85 + T88;
        T8L = T7X - T7U;
        T8n = T8d - T8a;
    }
    {
        E T95, T9A, T9l, Ta0, T98, T9i, T9D, Ta1;
        {
            E T93, T94, T9j, T9k;
            T93 = rio[(vs[7])];
            T94 = rio[(vs[7]) + (rs[4])];
            T95 = T93 + T94;
            T9A = T93 - T94;
            T9j = iio[(vs[7])];
            T9k = iio[(vs[7]) + (rs[4])];
            T9l = T9j - T9k;
            Ta0 = T9j + T9k;
        }
        {
            E T96, T97, T9B, T9C;
            T96 = rio[(vs[7]) + (rs[2])];
            T97 = rio[(vs[7]) + (rs[6])];
            T98 = T96 + T97;
            T9i = T96 - T97;
            T9B = iio[(vs[7]) + (rs[2])];
            T9C = iio[(vs[7]) + (rs[6])];
            T9D = T9B - T9C;
            Ta1 = T9B + T9C;
        }
        T99 = T95 + T98;
        Ta6 = T95 - T98;
        Tai = Ta0 + Ta1;
        T9m = T9i + T9l;
        T9E = T9A - T9D;
        T9S = T9l - T9i;
        Ta2 = Ta0 - Ta1;
        T9O = T9A + T9D;
    }
    {
        E T2D, T38, T2T, T3y, T2G, T2Q, T3b, T3z;
        {
            E T2B, T2C, T2R, T2S;
            T2B = rio[(vs[2])];
            T2C = rio[(vs[2]) + (rs[4])];
            T2D = T2B + T2C;
            T38 = T2B - T2C;
            T2R = iio[(vs[2])];
            T2S = iio[(vs[2]) + (rs[4])];
            T2T = T2R - T2S;
            T3y = T2R + T2S;
        }
        {
            E T2E, T2F, T39, T3a;
            T2E = rio[(vs[2]) + (rs[2])];
            T2F = rio[(vs[2]) + (rs[6])];
            T2G = T2E + T2F;
            T2Q = T2E - T2F;
            T39 = iio[(vs[2]) + (rs[2])];
            T3a = iio[(vs[2]) + (rs[6])];
            T3b = T39 - T3a;
            T3z = T39 + T3a;
        }
        T2H = T2D + T2G;
        T3E = T2D - T2G;
        T3Q = T3y + T3z;
        T2U = T2Q + T2T;
        T3c = T38 - T3b;
        T3q = T2T - T2Q;
        T3A = T3y - T3z;
        T3m = T38 + T3b;
    }
    {
        E T42, T4i, T4l, T4X, T45, T4d, T4g, T4Y;
        {
            E T40, T41, T4j, T4k;
            T40 = rio[(vs[3]) + (rs[1])];
            T41 = rio[(vs[3]) + (rs[5])];
            T42 = T40 + T41;
            T4i = T40 - T41;
            T4j = iio[(vs[3]) + (rs[1])];
            T4k = iio[(vs[3]) + (rs[5])];
            T4l = T4j - T4k;
            T4X = T4j + T4k;
        }
        {
            E T43, T44, T4e, T4f;
            T43 = rio[(vs[3]) + (rs[7])];
            T44 = rio[(vs[3]) + (rs[3])];
            T45 = T43 + T44;
            T4d = T43 - T44;
            T4e = iio[(vs[3]) + (rs[7])];
            T4f = iio[(vs[3]) + (rs[3])];
            T4g = T4e - T4f;
            T4Y = T4e + T4f;
        }
        T46 = T42 + T45;
        T4Z = T4X - T4Y;
        T59 = T4X + T4Y;
        T4h = T4d - T4g;
        T4m = T4i + T4l;
        T4w = T4d + T4g;
        T4T = T45 - T42;
        T4v = T4l - T4i;
    }
    {
        E T5d, T5I, T5t, T68, T5g, T5q, T5L, T69;
        {
            E T5b, T5c, T5r, T5s;
            T5b = rio[(vs[4])];
            T5c = rio[(vs[4]) + (rs[4])];
            T5d = T5b + T5c;
            T5I = T5b - T5c;
            T5r = iio[(vs[4])];
            T5s = iio[(vs[4]) + (rs[4])];
            T5t = T5r - T5s;
            T68 = T5r + T5s;
        }
        {
            E T5e, T5f, T5J, T5K;
            T5e = rio[(vs[4]) + (rs[2])];
            T5f = rio[(vs[4]) + (rs[6])];
            T5g = T5e + T5f;
            T5q = T5e - T5f;
            T5J = iio[(vs[4]) + (rs[2])];
            T5K = iio[(vs[4]) + (rs[6])];
            T5L = T5J - T5K;
            T69 = T5J + T5K;
        }
        T5h = T5d + T5g;
        T6e = T5d - T5g;
        T6q = T68 + T69;
        T5u = T5q + T5t;
        T5M = T5I - T5L;
        T60 = T5t - T5q;
        T6a = T68 - T69;
        T5W = T5I + T5L;
    }
    {
        E T6C, T6S, T6V, T7x, T6F, T6N, T6Q, T7y;
        {
            E T6A, T6B, T6T, T6U;
            T6A = rio[(vs[5]) + (rs[1])];
            T6B = rio[(vs[5]) + (rs[5])];
            T6C = T6A + T6B;
            T6S = T6A - T6B;
            T6T = iio[(vs[5]) + (rs[1])];
            T6U = iio[(vs[5]) + (rs[5])];
            T6V = T6T - T6U;
            T7x = T6T + T6U;
        }
        {
            E T6D, T6E, T6O, T6P;
            T6D = rio[(vs[5]) + (rs[7])];
            T6E = rio[(vs[5]) + (rs[3])];
            T6F = T6D + T6E;
            T6N = T6D - T6E;
            T6O = iio[(vs[5]) + (rs[7])];
            T6P = iio[(vs[5]) + (rs[3])];
            T6Q = T6O - T6P;
            T7y = T6O + T6P;
        }
        T6G = T6C + T6F;
        T7z = T7x - T7y;
        T7J = T7x + T7y;
        T6R = T6N - T6Q;
        T6W = T6S + T6V;
        T76 = T6N + T6Q;
        T7t = T6F - T6C;
        T75 = T6V - T6S;
    }
    {
        E T2K, T30, T33, T3F, T2N, T2V, T2Y, T3G;
        {
            E T2I, T2J, T31, T32;
            T2I = rio[(vs[2]) + (rs[1])];
            T2J = rio[(vs[2]) + (rs[5])];
            T2K = T2I + T2J;
            T30 = T2I - T2J;
            T31 = iio[(vs[2]) + (rs[1])];
            T32 = iio[(vs[2]) + (rs[5])];
            T33 = T31 - T32;
            T3F = T31 + T32;
        }
        {
            E T2L, T2M, T2W, T2X;
            T2L = rio[(vs[2]) + (rs[7])];
            T2M = rio[(vs[2]) + (rs[3])];
            T2N = T2L + T2M;
            T2V = T2L - T2M;
            T2W = iio[(vs[2]) + (rs[7])];
            T2X = iio[(vs[2]) + (rs[3])];
            T2Y = T2W - T2X;
            T3G = T2W + T2X;
        }
        T2O = T2K + T2N;
        T3H = T3F - T3G;
        T3R = T3F + T3G;
        T2Z = T2V - T2Y;
        T34 = T30 + T33;
        T3e = T2V + T2Y;
        T3B = T2N - T2K;
        T3d = T33 - T30;
    }
    {
        E T3V, T4q, T4b, T4Q, T3Y, T48, T4t, T4R;
        {
            E T3T, T3U, T49, T4a;
            T3T = rio[(vs[3])];
            T3U = rio[(vs[3]) + (rs[4])];
            T3V = T3T + T3U;
            T4q = T3T - T3U;
            T49 = iio[(vs[3])];
            T4a = iio[(vs[3]) + (rs[4])];
            T4b = T49 - T4a;
            T4Q = T49 + T4a;
        }
        {
            E T3W, T3X, T4r, T4s;
            T3W = rio[(vs[3]) + (rs[2])];
            T3X = rio[(vs[3]) + (rs[6])];
            T3Y = T3W + T3X;
            T48 = T3W - T3X;
            T4r = iio[(vs[3]) + (rs[2])];
            T4s = iio[(vs[3]) + (rs[6])];
            T4t = T4r - T4s;
            T4R = T4r + T4s;
        }
        T3Z = T3V + T3Y;
        T4W = T3V - T3Y;
        T58 = T4Q + T4R;
        T4c = T48 + T4b;
        T4u = T4q - T4t;
        T4I = T4b - T48;
        T4S = T4Q - T4R;
        T4E = T4q + T4t;
    }
    {
        E T5k, T5A, T5D, T6f, T5n, T5v, T5y, T6g;
        {
            E T5i, T5j, T5B, T5C;
            T5i = rio[(vs[4]) + (rs[1])];
            T5j = rio[(vs[4]) + (rs[5])];
            T5k = T5i + T5j;
            T5A = T5i - T5j;
            T5B = iio[(vs[4]) + (rs[1])];
            T5C = iio[(vs[4]) + (rs[5])];
            T5D = T5B - T5C;
            T6f = T5B + T5C;
        }
        {
            E T5l, T5m, T5w, T5x;
            T5l = rio[(vs[4]) + (rs[7])];
            T5m = rio[(vs[4]) + (rs[3])];
            T5n = T5l + T5m;
            T5v = T5l - T5m;
            T5w = iio[(vs[4]) + (rs[7])];
            T5x = iio[(vs[4]) + (rs[3])];
            T5y = T5w - T5x;
            T6g = T5w + T5x;
        }
        T5o = T5k + T5n;
        T6h = T6f - T6g;
        T6r = T6f + T6g;
        T5z = T5v - T5y;
        T5E = T5A + T5D;
        T5O = T5v + T5y;
        T6b = T5n - T5k;
        T5N = T5D - T5A;
    }
    {
        E T6v, T70, T6L, T7q, T6y, T6I, T73, T7r;
        {
            E T6t, T6u, T6J, T6K;
            T6t = rio[(vs[5])];
            T6u = rio[(vs[5]) + (rs[4])];
            T6v = T6t + T6u;
            T70 = T6t - T6u;
            T6J = iio[(vs[5])];
            T6K = iio[(vs[5]) + (rs[4])];
            T6L = T6J - T6K;
            T7q = T6J + T6K;
        }
        {
            E T6w, T6x, T71, T72;
            T6w = rio[(vs[5]) + (rs[2])];
            T6x = rio[(vs[5]) + (rs[6])];
            T6y = T6w + T6x;
            T6I = T6w - T6x;
            T71 = iio[(vs[5]) + (rs[2])];
            T72 = iio[(vs[5]) + (rs[6])];
            T73 = T71 - T72;
            T7r = T71 + T72;
        }
        T6z = T6v + T6y;
        T7w = T6v - T6y;
        T7I = T7q + T7r;
        T6M = T6I + T6L;
        T74 = T70 - T73;
        T7i = T6L - T6I;
        T7s = T7q - T7r;
        T7e = T70 + T73;
    }
    rio[0] = T7 + Te;
    iio[0] = T1g + T1h;
    rio[(rs[1])] = T1p + T1w;
    iio[(rs[1])] = T2y + T2z;
    rio[(rs[3])] = T3Z + T46;
    rio[(rs[2])] = T2H + T2O;
    iio[(rs[2])] = T3Q + T3R;
    iio[(rs[3])] = T58 + T59;
    rio[(rs[6])] = T7R + T7Y;
    iio[(rs[6])] = T90 + T91;
    iio[(rs[5])] = T7I + T7J;
    rio[(rs[5])] = T6z + T6G;
    iio[(rs[4])] = T6q + T6r;
    rio[(rs[4])] = T5h + T5o;
    rio[(rs[7])] = T99 + T9g;
    iio[(rs[7])] = Tai + Taj;
    {
        E T12, T18, TX, T13;
        T12 = T10 - T11;
        T18 = T14 - T17;
        TX = W[10];
        T13 = W[11];
        iio[(vs[6])] = ((TX * T12) - ((T13) * (T18)));
        rio[(vs[6])] = (((T13) * (T12)) + (TX * T18));
    }
    {
        E Tag, Tak, Taf, Tah;
        Tag = T99 - T9g;
        Tak = Tai - Taj;
        Taf = W[6];
        Tah = W[7];
        rio[(vs[4]) + (rs[7])] = (((Taf) * (Tag)) + (Tah * Tak));
        iio[(vs[4]) + (rs[7])] = ((Taf * Tak) - ((Tah) * (Tag)));
    }
    {
        E T8M, T8S, T8H, T8N;
        T8M = T8K - T8L;
        T8S = T8O - T8R;
        T8H = W[10];
        T8N = W[11];
        iio[(vs[6]) + (rs[6])] = ((T8H * T8M) - ((T8N) * (T8S)));
        rio[(vs[6]) + (rs[6])] = (((T8N) * (T8M)) + (T8H * T8S));
    }
    {
        E T2k, T2q, T2f, T2l;
        T2k = T2i - T2j;
        T2q = T2m - T2p;
        T2f = W[10];
        T2l = W[11];
        iio[(vs[6]) + (rs[1])] = ((T2f * T2k) - ((T2l) * (T2q)));
        rio[(vs[6]) + (rs[1])] = (((T2l) * (T2k)) + (T2f * T2q));
    }
    {
        E Ta4, Taa, T9Z, Ta5;
        Ta4 = Ta2 - Ta3;
        Taa = Ta6 - Ta9;
        T9Z = W[10];
        Ta5 = W[11];
        iio[(vs[6]) + (rs[7])] = ((T9Z * Ta4) - ((Ta5) * (Taa)));
        rio[(vs[6]) + (rs[7])] = (((Ta5) * (Ta4)) + (T9Z * Taa));
    }
    {
        E T8Y, T92, T8X, T8Z;
        T8Y = T7R - T7Y;
        T92 = T90 - T91;
        T8X = W[6];
        T8Z = W[7];
        rio[(vs[4]) + (rs[6])] = (((T8X) * (T8Y)) + (T8Z * T92));
        iio[(vs[4]) + (rs[6])] = ((T8X * T92) - ((T8Z) * (T8Y)));
    }
    {
        E T2w, T2A, T2v, T2x;
        T2w = T1p - T1w;
        T2A = T2y - T2z;
        T2v = W[6];
        T2x = W[7];
        rio[(vs[4]) + (rs[1])] = (((T2v) * (T2w)) + (T2x * T2A));
        iio[(vs[4]) + (rs[1])] = ((T2v * T2A) - ((T2x) * (T2w)));
    }
    {
        E Tac, Tae, Tab, Tad;
        Tac = Ta3 + Ta2;
        Tae = Ta6 + Ta9;
        Tab = W[2];
        Tad = W[3];
        iio[(vs[2]) + (rs[7])] = ((Tab * Tac) - ((Tad) * (Tae)));
        rio[(vs[2]) + (rs[7])] = (((Tad) * (Tac)) + (Tab * Tae));
    }
    {
        E T8U, T8W, T8T, T8V;
        T8U = T8L + T8K;
        T8W = T8O + T8R;
        T8T = W[2];
        T8V = W[3];
        iio[(vs[2]) + (rs[6])] = ((T8T * T8U) - ((T8V) * (T8W)));
        rio[(vs[2]) + (rs[6])] = (((T8V) * (T8U)) + (T8T * T8W));
    }
    {
        E T1a, T1c, T19, T1b;
        T1a = T11 + T10;
        T1c = T14 + T17;
        T19 = W[2];
        T1b = W[3];
        iio[(vs[2])] = ((T19 * T1a) - ((T1b) * (T1c)));
        rio[(vs[2])] = (((T1b) * (T1a)) + (T19 * T1c));
    }
    {
        E T1e, T1i, T1d, T1f;
        T1e = T7 - Te;
        T1i = T1g - T1h;
        T1d = W[6];
        T1f = W[7];
        rio[(vs[4])] = (((T1d) * (T1e)) + (T1f * T1i));
        iio[(vs[4])] = ((T1d * T1i) - ((T1f) * (T1e)));
    }
    {
        E T2s, T2u, T2r, T2t;
        T2s = T2j + T2i;
        T2u = T2m + T2p;
        T2r = W[2];
        T2t = W[3];
        iio[(vs[2]) + (rs[1])] = ((T2r * T2s) - ((T2t) * (T2u)));
        rio[(vs[2]) + (rs[1])] = (((T2t) * (T2s)) + (T2r * T2u));
    }
    {
        E T3C, T3I, T3x, T3D;
        T3C = T3A - T3B;
        T3I = T3E - T3H;
        T3x = W[10];
        T3D = W[11];
        iio[(vs[6]) + (rs[2])] = ((T3x * T3C) - ((T3D) * (T3I)));
        rio[(vs[6]) + (rs[2])] = (((T3D) * (T3C)) + (T3x * T3I));
    }
    {
        E T4U, T50, T4P, T4V;
        T4U = T4S - T4T;
        T50 = T4W - T4Z;
        T4P = W[10];
        T4V = W[11];
        iio[(vs[6]) + (rs[3])] = ((T4P * T4U) - ((T4V) * (T50)));
        rio[(vs[6]) + (rs[3])] = (((T4V) * (T4U)) + (T4P * T50));
    }
    {
        E T56, T5a, T55, T57;
        T56 = T3Z - T46;
        T5a = T58 - T59;
        T55 = W[6];
        T57 = W[7];
        rio[(vs[4]) + (rs[3])] = (((T55) * (T56)) + (T57 * T5a));
        iio[(vs[4]) + (rs[3])] = ((T55 * T5a) - ((T57) * (T56)));
    }
    {
        E T6o, T6s, T6n, T6p;
        T6o = T5h - T5o;
        T6s = T6q - T6r;
        T6n = W[6];
        T6p = W[7];
        rio[(vs[4]) + (rs[4])] = (((T6n) * (T6o)) + (T6p * T6s));
        iio[(vs[4]) + (rs[4])] = ((T6n * T6s) - ((T6p) * (T6o)));
    }
    {
        E T7u, T7A, T7p, T7v;
        T7u = T7s - T7t;
        T7A = T7w - T7z;
        T7p = W[10];
        T7v = W[11];
        iio[(vs[6]) + (rs[5])] = ((T7p * T7u) - ((T7v) * (T7A)));
        rio[(vs[6]) + (rs[5])] = (((T7v) * (T7u)) + (T7p * T7A));
    }
    {
        E T6c, T6i, T67, T6d;
        T6c = T6a - T6b;
        T6i = T6e - T6h;
        T67 = W[10];
        T6d = W[11];
        iio[(vs[6]) + (rs[4])] = ((T67 * T6c) - ((T6d) * (T6i)));
        rio[(vs[6]) + (rs[4])] = (((T6d) * (T6c)) + (T67 * T6i));
    }
    {
        E T7G, T7K, T7F, T7H;
        T7G = T6z - T6G;
        T7K = T7I - T7J;
        T7F = W[6];
        T7H = W[7];
        rio[(vs[4]) + (rs[5])] = (((T7F) * (T7G)) + (T7H * T7K));
        iio[(vs[4]) + (rs[5])] = ((T7F * T7K) - ((T7H) * (T7G)));
    }
    {
        E T3O, T3S, T3N, T3P;
        T3O = T2H - T2O;
        T3S = T3Q - T3R;
        T3N = W[6];
        T3P = W[7];
        rio[(vs[4]) + (rs[2])] = (((T3N) * (T3O)) + (T3P * T3S));
        iio[(vs[4]) + (rs[2])] = ((T3N * T3S) - ((T3P) * (T3O)));
    }
    {
        E T3K, T3M, T3J, T3L;
        T3K = T3B + T3A;
        T3M = T3E + T3H;
        T3J = W[2];
        T3L = W[3];
        iio[(vs[2]) + (rs[2])] = ((T3J * T3K) - ((T3L) * (T3M)));
        rio[(vs[2]) + (rs[2])] = (((T3L) * (T3K)) + (T3J * T3M));
    }
    {
        E T7C, T7E, T7B, T7D;
        T7C = T7t + T7s;
        T7E = T7w + T7z;
        T7B = W[2];
        T7D = W[3];
        iio[(vs[2]) + (rs[5])] = ((T7B * T7C) - ((T7D) * (T7E)));
        rio[(vs[2]) + (rs[5])] = (((T7D) * (T7C)) + (T7B * T7E));
    }
    {
        E T6k, T6m, T6j, T6l;
        T6k = T6b + T6a;
        T6m = T6e + T6h;
        T6j = W[2];
        T6l = W[3];
        iio[(vs[2]) + (rs[4])] = ((T6j * T6k) - ((T6l) * (T6m)));
        rio[(vs[2]) + (rs[4])] = (((T6l) * (T6k)) + (T6j * T6m));
    }
    {
        E T52, T54, T51, T53;
        T52 = T4T + T4S;
        T54 = T4W + T4Z;
        T51 = W[2];
        T53 = W[3];
        iio[(vs[2]) + (rs[3])] = ((T51 * T52) - ((T53) * (T54)));
        rio[(vs[2]) + (rs[3])] = (((T53) * (T52)) + (T51 * T54));
    }
    {
        E T5G, T5S, T5Q, T5U, T5F, T5P;
        T5F = KP707106781 * (T5z - T5E);
        T5G = T5u - T5F;
        T5S = T5u + T5F;
        T5P = KP707106781 * (T5N - T5O);
        T5Q = T5M - T5P;
        T5U = T5M + T5P;
        {
            E T5p, T5H, T5R, T5T;
            T5p = W[12];
            T5H = W[13];
            iio[(vs[7]) + (rs[4])] = ((T5p * T5G) - ((T5H) * (T5Q)));
            rio[(vs[7]) + (rs[4])] = (((T5H) * (T5G)) + (T5p * T5Q));
            T5R = W[4];
            T5T = W[5];
            iio[(vs[3]) + (rs[4])] = ((T5R * T5S) - ((T5T) * (T5U)));
            rio[(vs[3]) + (rs[4])] = (((T5T) * (T5S)) + (T5R * T5U));
        }
    }
    {
        E Tw, TI, TG, TK, Tv, TF;
        Tv = KP707106781 * (Tp - Tu);
        Tw = Tk - Tv;
        TI = Tk + Tv;
        TF = KP707106781 * (TD - TE);
        TG = TC - TF;
        TK = TC + TF;
        {
            E Tf, Tx, TH, TJ;
            Tf = W[12];
            Tx = W[13];
            iio[(vs[7])] = ((Tf * Tw) - ((Tx) * (TG)));
            rio[(vs[7])] = (((Tx) * (Tw)) + (Tf * TG));
            TH = W[4];
            TJ = W[5];
            iio[(vs[3])] = ((TH * TI) - ((TJ) * (TK)));
            rio[(vs[3])] = (((TJ) * (TI)) + (TH * TK));
        }
    }
    {
        E T9Q, T9W, T9U, T9Y, T9P, T9T;
        T9P = KP707106781 * (T9w + T9r);
        T9Q = T9O - T9P;
        T9W = T9O + T9P;
        T9T = KP707106781 * (T9F + T9G);
        T9U = T9S - T9T;
        T9Y = T9S + T9T;
        {
            E T9N, T9R, T9V, T9X;
            T9N = W[8];
            T9R = W[9];
            rio[(vs[5]) + (rs[7])] = (((T9N) * (T9Q)) + (T9R * T9U));
            iio[(vs[5]) + (rs[7])] = ((T9N * T9U) - ((T9R) * (T9Q)));
            T9V = W[0];
            T9X = W[1];
            rio[(vs[1]) + (rs[7])] = (((T9V) * (T9W)) + (T9X * T9Y));
            iio[(vs[1]) + (rs[7])] = ((T9V * T9Y) - ((T9X) * (T9W)));
        }
    }
    {
        E T36, T3i, T3g, T3k, T35, T3f;
        T35 = KP707106781 * (T2Z - T34);
        T36 = T2U - T35;
        T3i = T2U + T35;
        T3f = KP707106781 * (T3d - T3e);
        T3g = T3c - T3f;
        T3k = T3c + T3f;
        {
            E T2P, T37, T3h, T3j;
            T2P = W[12];
            T37 = W[13];
            iio[(vs[7]) + (rs[2])] = ((T2P * T36) - ((T37) * (T3g)));
            rio[(vs[7]) + (rs[2])] = (((T37) * (T36)) + (T2P * T3g));
            T3h = W[4];
            T3j = W[5];
            iio[(vs[3]) + (rs[2])] = ((T3h * T3i) - ((T3j) * (T3k)));
            rio[(vs[3]) + (rs[2])] = (((T3j) * (T3i)) + (T3h * T3k));
        }
    }
    {
        E T5Y, T64, T62, T66, T5X, T61;
        T5X = KP707106781 * (T5E + T5z);
        T5Y = T5W - T5X;
        T64 = T5W + T5X;
        T61 = KP707106781 * (T5N + T5O);
        T62 = T60 - T61;
        T66 = T60 + T61;
        {
            E T5V, T5Z, T63, T65;
            T5V = W[8];
            T5Z = W[9];
            rio[(vs[5]) + (rs[4])] = (((T5V) * (T5Y)) + (T5Z * T62));
            iio[(vs[5]) + (rs[4])] = ((T5V * T62) - ((T5Z) * (T5Y)));
            T63 = W[0];
            T65 = W[1];
            rio[(vs[1]) + (rs[4])] = (((T63) * (T64)) + (T65 * T66));
            iio[(vs[1]) + (rs[4])] = ((T63 * T66) - ((T65) * (T64)));
        }
    }
    {
        E T7g, T7m, T7k, T7o, T7f, T7j;
        T7f = KP707106781 * (T6W + T6R);
        T7g = T7e - T7f;
        T7m = T7e + T7f;
        T7j = KP707106781 * (T75 + T76);
        T7k = T7i - T7j;
        T7o = T7i + T7j;
        {
            E T7d, T7h, T7l, T7n;
            T7d = W[8];
            T7h = W[9];
            rio[(vs[5]) + (rs[5])] = (((T7d) * (T7g)) + (T7h * T7k));
            iio[(vs[5]) + (rs[5])] = ((T7d * T7k) - ((T7h) * (T7g)));
            T7l = W[0];
            T7n = W[1];
            rio[(vs[1]) + (rs[5])] = (((T7l) * (T7m)) + (T7n * T7o));
            iio[(vs[1]) + (rs[5])] = ((T7l * T7o) - ((T7n) * (T7m)));
        }
    }
    {
        E T8g, T8s, T8q, T8u, T8f, T8p;
        T8f = KP707106781 * (T89 - T8e);
        T8g = T84 - T8f;
        T8s = T84 + T8f;
        T8p = KP707106781 * (T8n - T8o);
        T8q = T8m - T8p;
        T8u = T8m + T8p;
        {
            E T7Z, T8h, T8r, T8t;
            T7Z = W[12];
            T8h = W[13];
            iio[(vs[7]) + (rs[6])] = ((T7Z * T8g) - ((T8h) * (T8q)));
            rio[(vs[7]) + (rs[6])] = (((T8h) * (T8g)) + (T7Z * T8q));
            T8r = W[4];
            T8t = W[5];
            iio[(vs[3]) + (rs[6])] = ((T8r * T8s) - ((T8t) * (T8u)));
            rio[(vs[3]) + (rs[6])] = (((T8t) * (T8s)) + (T8r * T8u));
        }
    }
    {
        E T4G, T4M, T4K, T4O, T4F, T4J;
        T4F = KP707106781 * (T4m + T4h);
        T4G = T4E - T4F;
        T4M = T4E + T4F;
        T4J = KP707106781 * (T4v + T4w);
        T4K = T4I - T4J;
        T4O = T4I + T4J;
        {
            E T4D, T4H, T4L, T4N;
            T4D = W[8];
            T4H = W[9];
            rio[(vs[5]) + (rs[3])] = (((T4D) * (T4G)) + (T4H * T4K));
            iio[(vs[5]) + (rs[3])] = ((T4D * T4K) - ((T4H) * (T4G)));
            T4L = W[0];
            T4N = W[1];
            rio[(vs[1]) + (rs[3])] = (((T4L) * (T4M)) + (T4N * T4O));
            iio[(vs[1]) + (rs[3])] = ((T4L * T4O) - ((T4N) * (T4M)));
        }
    }
    {
        E TO, TU, TS, TW, TN, TR;
        TN = KP707106781 * (Tu + Tp);
        TO = TM - TN;
        TU = TM + TN;
        TR = KP707106781 * (TD + TE);
        TS = TQ - TR;
        TW = TQ + TR;
        {
            E TL, TP, TT, TV;
            TL = W[8];
            TP = W[9];
            rio[(vs[5])] = (((TL) * (TO)) + (TP * TS));
            iio[(vs[5])] = ((TL * TS) - ((TP) * (TO)));
            TT = W[0];
            TV = W[1];
            rio[(vs[1])] = (((TT) * (TU)) + (TV * TW));
            iio[(vs[1])] = ((TT * TW) - ((TV) * (TU)));
        }
    }
    {
        E T26, T2c, T2a, T2e, T25, T29;
        T25 = KP707106781 * (T1M + T1H);
        T26 = T24 - T25;
        T2c = T24 + T25;
        T29 = KP707106781 * (T1V + T1W);
        T2a = T28 - T29;
        T2e = T28 + T29;
        {
            E T23, T27, T2b, T2d;
            T23 = W[8];
            T27 = W[9];
            rio[(vs[5]) + (rs[1])] = (((T23) * (T26)) + (T27 * T2a));
            iio[(vs[5]) + (rs[1])] = ((T23 * T2a) - ((T27) * (T26)));
            T2b = W[0];
            T2d = W[1];
            rio[(vs[1]) + (rs[1])] = (((T2b) * (T2c)) + (T2d * T2e));
            iio[(vs[1]) + (rs[1])] = ((T2b * T2e) - ((T2d) * (T2c)));
        }
    }
    {
        E T9y, T9K, T9I, T9M, T9x, T9H;
        T9x = KP707106781 * (T9r - T9w);
        T9y = T9m - T9x;
        T9K = T9m + T9x;
        T9H = KP707106781 * (T9F - T9G);
        T9I = T9E - T9H;
        T9M = T9E + T9H;
        {
            E T9h, T9z, T9J, T9L;
            T9h = W[12];
            T9z = W[13];
            iio[(vs[7]) + (rs[7])] = ((T9h * T9y) - ((T9z) * (T9I)));
            rio[(vs[7]) + (rs[7])] = (((T9z) * (T9y)) + (T9h * T9I));
            T9J = W[4];
            T9L = W[5];
            iio[(vs[3]) + (rs[7])] = ((T9J * T9K) - ((T9L) * (T9M)));
            rio[(vs[3]) + (rs[7])] = (((T9L) * (T9K)) + (T9J * T9M));
        }
    }
    {
        E T6Y, T7a, T78, T7c, T6X, T77;
        T6X = KP707106781 * (T6R - T6W);
        T6Y = T6M - T6X;
        T7a = T6M + T6X;
        T77 = KP707106781 * (T75 - T76);
        T78 = T74 - T77;
        T7c = T74 + T77;
        {
            E T6H, T6Z, T79, T7b;
            T6H = W[12];
            T6Z = W[13];
            iio[(vs[7]) + (rs[5])] = ((T6H * T6Y) - ((T6Z) * (T78)));
            rio[(vs[7]) + (rs[5])] = (((T6Z) * (T6Y)) + (T6H * T78));
            T79 = W[4];
            T7b = W[5];
            iio[(vs[3]) + (rs[5])] = ((T79 * T7a) - ((T7b) * (T7c)));
            rio[(vs[3]) + (rs[5])] = (((T7b) * (T7a)) + (T79 * T7c));
        }
    }
    {
        E T1O, T20, T1Y, T22, T1N, T1X;
        T1N = KP707106781 * (T1H - T1M);
        T1O = T1C - T1N;
        T20 = T1C + T1N;
        T1X = KP707106781 * (T1V - T1W);
        T1Y = T1U - T1X;
        T22 = T1U + T1X;
        {
            E T1x, T1P, T1Z, T21;
            T1x = W[12];
            T1P = W[13];
            iio[(vs[7]) + (rs[1])] = ((T1x * T1O) - ((T1P) * (T1Y)));
            rio[(vs[7]) + (rs[1])] = (((T1P) * (T1O)) + (T1x * T1Y));
            T1Z = W[4];
            T21 = W[5];
            iio[(vs[3]) + (rs[1])] = ((T1Z * T20) - ((T21) * (T22)));
            rio[(vs[3]) + (rs[1])] = (((T21) * (T20)) + (T1Z * T22));
        }
    }
    {
        E T4o, T4A, T4y, T4C, T4n, T4x;
        T4n = KP707106781 * (T4h - T4m);
        T4o = T4c - T4n;
        T4A = T4c + T4n;
        T4x = KP707106781 * (T4v - T4w);
        T4y = T4u - T4x;
        T4C = T4u + T4x;
        {
            E T47, T4p, T4z, T4B;
            T47 = W[12];
            T4p = W[13];
            iio[(vs[7]) + (rs[3])] = ((T47 * T4o) - ((T4p) * (T4y)));
            rio[(vs[7]) + (rs[3])] = (((T4p) * (T4o)) + (T47 * T4y));
            T4z = W[4];
            T4B = W[5];
            iio[(vs[3]) + (rs[3])] = ((T4z * T4A) - ((T4B) * (T4C)));
            rio[(vs[3]) + (rs[3])] = (((T4B) * (T4A)) + (T4z * T4C));
        }
    }
    {
        E T3o, T3u, T3s, T3w, T3n, T3r;
        T3n = KP707106781 * (T34 + T2Z);
        T3o = T3m - T3n;
        T3u = T3m + T3n;
        T3r = KP707106781 * (T3d + T3e);
        T3s = T3q - T3r;
        T3w = T3q + T3r;
        {
            E T3l, T3p, T3t, T3v;
            T3l = W[8];
            T3p = W[9];
            rio[(vs[5]) + (rs[2])] = (((T3l) * (T3o)) + (T3p * T3s));
            iio[(vs[5]) + (rs[2])] = ((T3l * T3s) - ((T3p) * (T3o)));
            T3t = W[0];
            T3v = W[1];
            rio[(vs[1]) + (rs[2])] = (((T3t) * (T3u)) + (T3v * T3w));
            iio[(vs[1]) + (rs[2])] = ((T3t * T3w) - ((T3v) * (T3u)));
        }
    }
    {
        E T8y, T8E, T8C, T8G, T8x, T8B;
        T8x = KP707106781 * (T8e + T89);
        T8y = T8w - T8x;
        T8E = T8w + T8x;
        T8B = KP707106781 * (T8n + T8o);
        T8C = T8A - T8B;
        T8G = T8A + T8B;
        {
            E T8v, T8z, T8D, T8F;
            T8v = W[8];
            T8z = W[9];
            rio[(vs[5]) + (rs[6])] = (((T8v) * (T8y)) + (T8z * T8C));
            iio[(vs[5]) + (rs[6])] = ((T8v * T8C) - ((T8z) * (T8y)));
            T8D = W[0];
            T8F = W[1];
            rio[(vs[1]) + (rs[6])] = (((T8D) * (T8E)) + (T8F * T8G));
            iio[(vs[1]) + (rs[6])] = ((T8D * T8G) - ((T8F) * (T8E)));
        }
    }
}
}
