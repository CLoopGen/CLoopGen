#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *R0;
R *R1;
R *Cr;
R *Ci;

stride rs;
stride csr;
stride csi;

INT v;
INT ivs;
INT ovs;

E KP1_996053456 = 1.996053456;
E KP062790519 = 0.062790519;
E KP125581039 = 1.25581039;
E KP998026728 = 0.998026728;
E KP1_369094211 = 1.369094211;
E KP728968627 = 0.728968627;
E KP963507348 = 0.963507348;
E KP876306680 = 0.876306680;
E KP497379774 = 0.497379774;
E KP968583161 = 0.968583161;
E KP1_457937254 = 1.457937254;
E KP684547105 = 0.684547105;
E KP1_752613360 = 1.752613360;
E KP481753674 = 0.481753674;
E KP1_937166322 = 1.937166322;
E KP248689887 = 0.248689887;
E KP992114701 = 0.992114701;
E KP250666467 = 0.250666467;
E KP1_809654104 = 1.809654104;
E KP425779291 = 0.425779291;
E KP1_541026485 = 1.541026485;
E KP637423989 = 0.637423989;
E KP1_688655851 = 1.688655851;
E KP535826794 = 0.535826794;
E KP851558583 = 0.851558583;
E KP904827052 = 0.904827052;
E KP1_984229402 = 1.984229402;
E KP125333233 = 0.125333233;
E KP1_274847979 = 1.274847979;
E KP770513242 = 0.770513242;
E KP844327925 = 0.844327925;
E KP1_071653589 = 1.071653589;
E KP293892626 = 0.293892626;
E KP475528258 = 0.475528258;
E KP250000000 = 0.250000000;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
E KP559016994 = 0.559016994;

INT i;

void init_vars() {
    const size_t data_size_bytes = 64 * 1024 * 1024; // ~64MB for reasonable timing (~0.01s)
    const size_t num_elements = data_size_bytes / sizeof(R);

    R0 = (R*)aligned_alloc(64, num_elements * sizeof(R));
    R1 = (R*)aligned_alloc(64, num_elements * sizeof(R));
    Cr = (R*)aligned_alloc(64, num_elements * sizeof(R));
    Ci = (R*)aligned_alloc(64, num_elements * sizeof(R));

    if (!R0 || !R1 || !Cr || !Ci) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        R0[idx] = sin(idx * 0.01);
        R1[idx] = cos(idx * 0.01);
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    rs = (stride)aligned_alloc(64, 13 * sizeof(INT));
    csr = (stride)aligned_alloc(64, 13 * sizeof(INT));
    csi = (stride)aligned_alloc(64, 13 * sizeof(INT));

    if (!rs || !csr || !csi) {
        fprintf(stderr, "Stride allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 13; ++j) {
        rs[j] = (j + 1) % 13;
        csr[j] = (j * 2) % 13;
        csi[j] = (j * 3) % 13;
    }

    ivs = 1;
    ovs = 1;
    v = 1000000; // Ensure loop runs enough times to touch allocated data safely and take measurable time

    i = 0;
}