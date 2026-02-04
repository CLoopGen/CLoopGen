#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// External pointers and scalars
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

// Constants (E type, i.e., double)
E KP998026728   = 0.998026728;
E KP125581039   = 0.125581039;
E KP1_996053456 = 1.996053456;
E KP062790519   = 0.062790519;
E KP809016994   = 0.809016994;
E KP309016994   = 0.309016994;
E KP1_369094211 = 1.369094211;
E KP728968627   = 0.728968627;
E KP963507348   = 0.963507348;
E KP876306680   = 0.876306680;
E KP497379774   = 0.497379774;
E KP968583161   = 0.968583161;
E KP684547105   = 0.684547105;
E KP1_457937254 = 1.457937254;
E KP481753674   = 0.481753674;
E KP1_752613360 = 1.752613360;
E KP248689887   = 0.248689887;
E KP1_937166322 = 1.937166322;
E KP992114701   = 0.992114701;
E KP250666467   = 0.250666467;
E KP425779291   = 0.425779291;
E KP1_809654104 = 1.809654104;
E KP1_274847979 = 1.274847979;
E KP770513242   = 0.770513242;
E KP844327925   = 0.844327925;
E KP1_071653589 = 1.071653589;
E KP125333233   = 0.125333233;
E KP1_984229402 = 1.984229402;
E KP904827052   = 0.904827052;
E KP851558583   = 0.851558583;
E KP637423989   = 0.637423989;
E KP1_541026485 = 1.541026485;
E KP535826794   = 0.535826794;
E KP1_688655851 = 1.688655851;
E KP293892626   = 0.293892626;
E KP475528258   = 0.475528258;
E KP250000000   = 0.250000000;
E KP559016994   = 0.559016994;
E KP587785252   = 0.587785252;
E KP951056516   = 0.951056516;

INT i;

// Function declaration to avoid implicit declaration error
void loop(void);

void init_vars() {
    // Target: make loop run ~0.01 seconds -> aim for moderate data size
    // Heuristic: use ~16 million iterations (adjustable) with moderate memory footprint
    const size_t N = 1 << 20;  // 1M elements per array

    // Allocate arrays with sufficient padding to prevent out-of-bounds access
    // The loop accesses indices up to 12 in R0/R1 via rs, so ensure rs values are valid
    R0 = (R*)aligned_alloc(32, (13 + 1) * sizeof(R));
    R1 = (R*)aligned_alloc(32, (13 + 1) * sizeof(R));
    Cr = (R*)aligned_alloc(32, (13 + 1) * sizeof(R));
    Ci = (R*)aligned_alloc(32, (13 + 1) * sizeof(R));

    rs  = (stride)aligned_alloc(32, 13 * sizeof(INT));
    csr = (stride)aligned_alloc(32, 13 * sizeof(INT));
    csi = (stride)aligned_alloc(32, 13 * sizeof(INT));

    // Initialize stride arrays: map logical offsets to physical offsets
    // Use identity mapping: rs[i] = i, so R0[(rs[k])] = R0[k]
    for (int j = 0; j < 13; j++) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    // Initialize data arrays with non-zero values to allow computation
    for (int j = 0; j < 13; j++) {
        R0[j] = sin(j + 1);
        R1[j] = cos(j + 1);
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }

    // Set loop parameters
    v = 100000;     // number of loop iterations
    ivs = 1;        // input vector stride (step by 1 element per iteration)
    ovs = 1;        // output vector stride

    // Ensure that during loop:
    // R0 += ivs * v does not go out of bounds
    // So we need at least v * ivs steps forward possible
    // But our R0 is only 13 long -> so we must reuse base pointer
    // Therefore: the loop logic assumes circular or repeated access?
    // But code uses R0[0], R0[rs[5]], etc. — these are fixed offsets from base

    // Actually, the loop updates: R0 = R0 + ivs each iteration
    // So we need enough room: initial R0 must have at least v * ivs + max_offset
    const size_t total_data_size = v * ivs + 13;
    free(R0); free(R1); free(Cr); free(Ci);
    R0 = (R*)aligned_alloc(32, total_data_size * sizeof(R));
    R1 = (R*)aligned_alloc(32, total_data_size * sizeof(R));
    Cr = (R*)aligned_alloc(32, total_data_size * sizeof(R));
    Ci = (R*)aligned_alloc(32, total_data_size * sizeof(R));

    // Re-initialize data
    for (size_t j = 0; j < total_data_size; j++) {
        R0[j] = sin((double)(j % 1000) / 100.0);
        R1[j] = cos((double)(j % 1000) / 100.0);
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }

    // Reset strides to identity over extended range
    free(rs); free(csr); free(csi);
    rs  = (stride)aligned_alloc(32, 13 * sizeof(INT));
    csr = (stride)aligned_alloc(32, 13 * sizeof(INT));
    csi = (stride)aligned_alloc(32, 13 * sizeof(INT));
    for (int j = 0; j < 13; j++) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    // Final check: after v iterations, R0 will be incremented by v * ivs
    // So initial R0 must point to start, and we access up to index 12 beyond current R0
    // So as long as total_data_size >= v * ivs + 13, safe.
}