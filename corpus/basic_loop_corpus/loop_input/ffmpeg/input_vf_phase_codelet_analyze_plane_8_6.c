#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

int ns = 1;
int os = 1;
uint8_t *nptr = NULL;
uint8_t *optr = NULL;
int w = TOTAL_ELEMENTS / 2;
int bdif = 0;
int tdif = 0;
int pdif = 0;
int t = 0;
uint8_t *rend = NULL;

static uint8_t nbuffer[TOTAL_ELEMENTS] __attribute__((aligned(32)));
static uint8_t obuffer[TOTAL_ELEMENTS] __attribute__((aligned(32)));

void init_vars() {
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        nbuffer[i] = (uint8_t)(rand() & 0xFF);
        obuffer[i] = (uint8_t)(rand() & 0xFF);
    }
    
    nptr = nbuffer + 1024;
    optr = obuffer + 1024;
    rend = nptr + w;
    
    bdif = 0;
    tdif = 0;
    pdif = 0;
    t = 0;
}