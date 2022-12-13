/**
 *	FileName:	PGM.cpp
 *	Author:		Ryan M. Bowen
 *	Date:		9/20/2012
 *	Revised:	2/21/2020
 *
 *	Description:	Source code for functions to assist reading
 *					and writing PGM files.
 */
#include "PGM.h"


bool openPGM(string fileName)
{
	// Open the file
	pgmFile = new ifstream(fileName);
	
	// If open if successful then proceed to read header information
	if (pgmFile->is_open()) {		
		setPGMHeader();		
	}else{
		return false;
	}

	return true;
}

void closePGM()
{
	// Close the File
	pgmFile->close();		
}

bool writePGM(string fileName, int** data)
{
	// Open the output stream
	ofstream myWriteFile;
	myWriteFile.open(fileName);

	// Check if file opened ok
	if (myWriteFile.is_open()) {

		// Write the header first
		myWriteFile << header;

		// iterate through the data and output to the file
		// ASSUMING DATA IS PROPER TO THE HEADER
		for(int j=0; j<pgmHeight; j++){
			for(int k=0; k<pgmWidth; k++){
				myWriteFile << data[j][k] << " ";
			}
			myWriteFile << endl;
		}
	
	}else {
		return false;
	}

	// Done writing, close the file
	myWriteFile.close();
	return true;
}

void setPGMHeader()
{
	cout << "Reading in File\n";
	if (pgmFile->is_open()) {
    
		// Clear the memory of the header
		memset(&header[0], 0, sizeof(header));
		
		// ORDER OF THIS IS IMPORTANT
		// Set the magic number
		setPGMMagic();
    
		// Set the comment
		setPGMComment();
    
		// The sizes magicNumber, comment, pgmWidth, pgmHeight, pgmMaxPix
		setPGMSize();

		// Set the max pixel size
		setPGMMaxPixelSize();

		// Concat everything together for the full header
		sprintf(header,"%s\n%s\n%d %d\n%d\n", magicNumber, comment, pgmWidth, pgmHeight, pgmMaxPix); 
	}
	
	cout << "Done Reading in File\n";
}

/*
 * Set the magic number information into variables
 */
void setPGMMagic()
{
	// Clear memory
	memset(&magicNumber[0], 0, sizeof(magicNumber));

	// Two character magic number
	// >> increments the file pointer
	*pgmFile>>*magicNumber;
	*pgmFile>>*(magicNumber+1);
}

/*
 * Set the commment information into variables
 */
void setPGMComment()
{
	// clear the memory 
	memset(&comment[0], 0, sizeof(comment));
  int i =0;	

	// read in the comment till end of the line
	do{ 
		*pgmFile>>*(comment+i);
  	i++;
    
	}while((pgmFile->peek()!='\n'));

}

/*
 * Set the image size information into variables
 */
void setPGMSize()
{

		// Clear the buffer
		int i=0;		
		memset(&buffer[0], 0, sizeof(buffer));

		// Read first size, ended by a space
		do{
			*pgmFile>>buffer[i];	
			i++;
			
		}while(pgmFile->peek()!=' ');

		// Convert to an integer
		sscanf(buffer,"%d",&pgmWidth);

		// clear the buffer
		i=0;
		memset(&buffer[0], 0, sizeof(buffer));

		// Read the next number, ended by newline
		do{
			*pgmFile>>buffer[i];	
			i++;
			
		}while(pgmFile->peek()!='\n');

		// convert to integer
		sscanf(buffer,"%d",&pgmHeight);
}

/*
 *  Set the max pixel size information into variables
 */
void setPGMMaxPixelSize()
{
		// Clear the buffer
		int i=0;
		memset(&buffer[0], 0, sizeof(buffer));

		// Read in the number, ended by newline
		do{
			*pgmFile>>buffer[i];	
			i++;
			
		}while(pgmFile->peek()!='\n');

		//convert to an integer
		sscanf(buffer,"%d",&pgmMaxPix);
}

/**
 * Reads the data in the PGM File that was opened.
 * Requires that openPGM is called first!
 *
 *	@data - data location to store the data read
 */
void getPGMData(int** data)
{

	// read in the image into data
	int i;
	int cNum;

	// loop across rows and column base don previously read header information
	for(int j=0; j<pgmHeight; j++){
		for(int k=0; k<pgmWidth; k++){
			
			// clear the buffer
			i=0;
			memset(&buffer[0], 0, sizeof(buffer));

			// Read in a number, space or newline terminated
			do{
				*pgmFile>>buffer[i];
				i++;
			}while((pgmFile->peek()!=' ') && (pgmFile->peek()!='\n'));

			// convert to a number
			sscanf(buffer,"%d",&cNum);	
	
			// store in data
			data[j][k] = cNum;
		}
	}
}


/*
 * Return the max pixel value of the PGM image data
 */
int getPGMMaxPixelSize(){

		return pgmMaxPix;
}

/*
 * Return the with of the PGM image data (columns)
 */
int getPGMWidth(){
		return pgmWidth;
}

/*
 * Return the with of the PGM image data (rows)
 */
int getPGMHeight(){
		return pgmHeight;
}
