#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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

typedef struct {
    su3_vector h[2];
} half_wilson_vector;

int sites_on_node;
site *lattice;
field_offset x1_off;
field_offset x2_off;
int i;
site *s;
half_wilson_vector *temp_x;

void init_vars() {
    size_t total_size = 64 * 1024 * 1024; // Aim for ~64MB of lattice data
    size_t site_size = sizeof(site);
    sites_on_node = total_size / site_size;
    if (sites_on_node == 0) sites_on_node = 1;

    lattice = (site *)calloc(sites_on_node, sizeof(site));
    temp_x = (half_wilson_vector *)calloc(sites_on_node, sizeof(half_wilson_vector));

    x1_off = offsetof(site, phi);
    x2_off = offsetof(site, resid);

    for (int idx = 0; idx < sites_on_node; idx++) {
        lattice[idx].phi.c[0].real = 1.0;
        lattice[idx].phi.c[0].imag = 0.0;
        lattice[idx].resid.c[0].real = 0.0;
        lattice[idx].resid.c[0].imag = 1.0;
    }

    s = lattice;
    i = 0;
}