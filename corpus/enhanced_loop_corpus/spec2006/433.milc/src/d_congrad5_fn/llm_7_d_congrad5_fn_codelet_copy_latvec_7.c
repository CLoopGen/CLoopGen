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
extern int even_sites_on_node;
extern site *lattice;
extern field_offset src;
extern field_offset dest;
extern int i;
extern site *s;
extern su3_vector *spt;
extern su3_vector *dpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = even_sites_on_node, s = &(lattice[i]); i < sites_on_node; i++, s++) {
        s = &(lattice[i]);
        spt = (su3_vector *)((char *)(s) + (src));
        dpt = (su3_vector *)((char *)(s) + (dest));
        dpt->c[0] = spt->c[0];
        dpt->c[1] = spt->c[1];
        dpt->c[2] = spt->c[2];
    }
}
