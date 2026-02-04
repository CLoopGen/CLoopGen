#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

typedef int field_offset;

int sites_on_node = 131072;
int even_sites_on_node = 65536;
site *lattice;
int **neighbor;
field_offset field = 1024;
int _usr_index = 0;
char **dest;
int j;
site *s;

void init_vars() {
    const size_t site_size = sizeof(site);
    const size_t total_site_bytes = sites_on_node * site_size;
    
    lattice = (site*)calloc(sites_on_node, sizeof(site));
    if (!lattice) exit(1);

    dest = (char**)malloc(sites_on_node * sizeof(char*));
    if (!dest) exit(1);

    neighbor = (int**)malloc(sizeof(int*));
    if (!neighbor) exit(1);
    neighbor[0] = (int*)malloc(sites_on_node * sizeof(int));
    if (!neighbor[0]) exit(1);

    for (int i = 0; i < sites_on_node; i++) {
        neighbor[0][i] = i;
    }

    for (int i = 0; i < sites_on_node; i++) {
        dest[i] = (char*)calloc(1, 2048);
        if (!dest[i]) exit(1);
    }
}