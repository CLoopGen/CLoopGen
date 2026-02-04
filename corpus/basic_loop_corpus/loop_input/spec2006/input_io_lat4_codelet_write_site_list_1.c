#include <stdio.h>
#include <stdlib.h>
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

typedef int int32type;

int nx = 8;
int ny = 8;
int nz = 8;
int sites_on_node = 512;
site *lattice = NULL;
int i;
int buf_length;
site *s;
int32type coords;
int32type *cbuf = NULL;

void init_vars() {
    lattice = (site*)calloc(sites_on_node, sizeof(site));
    cbuf = (int32type*)malloc(2048 * sizeof(int32type));

    for (int idx = 0; idx < sites_on_node; idx++) {
        lattice[idx].x = idx & 0x7;
        lattice[idx].y = (idx >> 3) & 0x7;
        lattice[idx].z = (idx >> 6) & 0x7;
        lattice[idx].t = (idx >> 9) & 0x7;
        lattice[idx].parity = (lattice[idx].x + lattice[idx].y + lattice[idx].z + lattice[idx].t) % 2;
        lattice[idx].index = idx;
    }

    buf_length = 0;
}