#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int md5uint;

typedef md5uint md5sig[4];

typedef struct {
    unsigned int l : 20;
    unsigned int hash_info : 3;
    unsigned int timelimit_impatience : 9;
    unsigned int u : 20;
    unsigned int slvndx : 12;
} flags_t;

struct solution_s {
    md5sig s;
    flags_t flags;
};

typedef struct solution_s solution;

unsigned int nsiz = 65536;
unsigned int h;
solution *nsol;

void init_vars() {
    nsol = (solution *)calloc(nsiz, sizeof(solution));
    if (!nsol) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}