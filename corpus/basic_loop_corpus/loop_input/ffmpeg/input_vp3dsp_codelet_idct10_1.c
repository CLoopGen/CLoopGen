#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *ip;
int A;
int B;
int C;
int D;
int Ad;
int Bd;
int Cd;
int Dd;
int E;
int F;
int G;
int H;
int Ed;
int Gd;
int Add;
int Bdd;
int Fd;
int Hd;
int i;

static int16_t *ip_base;
static size_t total_elements = 262144; // 262144 * sizeof(int16_t) = 512KB, safe for 8-stride access

void init_vars() {
    ip_base = calloc(total_elements, sizeof(int16_t));
    if (!ip_base) {
        exit(1);
    }
    ip = ip_base;

    A = 1;
    B = 2;
    C = 3;
    D = 4;
    Ad = 5;
    Bd = 6;
    E = 7;
    F = 0;
    G = 8;
    H = 9;
    Cd = 0;
    Dd = 0;
    Ed = 0;
    Gd = 0;
    Add = 0;
    Bdd = 0;
    Fd = 0;
    Hd = 0;
    i = 0;
}