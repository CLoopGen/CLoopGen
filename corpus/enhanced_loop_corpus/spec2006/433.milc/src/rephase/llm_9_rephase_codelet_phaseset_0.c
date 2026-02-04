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
int limit = sites_on_node / 2;
for (i = 0; i < limit; i++) {
    site *forward = &lattice[i];
    site *backward = &lattice[sites_on_node - 1 - i];

    forward->phase[3] = 1.0;
    backward->phase[3] = 1.0;

    forward->phase[0] = ((forward->t) % 2 == 1) ? -1.0 : 1.0;
    backward->phase[0] = ((backward->t) % 2 == 1) ? -1.0 : 1.0;

    forward->phase[1] = ((forward->x) % 2 == 1) ? -forward->phase[0] : forward->phase[0];
    backward->phase[1] = ((backward->x) % 2 == 1) ? -backward->phase[0] : backward->phase[0];

    forward->phase[2] = ((forward->y) % 2 == 1) ? -forward->phase[1] : forward->phase[1];
    backward->phase[2] = ((backward->y) % 2 == 1) ? -backward->phase[1] : backward->phase[1];

    if (forward->t == nt - 1) forward->phase[3] = -forward->phase[3];
    if (backward->t == nt - 1) backward->phase[3] = -backward->phase[3];
}

if (sites_on_node % 2 == 1) {
    sit = &lattice[sites_on_node / 2];
    sit->phase[3] = 1.0;
    sit->phase[0] = ((sit->t) % 2 == 1) ? -1.0 : 1.0;
    sit->phase[1] = ((sit->x) % 2 == 1) ? -sit->phase[0] : sit->phase[0];
    sit->phase[2] = ((sit->y) % 2 == 1) ? -sit->phase[1] : sit->phase[1];
    if (sit->t == nt - 1) sit->phase[3] = -sit->phase[3];
}
}
