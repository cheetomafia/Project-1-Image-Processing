#include "ImageProcessing.h"
#include "PGM.h"
#include "SelectionSort.h"
#include <iostream>

// Implement your functions here
void swapPixel(int &a, int &b) {// swaps the values of pixels
  int temp;
  temp = a;
  a = b;
  b = temp;
  return;
}

int **copyImage(string fileName, int **data) {// copies the data for the image
  int **copied = data;

  return copied;
}

int **flipVertical(string fileName, int **data) {
  // take in data
  // flip it
  // :)
  // uses the swapPixel function to flip the image vertically
  int width = getPGMWidth();
  int height = getPGMHeight();

  for (int j = 0; j < width; j++) {
    for (int i = 0; i < height / 2; i++) {
      swapPixel(data[i][j], data[height - 1 - i][j]);
      
    }
  }

  return data;
}

int **flipHorizontal(string fileName, int **data) {
  // take in data
  // flip it horizontal
  // :)
  // uses the swapPixel function to flip the image horizontal
  int width = getPGMWidth();
  int height = getPGMHeight();

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      swapPixel(data[i][j], data[i][width - 1 - j]);
    }
  }

  return data;
}

//void medianFilter(string fileName, int **data, int**modified, int sz) {
int** medianFilter(string fileName, int** data, int** modified, int height, int width, int sz){
  // code making the filter

  modified = data;
  int window_size;
  // switch case probably
  switch(sz){
    case MEDIAN3:
      //3x3 filter
      window_size = 3; 
    break;
    case MEDIAN9:
      //9x9 filter here
      window_size = 9;
    break;
    case MEDIAN15:
      //15x15 filter here
      window_size = 15;
    break; 
    default:
      cout << "Error in medianFilter" << endl;
    break;
    }
  // or maybe the filter code is in the switch case :)
  int array[height][width];// creates the array that the data is being put into
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      array[y][x] = data[y][x];
    }
  }
  int window[window_size*window_size];
  int edgex = window_size / 2; // half window width
  int edgey = window_size / 2; // half window height
  
   for (int x = edgex; x < width - edgex; x++) {
    for (int y = edgey; y < height - edgey; y++) {
      int i = 0;
      for (int fx = 0; fx < window_size; fx++) {
        for (int fy = 0; fy < window_size; fy++) {
          window[i] = array[y + fy - edgey][x + fx - edgex];
          // puts data from array into a window to be sorted
          i++;
        }
      }
      selectionSort(window, window_size*window_size, descending); //sorts
      modified[y][x] = window[(window_size * window_size)  / 2];
      //puts data into picture
    }
  }

  return modified;
} 
