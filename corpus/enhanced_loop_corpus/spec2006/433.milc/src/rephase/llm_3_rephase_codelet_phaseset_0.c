#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long r0;
    unsigned long r1;
    unsigned long r2;
    unsigned long r3;
    unsigned long r4;
    unsigned long r5;
    unsigned long r6;
    unsigned long multiplier;
    unsigned long addend;
    unsigned long ic_state;
    double scale;
} double_prn;

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

typedef struct {
    complex m01;
    complex m02;
    complex m12;
    double m00im;
    double m11im;
    double m22im;
    double space;
} anti_hermitmat;

typedef struct {
    complex c[3];
} su3_vector;

typedef struct {
    short x;
    short y;
    short z;
    short t;
    char parity;
    int index;
    double_prn site_prn;
    int space1;
    su3_matrix link[4];
    anti_hermitmat mom[4];
    double phase[4];
    su3_vector phi;
    su3_vector resid;
    su3_vector cg_p;
    su3_vector xxx;
    su3_vector ttt;
    su3_vector g_rand;
    su3_vector tempvec[4];
    su3_vector templongvec[4];
    su3_vector templongv1;
    su3_matrix tempmat1;
    su3_matrix staple;
} site;

extern int nt;
extern int sites_on_node;
extern site *lattice;
extern site *sit;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Step Size > 1 (simulating non-unit stride)
    // Process every second site in forward direction, then fill in the gaps in a second pass
    // This creates a strided access pattern with stride 2
    int stride = 2;
    
    // First pass: process even indices (0, 2, 4, ...)
    for (i = 0; i < sites_on_node; i += stride) {
        site *sit = &lattice[i];
        sit->phase[3] = 1.;
        if ((sit->t) % 2 == 1)
            sit->phase[0] = -1.;
        else
            sit->phase[0] = 1.;
        if ((sit->x) % 2 == 1)
            sit->phase[1] = -sit->phase[0];
        else
            sit->phase[1] = sit->phase[0];
        if ((sit->y) % 2 == 1)
            sit->phase[2] = -sit->phase[1];
        else
            sit->phase[2] = sit->phase[1];
        if (sit->t == nt - 1) {
            sit->phase[3] = -sit->phase[3];
        }
    }

    // Second pass: process odd indices (1, 3, 5, ...)
    for (i = 1; i < sites_on_node; i += stride) {
        site *sit = &lattice[i];
        sit->phase[3] = 1.;
        if ((sit->t) % 2 == 1)
            sit->phase[0] = -1.;
        else
            sit->phase[0] = 1.;
        if ((sit->x) % 2 == 1)
            sit->phase[1] = -sit->phase[0];
        else
            sit->phase[1] = sit->phase[0];
        if ((sit->y) % 2 == 1)
            sit->phase[2] = -sit->phase[1];
        else
            sit->phase[2] = sit->phase[1];
        if (sit->t == nt - 1) {
            sit->phase[3] = -sit->phase[3];
        }
    }
}
