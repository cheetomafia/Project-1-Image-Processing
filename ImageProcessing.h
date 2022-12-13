#ifndef IMAGE_PROCESSING__
#define IMAGE_PROCESSING__

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>

using namespace std;
// Prototype your functions here


const int COPY = 0;
const int VERTICAL = 1;
const int HORIZONTAL = 2;
const int MEDIAN3 = 3;
const int MEDIAN9 = 4;
const int MEDIAN15 = 5;

/**
 * Copy Image
 *
 * @param data - array of PGM data from image
 * @param filename - name of file being copied
 * @return int**
 */
int** copyImage(string fileName, int** data);

/**
 * Flip Image about Horizontal Axis
 *
 * @param x - array of PGM data from image
 * 
 * @return in**
 */

int** flipVertical(string fileName, int** x);

/**
 * Flip Image about Vertical Axis
 *
 * @param x - array of PGM data from image
 * 
 * @return void
 */

int** flipHorizontal(string fileName, int** x);

/**
 * Apply Median Filter to noisy image
 *
 * @param filename - name of file being scanned
 * @param data - input array containing pgm
 * @param modified - output pgm array
 * @param height - height of input array
 * @param width - width of input array 
 * @param sz - size of filter applied
 * 
 * @return void
 */

int** medianFilter(string fileName, int** data, int** modified, int height, int width, int sz);

#endif
