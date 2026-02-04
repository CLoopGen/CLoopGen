#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

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
extern  E KP1_996053456;
extern  E KP062790519;
extern  E KP125581039;
extern  E KP998026728;
extern  E KP1_369094211;
extern  E KP728968627;
extern  E KP963507348;
extern  E KP876306680;
extern  E KP497379774;
extern  E KP968583161;
extern  E KP1_457937254;
extern  E KP684547105;
extern  E KP1_752613360;
extern  E KP481753674;
extern  E KP1_937166322;
extern  E KP248689887;
extern  E KP992114701;
extern  E KP250666467;
extern  E KP1_809654104;
extern  E KP425779291;
extern  E KP1_541026485;
extern  E KP637423989;
extern  E KP1_688655851;
extern  E KP535826794;
extern  E KP851558583;
extern  E KP904827052;
extern  E KP1_984229402;
extern  E KP125333233;
extern  E KP1_274847979;
extern  E KP770513242;
extern  E KP844327925;
extern  E KP1_071653589;
extern  E KP293892626;
extern  E KP475528258;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i--, R0 += ivs, R1 += ivs, Cr += ovs, Ci += ovs) {
    E TE, TR, T2i, T1z, TL, TS, TB, T2d, T1l, T1i, T2c, T9, T23, TZ, TW;
    E T22, Ti, T26, T16, T13, T25, Ts, T2a, T1e, T1b, T29, TP, TQ;
    
    INT idx_r0[13], idx_r1[13], idx_csr[13], idx_csi[13];
    for (INT j = 0; j < 13; ++j) {
        idx_r0[j] = rs[j];
        idx_r1[j] = rs[j];
        idx_csr[j] = csr[j];
        idx_csi[j] = csi[j];
    }

    TE = R0[0];
    {
        E TI = R0[idx_r0[10]], TJ = R1[idx_r1[2]];
        E TK = TI - TJ;
        E T1y = TI + TJ;
        E TF = R0[idx_r0[5]], TG = R1[idx_r1[7]];
        E TH = TF - TG;
        E T1x = TF + TG;
        TR = KP559016994 * (TH - TK);
        T2i = KP951056516 * T1y - KP587785252 * T1x;
        T1z = KP951056516 * T1x + KP587785252 * T1y;
        TL = TH + TK;
        TS = TE - KP250000000 * TL;
    }

    T9 = R0[idx_r0[1]] + (R0[idx_r0[6]] - R1[idx_r1[8]]) + (R0[idx_r0[11]] - R1[idx_r1[3]]);
    TZ = KP475528258 * (R0[idx_r0[6]] + R1[idx_r1[8]]) + KP293892626 * (R0[idx_r0[11]] + R1[idx_r1[3]]);
    TW = KP559016994 * ((R0[idx_r0[6]] - R1[idx_r1[8]]) - (R0[idx_r0[11]] - R1[idx_r1[3]])) + (R0[idx_r0[1]] - KP250000000 * ((R0[idx_r0[6]] - R1[idx_r1[8]]) + (R0[idx_r0[11]] - R1[idx_r1[3]])));

    Ti = R0[idx_r0[4]] + (R0[idx_r0[9]] - R1[idx_r1[11]] - (R1[idx_r1[1]] + R1[idx_r1[6]]));
    T16 = KP475528258 * (R0[idx_r0[9]] + R1[idx_r1[11]]) + KP293892626 * (R1[idx_r1[6]] - R1[idx_r1[1]]);
    T13 = KP559016994 * (R0[idx_r0[9]] - R1[idx_r1[11]] + R1[idx_r1[1]] + R1[idx_r1[6]]) + (R0[idx_r0[4]] - KP250000000 * (R0[idx_r0[9]] - R1[idx_r1[11]] - R1[idx_r1[1]] - R1[idx_r1[6]]));

    Ts = R0[idx_r0[2]] + (R0[idx_r0[7]] - R1[idx_r1[9]] + R0[idx_r0[12]] - R1[idx_r1[4]]);
    T1e = KP475528258 * (R0[idx_r0[7]] + R1[idx_r1[9]]) + KP293892626 * (R0[idx_r0[12]] + R1[idx_r1[4]]);
    T1b = KP559016994 * (R0[idx_r0[7]] - R1[idx_r1[9]] - (R0[idx_r0[12]] - R1[idx_r1[4]])) + (R0[idx_r0[2]] - KP250000000 * (R0[idx_r0[7]] - R1[idx_r1[9]] + R0[idx_r0[12]] - R1[idx_r1[4]]));

    TB = R0[idx_r0[3]] + (R0[idx_r0[8]] - R1[idx_r1[10]] - (R1[0] + R1[idx_r1[5]]));
    T1l = KP475528258 * (R0[idx_r0[8]] + R1[idx_r1[10]]) + KP293892626 * (R1[idx_r1[5]] - R1[0]);
    T1i = KP559016994 * (R0[idx_r0[8]] - R1[idx_r1[10]] + R1[0] + R1[idx_r1[5]]) + (R0[idx_r0[3]] - KP250000000 * (R0[idx_r0[8]] - R1[idx_r1[10]] - R1[0] - R1[idx_r1[5]]));

    TP = TB - Ts;
    TQ = T9 - Ti;

    Ci[idx_csi[2]] = KP587785252 * TP - KP951056516 * TQ;
    Ci[idx_csi[7]] = KP587785252 * TQ + KP951056516 * TP;

    E TM = TE + TL;
    E Tj = T9 + Ti;
    E TC = Ts + TB;
    E TD = KP559016994 * (Tj - TC);
    E TN = Tj + TC;

    Cr[idx_csr[12]] = TM + TN;
    Cr[idx_csr[2]] = TD + (TM - KP250000000 * TN);
    Cr[idx_csr[7]] = (TM - KP250000000 * TN) - TD;

    E TT = TR + TS;
    E T1o = /* Combined from T1J, T1U, T1P, T1M, T18, T1n */
        (KP1_071653589*TZ - KP844327925*TW - (KP770513242*T13 - KP1_274847979*T16))
        + (KP125333233*T1i + KP1_984229402*T1l - (KP904827052*T1b + KP851558583*T1e))
        + (KP535826794*TW + KP1_688655851*TZ - (KP637423989*T13 + KP1_541026485*T16))
        + (KP425779291*T1b - KP1_809654104*T1e - (KP250666467*T1l - KP992114701*T1i))
        + (KP968583161*TW - KP497379774*TZ + KP535826794*T13 - KP1_688655851*T16)
        + (KP876306680*T1b - KP963507348*T1e + KP728968627*T1i - KP1_369094211*T1l);

    E T1C = /* Similar aggregation of symmetric terms */
        (KP1_071653589*TZ + KP844327925*TW + KP770513242*T13 + KP1_274847979*T16)
        + (KP125333233*T1i + KP1_984229402*T1l + KP904827052*T1b + KP851558583*T1e)
        + (KP535826794*TW + KP1_688655851*TZ + KP637423989*T13 + KP1_541026485*T16)
        + (KP425779291*T1b - KP1_809654104*T1e + KP250666467*T1l - KP992114701*T1i)
        + (KP844327925*T13 + KP1_071653589*T16 + KP248689887*TW + KP1_937166322*TZ)
        + (KP481753674*T1b + KP1_752613360*T1e + KP684547105*T1i + KP1_457937254*T1l);

    Cr[0] = TT + T1o;
    Ci[0] = -(T1z + T1C);

    E T21 = TS - TR;
    E T2g = /* Aggregated real part output */
        (KP1_071653589*T2a + KP844327925*T29 + KP998026728*T2c + KP125581039*T2d)
        + (KP535826794*T29 + KP1_688655851*T2a + KP062790519*T2c + KP1_996053456*T2d)
        + (KP1_984229402*T26 - KP125333233*T25 + KP684547105*T22 + KP1_457937254*T23)
        + (KP728968627*T22 - KP1_369094211*T23 - (KP992114701*T25 + KP250666467*T26))
        + (KP062790519*T29 - KP1_996053456*T2a - (KP637423989*T2c + KP1_541026485*T2d));

    E T2p = /* Imaginary counterpart */
        (KP1_752613360*T23 - KP481753674*T22 + KP904827052*T25 + KP851558583*T26)
        + (KP876306680*T22 + KP963507348*T23 + KP1_809654104*T26 - KP425779291*T25)
        + (KP1_984229402*T26 - KP125333233*T25 - (KP684547105*T22 + KP1_457937254*T23))
        + (KP1_274847979*T2d - KP770513242*T2c - (KP998026728*T29 + KP125581039*T2a))
        + (KP728968627*T22 - KP1_369094211*T23 + KP992114701*T25 - KP250666467*T26);

    Cr[idx_csr[1]] = T21 + T2g;
    Ci[idx_csi[1]] = T2p - T2i;
}
}
