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

int sites_on_node = 1 << 20; // ~1M sites to target ~0.01 sec runtime
site *lattice;
int **neighbor;
void *field;
int size = sizeof(site);
int _usr_index = 0;
char **dest;
int j;
site *s;

void init_vars() {
    const int num_neighbors = 4;

    // Allocate lattice
    lattice = (site*)calloc(sites_on_node, sizeof(site));
    if (!lattice) exit(1);

    // Allocate field with same size as lattice for memory access bounds
    field = malloc(sites_on_node * size);
    if (!field) exit(1);

    // Initialize neighbor array: each site has a fixed neighbor mapping within valid range
    neighbor = (int**)malloc(sizeof(int*) * num_neighbors);
    if (!neighbor) exit(1);
    for (int i = 0; i < num_neighbors; i++) {
        neighbor[i] = (int*)malloc(sites_on_node * sizeof(int));
        if (!neighbor[i]) exit(1);
        for (int j = 0; j < sites_on_node; j++) {
            neighbor[i][j] = j; // map to valid index in [0, sites_on_node)
        }
    }

    // Allocate dest array of char pointers
    dest = (char**)malloc(sites_on_node * sizeof(char*));
    if (!dest) exit(1);
    for (int j = 0; j < sites_on_node; j++) {
        dest[j] = NULL;
    }

    // Initialize site_prn fields in lattice to avoid uninitialized reads
    for (int i = 0; i < sites_on_node; i++) {
        lattice[i].site_prn.r0 = 1UL;
        lattice[i].site_prn.r1 = 2UL;
        lattice[i].site_prn.r2 = 3UL;
        lattice[i].site_prn.r3 = 4UL;
        lattice[i].site_prn.r4 = 5UL;
        lattice[i].site_prn.r5 = 6UL;
        lattice[i].site_prn.r6 = 7UL;
        lattice[i].site_prn.multiplier = 8UL;
        lattice[i].site_prn.addend = 9UL;
        lattice[i].site_prn.ic_state = 10UL;
        lattice[i].site_prn.scale = 1.0;
    }
}