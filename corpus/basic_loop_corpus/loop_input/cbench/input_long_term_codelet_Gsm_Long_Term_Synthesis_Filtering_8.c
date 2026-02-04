#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef short word;
typedef long longword;
typedef unsigned long ulongword;

word *erp;
word *drp;
longword ltmp;
int k;
word brp;
word drpp;
word Nr;

#define DATA_SIZE (1 << 20)  // 1MB of data: adjust as needed

void init_vars() {
    Nr = 10;  // chosen so that k - Nr >= 0 when k starts from 0 and we access drp[k - Nr]
    
    // Allocate memory for erp and drp with padding to avoid out-of-bounds access
    // Since loop runs from k=0 to k=39, and accesses drp[k - Nr], we need at least 39 - Nr + 1 elements
    // So we require index up to 39 and down to -Nr -> allocate 40 + Nr elements, offset pointer
    int base_offset = Nr;
    int total_size = 40 + base_offset;  // indices from -Nr to 39 -> size 39 + Nr + 1

    erp = (word*)calloc(total_size, sizeof(word));
    drp = (word*)calloc(total_size, sizeof(word));

    // Initialize brp to a non-zero value for meaningful computation
    brp = 15000;

    // Initialize ltmp
    ltmp = 0;

    // Seed and initialize arrays with some values to simulate real data
    srand(time(NULL));
    for (int i = 0; i < total_size; i++) {
        erp[i] = (word)(rand() % 65536 - 32768);
        drp[i] = (word)(rand() % 65536 - 32768);
    }
}