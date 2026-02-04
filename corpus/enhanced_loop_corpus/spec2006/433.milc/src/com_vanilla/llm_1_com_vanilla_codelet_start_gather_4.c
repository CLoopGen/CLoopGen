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

typedef int field_offset;

extern int sites_on_node;
extern site *lattice;
extern int **neighbor;
extern field_offset field;
extern int _usr_index;
extern char **dest;
extern int j;
extern site *s;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop() {
    int j_inner, j_outer;
    site *s;
    const int unroll_factor = 2;
    int remainder = sites_on_node % unroll_factor;
    s = lattice;

    for (j_outer = 0; j_outer < sites_on_node / unroll_factor; j_outer++) {
        for (j_inner = 0; j_inner < unroll_factor; j_inner++) {
            int idx = j_outer * unroll_factor + j_inner;
            dest[idx] = ((char *)(lattice + neighbor[index][idx])) + field;
            s++;
        }
    }

    for (j = sites_on_node - remainder; j < sites_on_node; j++, s++) {
        dest[j] = ((char *)(lattice + neighbor[index][j])) + field;
    }
}
