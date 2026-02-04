#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
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

typedef int field_offset;

int sites_on_node = 65536;
int even_sites_on_node = 32768;
site *lattice;
field_offset src;
field_offset dest;
int parity = 0;
int i;
site *s;

void init_vars() {
    lattice = (site*)calloc(sites_on_node, sizeof(site));
    if (!lattice) exit(1);

    src = offsetof(site, phi);
    dest = offsetof(site, resid);

    for (int idx = 0; idx < sites_on_node; idx++) {
        site* s = &lattice[idx];
        for (int j = 0; j < 3; j++) {
            s->phi.c[j].real = 1.0;
            s->phi.c[j].imag = 0.0;
            s->resid.c[j].real = 0.0;
            s->resid.c[j].imag = 0.0;
        }
    }

    parity = 0;
    i = 0;
    s = &(lattice[i]);
}