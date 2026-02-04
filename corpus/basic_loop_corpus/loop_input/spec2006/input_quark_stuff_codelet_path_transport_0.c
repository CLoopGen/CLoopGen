#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
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

int sites_on_node = 100000;
int even_sites_on_node = 50000;
site *lattice = NULL;
field_offset dest;
int parity = 1;
int i;
site *s;
su3_vector *tmp_src = NULL;

void init_vars() {
    lattice = (site*)calloc(sites_on_node, sizeof(site));
    if (!lattice) exit(1);

    tmp_src = (su3_vector*)malloc(sites_on_node * sizeof(su3_vector));
    if (!tmp_src) exit(1);

    for (int j = 0; j < sites_on_node; j++) {
        tmp_src[j].c[0].real = 1.0;
        tmp_src[j].c[0].imag = 0.0;
        tmp_src[j].c[1].real = 0.0;
        tmp_src[j].c[1].imag = 1.0;
        tmp_src[j].c[2].real = -1.0;
        tmp_src[j].c[2].imag = -1.0;
    }

    dest = (field_offset)offsetof(site, phi);
}