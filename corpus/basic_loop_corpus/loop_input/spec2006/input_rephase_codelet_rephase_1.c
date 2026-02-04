#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

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

int sites_on_node;
site *lattice;
int i;
int j;
int k;
int dir;
site *s;

void init_vars() {
    const int target_size = 100 * 1024 * 1024; // Aim for ~100MB of lattice data
    const int bytes_per_site = sizeof(site);
    sites_on_node = target_size / bytes_per_site;
    if (sites_on_node == 0) sites_on_node = 1;

    lattice = (site*)calloc(sites_on_node, sizeof(site));
    if (!lattice) {
        fprintf(stderr, "Failed to allocate lattice\n");
        exit(1);
    }

    for (int idx = 0; idx < sites_on_node; idx++) {
        site* s = &lattice[idx];
        s->x = idx; s->y = idx+1; s->z = idx+2; s->t = idx+3;
        s->parity = (idx % 2);
        s->index = idx;

        s->site_prn.r0 = 1UL + idx;
        s->site_prn.r1 = 2UL + idx;
        s->site_prn.r2 = 3UL + idx;
        s->site_prn.r3 = 4UL + idx;
        s->site_prn.r4 = 5UL + idx;
        s->site_prn.r5 = 6UL + idx;
        s->site_prn.r6 = 7UL + idx;
        s->site_prn.multiplier = 8UL + idx;
        s->site_prn.addend = 9UL + idx;
        s->site_prn.ic_state = 10UL + idx;
        s->site_prn.scale = 1.0 + idx * 0.1;

        s->space1 = idx * 2;

        for (int d = 0; d < 4; d++) {
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    s->link[d].e[a][b].real = 1.0 + a * 3 + b + idx * 0.001;
                    s->link[d].e[a][b].imag = 0.5 + a * 3 + b + idx * 0.001;
                }
            }
            s->mom[d].m01.real = 0.1; s->mom[d].m01.imag = 0.2;
            s->mom[d].m02.real = 0.3; s->mom[d].m02.imag = 0.4;
            s->mom[d].m12.real = 0.5; s->mom[d].m12.imag = 0.6;
            s->mom[d].m00im = 0.1;
            s->mom[d].m11im = 0.2;
            s->mom[d].m22im = 0.3;
            s->mom[d].space = 0.0;
            s->phase[d] = 1.0 + d * 0.1;
        }

        for (int c = 0; c < 3; c++) {
            s->phi.c[c].real = 1.0 + c;
            s->phi.c[c].imag = 0.5 + c;
            s->resid.c[c].real = 2.0 + c;
            s->resid.c[c].imag = 1.5 + c;
            s->cg_p.c[c].real = 3.0 + c;
            s->cg_p.c[c].imag = 2.5 + c;
            s->xxx.c[c].real = 4.0 + c;
            s->xxx.c[c].imag = 3.5 + c;
            s->ttt.c[c].real = 5.0 + c;
            s->ttt.c[c].imag = 4.5 + c;
            s->g_rand.c[c].real = 6.0 + c;
            s->g_rand.c[c].imag = 5.5 + c;
            s->templongv1.c[c].real = 7.0 + c;
            s->templongv1.c[c].imag = 6.5 + c;
            for (int t = 0; t < 4; t++) {
                s->tempvec[t].c[c].real = 1.0 + t + c * 0.1;
                s->tempvec[t].c[c].imag = 0.5 + t + c * 0.1;
                s->templongvec[t].c[c].real = 2.0 + t + c * 0.1;
                s->templongvec[t].c[c].imag = 1.5 + t + c * 0.1;
            }
        }

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                s->tempmat1.e[a][b].real = 1.0 + a * 3 + b;
                s->tempmat1.e[a][b].imag = 0.5 + a * 3 + b;
                s->staple.e[a][b].real = 2.0 + a * 3 + b;
                s->staple.e[a][b].imag = 1.5 + a * 3 + b;
            }
        }
    }

    i = 0;
    j = 0;
    k = 0;
    dir = 0;
    s = NULL;
}