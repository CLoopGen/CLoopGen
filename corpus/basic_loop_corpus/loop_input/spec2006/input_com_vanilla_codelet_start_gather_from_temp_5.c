#include <stdio.h>
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

int even_sites_on_node = 100000;
site *lattice;
int **neighbor;
void *field;
int size = 64;
int _usr_index = 0;
char **dest;
int j;
site *s;

void init_vars() {
    const int data_size = 8 * 1024 * 1024;
    field = aligned_alloc(64, data_size);
    memset(field, 0, data_size);

    lattice = calloc(even_sites_on_node, sizeof(site));
    if (!lattice) exit(1);

    neighbor = malloc(sizeof(int*));
    neighbor[0] = malloc(even_sites_on_node * sizeof(int));
    for (int i = 0; i < even_sites_on_node; i++) {
        neighbor[0][i] = i % (data_size / size);
    }

    dest = malloc(even_sites_on_node * sizeof(char*));
    if (!dest) exit(1);

    for (int i = 0; i < even_sites_on_node; i++) {
        site *s = &lattice[i];
        s->index = i;
        s->site_prn.ic_state = i;
        s->site_prn.scale = 1.0;
    }
}