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

int even_sites_on_node = 100000;
site *lattice;
int **neighbor;
field_offset field = sizeof(site) / 2; 
int _usr_index = 0;
char **dest;
int j;
site *s;

void init_vars() {
    const int nodes = 4;
    const int sites_per_node = 256 * 1024; // ~256KB per node, total lattice ~1MB
    const int total_sites = nodes * sites_per_node;

    lattice = (site*)calloc(total_sites, sizeof(site));
    if (!lattice) exit(1);

    neighbor = (int**)malloc(sizeof(int*) * nodes);
    if (!neighbor) exit(1);
    for (int n = 0; n < nodes; n++) {
        neighbor[n] = (int*)malloc(sizeof(int) * even_sites_on_node);
        if (!neighbor[n]) exit(1);
        for (int j = 0; j < even_sites_on_node; j++) {
            neighbor[n][j] = (n + 1) % nodes * sites_per_node + (j % sites_per_node);
        }
    }

    dest = (char**)malloc(sizeof(char*) * even_sites_on_node);
    if (!dest) exit(1);
    memset(dest, 0, sizeof(char*) * even_sites_on_node);

    _usr_index = 0;
}