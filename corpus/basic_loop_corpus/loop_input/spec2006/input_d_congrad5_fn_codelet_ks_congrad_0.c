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

typedef int field_offset;

int sites_on_node;
site *lattice;
su3_vector *t_dest;
field_offset dest;
int i;
site *s;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB of lattice data
    const size_t site_size = sizeof(site);
    sites_on_node = data_size / site_size;
    
    // Ensure at least one site
    if (sites_on_node == 0) sites_on_node = 1;

    // Allocate lattice
    lattice = (site*)calloc(sites_on_node, sizeof(site));
    if (!lattice) {
        fprintf(stderr, "Failed to allocate lattice\n");
        exit(1);
    }

    // Allocate t_dest
    t_dest = (su3_vector*)calloc(sites_on_node, sizeof(su3_vector));
    if (!t_dest) {
        fprintf(stderr, "Failed to allocate t_dest\n");
        exit(1);
    }

    // Initialize dest to point to the 'phi' field in site
    dest = (char*)&(((site*)0)->phi) - (char*)0;

    // Initialize lattice with dummy values
    for (int idx = 0; idx < sites_on_node; idx++) {
        site* s = &lattice[idx];
        s->x = idx % 2 ? 1 : -1;
        s->y = idx % 3 ? 1 : -1;
        s->z = idx % 5 ? 1 : -1;
        s->t = idx % 7 ? 1 : -1;
        s->parity = (idx % 2);
        s->index = idx;
        s->space1 = 0;
        s->site_prn.ic_state = idx + 12345UL;
        s->site_prn.scale = 1.0;
        
        // Initialize phi vectors
        for (int c = 0; c < 3; c++) {
            s->phi.c[c].real = 0.1 * (idx + c);
            s->phi.c[c].imag = 0.2 * (idx + c);
        }
        
        // Initialize other fields as needed
        for (int j = 0; j < 4; j++) {
            s->phase[j] = 0.5;
            for (int c = 0; c < 3; c++) {
                s->tempvec[j].c[c].real = 1.0;
                s->tempvec[j].c[c].imag = 0.0;
            }
        }
    }

    // Initialize global loop variables
    i = 0;
    s = lattice;
}