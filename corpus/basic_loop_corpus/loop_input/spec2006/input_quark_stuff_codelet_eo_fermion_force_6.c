#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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
field_offset x_off;
int i;
site *s;
su3_vector *temp_x;

void init_vars() {
    size_t data_size = 134217728; // ~128MB to target ~0.01 sec runtime
    size_t site_size = sizeof(site);
    sites_on_node = data_size / (sizeof(su3_vector) + site_size / 8);
    if (sites_on_node == 0) sites_on_node = 1;

    lattice = (site *)calloc(sites_on_node, sizeof(site));
    temp_x = (su3_vector *)calloc(sites_on_node, sizeof(su3_vector));

    x_off = (field_offset)offsetof(site, phi);

    for (int idx = 0; idx < sites_on_node; idx++) {
        site *s = &lattice[idx];
        for (int j = 0; j < 3; j++) {
            s->phi.c[j].real = 1.0;
            s->phi.c[j].imag = 0.0;
        }
    }

    i = 0;
    s = lattice;
}