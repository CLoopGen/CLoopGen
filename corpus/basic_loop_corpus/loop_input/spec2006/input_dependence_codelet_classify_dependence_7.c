#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subscript {
    int position;
    int coefficient;
    int offset;
    const char *variable;
    struct subscript *next;
} subscript;

subscript icoefficients[13];
subscript ocoefficients[13];
int count;
char *iiv_used[13];
char *oiv_used[13];
int ocoeff[13];
int icoeff[13];
int idx;

void init_vars() {
    count = 12;
    for (int i = 0; i <= count; i++) {
        icoeff[i] = 0;
        ocoeff[i] = 0;
        iiv_used[i] = NULL;
        oiv_used[i] = NULL;
        icoefficients[i].position = i;
        icoefficients[i].coefficient = (i % 5) + 1;
        icoefficients[i].offset = i * 10;
        if (i % 3 == 0) {
            char *ivar_name = (char*)malloc(32);
            snprintf(ivar_name, 32, "ivar_%d", i);
            icoefficients[i].variable = ivar_name;
            icoefficients[i].next = &icoefficients[(i+1) % 13];
        } else {
            icoefficients[i].variable = NULL;
            icoefficients[i].next = NULL;
        }

        ocoefficients[i].position = i;
        ocoefficients[i].coefficient = (i % 7) + 1;
        ocoefficients[i].offset = i * 20;
        if (i % 4 == 0) {
            char *ovar_name = (char*)malloc(32);
            snprintf(ovar_name, 32, "ovar_%d", i);
            ocoefficients[i].variable = ovar_name;
            ocoefficients[i].next = &ocoefficients[(i+1) % 13];
        } else {
            ocoefficients[i].variable = NULL;
            ocoefficients[i].next = NULL;
        }
    }
}