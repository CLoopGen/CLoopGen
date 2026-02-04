#include <stdio.h>
#include <stdlib.h>
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

int sites_on_node = 65536;
int even_sites_on_node = 32768;
site *lattice;
int **neighbor;
void *field;
int size = 128;
int _usr_index = 0;
char **dest;
int j;
site *s;

void init_vars() {
    const int total_sites = sites_on_node;
    const int data_size = 65536 * 128; // ~8MB of field data

    lattice = (site*)calloc(total_sites, sizeof(site));
    if (!lattice) exit(1);

    field = malloc(data_size);
    if (!field) exit(1);

    dest = (char**)malloc(total_sites * sizeof(char*));
    if (!dest) exit(1);

    neighbor = (int**)malloc(sizeof(int*));
    if (!neighbor) exit(1);
    neighbor[0] = (int*)malloc(total_sites * sizeof(int));
    if (!neighbor[0]) exit(1);

    for (int i = 0; i < total_sites; i++) {
        neighbor[0][i] = i % (data_size / size);
    }

    for (int i = 0; i < total_sites; i++) {
        site *s = &lattice[i];
        s->index = i;
        s->parity = (i % 2) ? 1 : 0;
        s->site_prn.ic_state = i;
        s->site_prn.scale = 1.0;
        s->space1 = 0;
        s->phase[0] = s->phase[1] = s->phase[2] = s->phase[3] = 1.0;
    }
}