#include <stdio.h>
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

int nt = 8;
int sites_on_node = 65536;
site *lattice;
site *sit;
int i;

void init_vars() {
    lattice = (site*)calloc(sites_on_node, sizeof(site));
    if (!lattice) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < sites_on_node; idx++) {
        site* s = &lattice[idx];
        s->x = idx % 16;
        s->y = (idx / 16) % 16;
        s->z = (idx / 256) % 16;
        s->t = (idx / 4096) % nt;
        s->parity = (s->x + s->y + s->z + s->t) % 2;
        s->index = idx;

        s->site_prn.r0 = idx;
        s->site_prn.r1 = idx + 1;
        s->site_prn.r2 = idx + 2;
        s->site_prn.r3 = idx + 3;
        s->site_prn.r4 = idx + 4;
        s->site_prn.r5 = idx + 5;
        s->site_prn.r6 = idx + 6;
        s->site_prn.multiplier = 0x5DEECE66DUL;
        s->site_prn.addend = 0xBUL;
        s->site_prn.ic_state = idx;
        s->site_prn.scale = 1.0;

        s->space1 = 0;

        for (int j = 0; j < 4; j++) {
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    s->link[j].e[a][b].real = 0.0;
                    s->link[j].e[a][b].imag = 0.0;
                }
            }
            s->mom[j].m01.real = 0.0;
            s->mom[j].m01.imag = 0.0;
            s->mom[j].m02.real = 0.0;
            s->mom[j].m02.imag = 0.0;
            s->mom[j].m12.real = 0.0;
            s->mom[j].m12.imag = 0.0;
            s->mom[j].m00im = 0.0;
            s->mom[j].m11im = 0.0;
            s->mom[j].m22im = 0.0;
            s->mom[j].space = 0.0;
        }

        for (int j = 0; j < 4; j++) {
            s->phase[j] = 1.0;
        }

        for (int c = 0; c < 3; c++) {
            s->phi.c[c].real = 0.0;
            s->phi.c[c].imag = 0.0;
            s->resid.c[c].real = 0.0;
            s->resid.c[c].imag = 0.0;
            s->cg_p.c[c].real = 0.0;
            s->cg_p.c[c].imag = 0.0;
            s->xxx.c[c].real = 0.0;
            s->xxx.c[c].imag = 0.0;
            s->ttt.c[c].real = 0.0;
            s->ttt.c[c].imag = 0.0;
            s->g_rand.c[c].real = 0.0;
            s->g_rand.c[c].imag = 0.0;
            s->templongv1.c[c].real = 0.0;
            s->templongv1.c[c].imag = 0.0;
        }

        for (int j = 0; j < 4; j++) {
            for (int c = 0; c < 3; c++) {
                s->tempvec[j].c[c].real = 0.0;
                s->tempvec[j].c[c].imag = 0.0;
                s->templongvec[j].c[c].real = 0.0;
                s->templongvec[j].c[c].imag = 0.0;
            }
        }

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                s->tempmat1.e[a][b].real = 0.0;
                s->tempmat1.e[a][b].imag = 0.0;
                s->staple.e[a][b].real = 0.0;
                s->staple.e[a][b].imag = 0.0;
            }
        }
    }

    sit = lattice;
}