#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ChannelStatistics {
    size_t depth;
    double area;
    double minima;
    double maxima;
    double sum;
    double sum_squared;
    double sum_cubed;
    double sum_fourth_power;
    double mean;
    double variance;
    double standard_deviation;
    double kurtosis;
    double skewness;
    double entropy;
    double median;
    long double sumLD;
    long double M1;
    long double M2;
    long double M3;
    long double M4;
} ChannelStatistics;

extern ChannelStatistics *channel_statistics;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= (ssize_t)32; i += 2) {
    ChannelStatistics *cs = channel_statistics + i;
    cs->area = 0.;
    cs->depth = 1;
    cs->maxima = (-1.7976931348623157E+308);
    cs->minima = 1.7976931348623157E+308;
    cs->sum = 0.;
    cs->sumLD = 0.;
    cs->mean = 0.;
    cs->standard_deviation = 0.;
    cs->variance = 0.;
    cs->skewness = 0.;
    cs->kurtosis = 0.;
    cs->entropy = 0.;
}
}
