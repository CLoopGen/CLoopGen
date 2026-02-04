#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char Alphabet[25] = {
    'A', 'C', 'G', 'T', 'R', 'Y', 'M', 'K', 'S', 'W',
    'B', 'D', 'H', 'V', 'N', 'Z', 'X', 'P', 'Q', 'U',
    'E', 'F', 'L', 'I', 'J'
};

static char dsq_data[134217728]; // ~128MB
char *dsq = dsq_data;

static char seq_data[134217728]; // ~128MB
char *seq = seq_data;

int L = 134217727; // Ensure dsq[i + 1] is valid for i = 0 to L-1
int i;

void init_vars() {
    // Initialize dsq with valid indices into Alphabet (0-24)
    for (int j = 0; j < 134217728; j++) {
        dsq[j] = rand() % 25;
    }
    // Zero out seq for clean state
    memset(seq, 0, 134217728);
}