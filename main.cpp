#include "PGM.h"
#include "ImageProcessing.h"
#include <iostream>
using namespace std;

int main() {
  // Path to the file
  // If image is in the same directory as executable
  // string fileName = "lena.pgm";
  char cont = 'y';
  // Clion paths 
  // string fileName = "..\\test_images\\lena.pgm";
  // string outputName = "..\\processed_images\\lena_copy.pgm";
  while (cont == 'y' || cont == 'Y'){ 
  // Paths that work with replit
  //string fileName = "test_images/noisy.pgm"; //WE NEED TO MAKE THIS NOT HARDCODED
  string fileName;
  //string outputName = "processed_images/noisy_filter.pgm"; //WE NEED TO MAKE THIS NOT HARDCODED
  string outputName;
  int imageOp = 0;
  cout << "Enter Original File Name: ";
  cin >> fileName;
  cout << endl;
  // Open File set information
  if (openPGM(fileName)) {
    // Get Image Size Information
    int width = getPGMWidth();
    int height = getPGMHeight();

    // Declare and allocate memory for data
    int **original;
    original = new int *[height];

    int **modified;
    modified = new int *[height];

    for (int i = 0; i < height; i++) {
      original[i] = new int[width];

      modified[i] = new int [width];
    }
    
     cout << "Select Operation:" << endl
      << "\t(0) Copy Image" << endl
      << "\t(1) Flip Vertical" << endl
      << "\t(2) Flip Horizontal" << endl
      << "\t(3) Median Filter 3x3" << endl
      << "\t(4) Median Filter 9x9" << endl
      << "\t(5) Median Filter 15x15" << endl;
    cout << "Enter Selection: ";
      cin >> imageOp;
    cout << "\nEnter Save File Name: ";
  cin >> outputName;

  

    // Get the data
    getPGMData(original);
    //getPGMData(modified);

    // declare main function from image processing

    // Write back out the same image
   // writePGM(outputName, original);
    switch (imageOp){
      case COPY:
        writePGM(outputName, copyImage(fileName, original));
        break;
      case VERTICAL:
        writePGM(outputName, flipVertical(fileName, original));
        break;
      case HORIZONTAL:
        writePGM(outputName, flipHorizontal(fileName, original));
        break;
      case MEDIAN3:
        writePGM(outputName, medianFilter(fileName, original, modified, height, width, imageOp));
        break;
      case MEDIAN9:
        writePGM(outputName, medianFilter(fileName, original, modified, height, width, imageOp));
        break;
      case MEDIAN15:
        writePGM(outputName, medianFilter(fileName, original, modified, height, width, imageOp));
        break;
      default:
        cout << "Error" << endl;
        break;
      }
  
    // Clean up memory
    cout << "Cleaning up now!" << endl;
    for (int i = 0; i < height; i++) {
      delete[] original[i];
      delete[] modified[i];
    }
    delete[] original;
    delete[] modified;
    cout << "Clean-up finished." << endl;
    cout << "Perform another operation [y/n]?" << endl;
    cont = 'n';
    while (cont != 'y' || cont != 'Y'){
      cin >> cont;
      if (cont == 'n' || cont =='N' || cont == 'y' || cont == 'Y'){
        break;
      }
      else {
        cout << "invalid character try again" << endl;
      }
    }
  }
    }
}
