#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

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

int even_sites_on_node = 100000;
site *lattice = NULL;
su3_vector *t_dest = NULL;
field_offset dest;
int i;
site *s;
int l_parity = 1;
int loopend;

void init_vars() {
    const size_t num_sites = 200000;
    lattice = (site*)calloc(num_sites, sizeof(site));
    t_dest = (su3_vector*)calloc(num_sites, sizeof(su3_vector));

    if (!lattice || !t_dest) {
        exit(1);
    }

    even_sites_on_node = num_sites / 2;
    loopend = num_sites;
    l_parity = 1;
    i = (l_parity == 1 ? even_sites_on_node : 0);

    dest = (field_offset)offsetof(site, phi);

    for (size_t idx = 0; idx < num_sites; ++idx) {
        t_dest[idx].c[0].real = 1.0;
        t_dest[idx].c[0].imag = 0.0;
        t_dest[idx].c[1].real = 0.0;
        t_dest[idx].c[1].imag = 1.0;
        t_dest[idx].c[2].real = 0.5;
        t_dest[idx].c[2].imag = 0.5;
    }
}