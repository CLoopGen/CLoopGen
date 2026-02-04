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

typedef struct {
    su3_vector h[2];
} half_wilson_vector;

int sites_on_node = 100000;

site *lattice;

char **gen_pt[16];

half_wilson_vector *dest;

site *s;
int i;

void init_vars() {
    lattice = (site*)calloc(sites_on_node, sizeof(site));
    dest = (half_wilson_vector*)calloc(sites_on_node, sizeof(half_wilson_vector));

    for (int p = 0; p < 16; p++) {
        gen_pt[p] = (char**)malloc(sites_on_node * sizeof(char*));
        for (int j = 0; j < sites_on_node; j++) {
            gen_pt[p][j] = (char*)malloc(sizeof(half_wilson_vector));
            for (int k = 0; k < sizeof(half_wilson_vector); k++) {
                gen_pt[p][j][k] = (char)(k % 256);
            }
        }
    }

    s = lattice;
    i = 0;
}