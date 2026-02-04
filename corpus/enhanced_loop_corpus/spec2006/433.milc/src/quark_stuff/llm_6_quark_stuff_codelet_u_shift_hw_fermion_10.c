#include <stdio.h>

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

typedef struct {
    su3_vector h[2];
} half_wilson_vector;

extern int sites_on_node;
extern site *lattice;
extern char **gen_pt[16];
extern half_wilson_vector *dest;
extern site *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    half_wilson_vector *temp_dest = dest;
    site *local_lat = lattice;
    char **gen_ptr = gen_pt[0];
    int idx;
    for (i = 0, s = local_lat; i < sites_on_node; i++, s++) {
        idx = i;
        temp_dest[idx] = *(half_wilson_vector *)(gen_ptr[idx]);
    }
}
