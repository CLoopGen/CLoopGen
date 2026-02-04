#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

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
char **gen_pt[16];
su3_vector *dest;
site *s;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec runtime
    const size_t elem_size = sizeof(su3_vector);
    sites_on_node = data_size / elem_size;

    lattice = (site*)calloc(sites_on_node, sizeof(site));
    dest = (su3_vector*)malloc(sites_on_node * sizeof(su3_vector));

    for (int pt_idx = 0; pt_idx < 16; pt_idx++) {
        gen_pt[pt_idx] = (char**)malloc(sites_on_node * sizeof(char*));
        for (int j = 0; j < sites_on_node; j++) {
            gen_pt[pt_idx][j] = (char*)malloc(sizeof(su3_vector));
            su3_vector* vec = (su3_vector*)gen_pt[pt_idx][j];
            for (int c = 0; c < 3; c++) {
                vec->c[c].real = 0.1 * (pt_idx + 1) * (j + 1) + c;
                vec->c[c].imag = 0.2 * (pt_idx + 1) * (j + 1) - c;
            }
        }
    }

    s = lattice;
    i = 0;

    for (int idx = 0; idx < sites_on_node; idx++) {
        site* curr_site = &lattice[idx];
        curr_site->index = idx;
        curr_site->parity = idx % 2;
        curr_site->x = idx;
        curr_site->y = idx >> 4;
        curr_site->z = idx >> 8;
        curr_site->t = idx >> 12;
        curr_site->site_prn.ic_state = idx;
        curr_site->site_prn.scale = 1.0;
        curr_site->space1 = 0;
        for (int d = 0; d < 4; d++) {
            memset(&curr_site->link[d], 0, sizeof(su3_matrix));
            memset(&curr_site->mom[d], 0, sizeof(anti_hermitmat));
            curr_site->phase[d] = 1.0;
        }
        memset(&curr_site->phi, 0, sizeof(su3_vector));
        memset(&curr_site->resid, 0, sizeof(su3_vector));
        memset(&curr_site->cg_p, 0, sizeof(su3_vector));
        memset(&curr_site->xxx, 0, sizeof(su3_vector));
        memset(&curr_site->ttt, 0, sizeof(su3_vector));
        memset(&curr_site->g_rand, 0, sizeof(su3_vector));
        for (int tv = 0; tv < 4; tv++) {
            memset(&curr_site->tempvec[tv], 0, sizeof(su3_vector));
            memset(&curr_site->templongvec[tv], 0, sizeof(su3_vector));
        }
        memset(&curr_site->templongv1, 0, sizeof(su3_vector));
        memset(&curr_site->tempmat1, 0, sizeof(su3_matrix));
        memset(&curr_site->staple, 0, sizeof(su3_matrix));
    }
}