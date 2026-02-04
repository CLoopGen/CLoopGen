#include <stdio.h>
#include <inttypes.h>

double m_rgQp[21];
double m_rgRp[21];
double Pm_rgQp[20];
double Pm_rgRp[20];
int i;

void init_vars() {
    for (int j = 0; j < 20; j++) {
        Pm_rgQp[j] = (double)(j * 3.14);
        Pm_rgRp[j] = (double)(j * 2.71);
    }
    m_rgQp[0] = 0.0;
    m_rgRp[0] = 0.0;
}