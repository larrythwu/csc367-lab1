// ------------
// This code is provided solely for the personal and private use of
// students taking the CSC367H5 course at the University of Toronto.
// Copying for purposes other than this use is expressly prohibited.
// All forms of distribution of this code, whether as given or with
// any changes, are expressly prohibited.
//
// Authors: Bogdan Simion, Alexey Khrabrov
//
// All of the files in this directory and all subdirectories are:
// Copyright (c) 2022 Bogdan Simion
// -------------
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "time_util.h"

#define NVECS 10000
#define NDIMS 10000

static double ranf(void)
{
	return (double)random() / RAND_MAX;
}

void generate(double m[NDIMS][NVECS])
{
	srandom(42);
	for (int i = 0; i < NDIMS; i++) {
		for (int j = 0; j < NVECS; j++) {
			m[i][j] = ranf();
		}
	}
}


double avg_vec_len(const double m[NDIMS][NVECS])
{
	double len_sum = 0.0;

	for (int i = 0; i < NVECS; i++) {
		double s = 0.0;
		for (int j = 0; j < NDIMS; j++) {
			s += m[j][i] * m[j][i];
		}

		double len = sqrt(s);
		len_sum += len;
	}

	return len_sum / NVECS;
}


double matrix[NDIMS][NVECS];

int main()
{
	generate(matrix);

	double time_msec = 0.0;
	//clock in 
    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    double avg_len = avg_vec_len(matrix);
    //clock out
    clock_gettime(CLOCK_MONOTONIC, &stop);
    //time_msec = ( stop.tv_sec - start.tv_sec ) + ( stop.tv_nsec - start.tv_nsec ) / BILLION;
	double start_time = timespec_to_msec(start);
    double end_time = timespec_to_msec(stop);
    time_msec = end_time-start_time;
    printf("%f\n", avg_len);
    printf("%f\n", time_msec);
	return 0;
}
