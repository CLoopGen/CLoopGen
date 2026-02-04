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

int sites_on_node;
site *lattice;
field_offset src;
field_offset dest;
int i;
site *s;
su3_vector *spt;
su3_vector *dpt;

void init_vars() {
    size_t total_size = 131072; // ~128KB per site * 1024 sites ≈ 131MB, adjust for ~0.01 sec runtime
    sites_on_node = 1024;
    lattice = (site*)calloc(sites_on_node, sizeof(site));
    if (!lattice) exit(1);

    src = (char*)&(((site*)0)->phi) - (char*)0;
    dest = (char*)&(((site*)0)->resid) - (char*)0;

    s = NULL;
    spt = NULL;
    dpt = NULL;
    i = 0;
}