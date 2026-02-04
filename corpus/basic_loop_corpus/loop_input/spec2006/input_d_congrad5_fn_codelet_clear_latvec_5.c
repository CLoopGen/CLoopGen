#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
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
field_offset v;
int i;
int j;
site *s;
su3_vector *vv;

void init_vars() {
    size_t total_size = 64 * 1024 * 1024; // Aim for ~64 MB
    size_t site_size = sizeof(site);
    sites_on_node = total_size / site_size;
    if (sites_on_node == 0) sites_on_node = 1;

    lattice = (site *)calloc(sites_on_node, sizeof(site));
    if (!lattice) {
        sites_on_node = 0;
        return;
    }

    v = (field_offset)offsetof(site, phi);

    for (i = 0; i < sites_on_node; i++) {
        site *s = &lattice[i];
        for (int mu = 0; mu < 4; mu++) {
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    s->link[mu].e[a][b].real = 0.0;
                    s->link[mu].e[a][b].imag = 0.0;
                }
            }
        }
        for (int mu = 0; mu < 4; mu++) {
            s->mom[mu].m01.real = 0.0; s->mom[mu].m01.imag = 0.0;
            s->mom[mu].m02.real = 0.0; s->mom[mu].m02.imag = 0.0;
            s->mom[mu].m12.real = 0.0; s->mom[mu].m12.imag = 0.0;
            s->mom[mu].m00im = 0.0;
            s->mom[mu].m11im = 0.0;
            s->mom[mu].m22im = 0.0;
        }
        for (int mu = 0; mu < 4; mu++) {
            s->phase[mu] = 1.0;
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
            for (int mu = 0; mu < 4; mu++) {
                s->tempvec[mu].c[c].real = 0.0;
                s->tempvec[mu].c[c].imag = 0.0;
                s->templongvec[mu].c[c].real = 0.0;
                s->templongvec[mu].c[c].imag = 0.0;
            }
            s->templongv1.c[c].real = 0.0;
            s->templongv1.c[c].imag = 0.0;
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
}