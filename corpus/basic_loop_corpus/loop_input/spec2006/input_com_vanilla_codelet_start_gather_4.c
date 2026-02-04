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

int sites_on_node = 100000;
site *lattice;
int **neighbor;
field_offset field = sizeof(site) / 2; 
int _usr_index = 0;
char **dest;
int j;
site *s;

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // Target ~128MB
    sites_on_node = total_size / sizeof(site);
    if (sites_on_node < 1) sites_on_node = 1;

    lattice = (site*)calloc(sites_on_node, sizeof(site));
    if (!lattice) exit(1);

    dest = (char**)calloc(sites_on_node, sizeof(char*));
    if (!dest) exit(1);

    neighbor = (int**)calloc(1, sizeof(int*));
    if (!neighbor) exit(1);
    neighbor[0] = (int*)calloc(sites_on_node, sizeof(int));
    if (!neighbor[0]) exit(1);

    for (int i = 0; i < sites_on_node; i++) {
        neighbor[0][i] = i % sites_on_node;
    }

    _usr_index = 0;
    field = sizeof(site) - sizeof(su3_matrix)*4 - sizeof(anti_hermitmat)*4 - sizeof(double)*4 - 64;
    if (field < 0) field = 0;
    field = field & ~7; // align to 8 bytes

    for (int i = 0; i < sites_on_node; i++) {
        site* s = &lattice[i];
        s->index = i;
        s->parity = i % 2;
        s->x = i;
        s->y = i >> 4;
        s->z = i >> 8;
        s->t = i >> 12;
        s->site_prn.ic_state = i;
        s->site_prn.scale = 1.0;
        s->phase[0] = 1.0; s->phase[1] = 1.0; s->phase[2] = 1.0; s->phase[3] = 1.0;
    }
}