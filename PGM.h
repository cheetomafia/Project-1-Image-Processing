/**
 *	FileName:	PGM.h
 *	Author:		Ryan M. Bowen
 *	Date:		9/20/2012
 *	Revised:	9/26/2012
 *
 *	Description:	Functions to assist reading
 *					and wirting PGM files.
 */

#pragma once

#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

/**
 * File Stream object used through the program for image input
 */
static ifstream *pgmFile;

/**
 *	Conatians the full PGM Header
 */
static char header[500];

/**
 * Contains the Magic Number of the PGM file (i.e. P2)
 */
static char magicNumber[10];	

/**
 * Contains the PGM image comment
 */
static char comment[100];		

/**
 *	Buffer to be used for storing tempory data
 */
static char buffer[10];	

/**
 *	Width of the PGM File
 */

static int pgmWidth;

/**
 * Height of the PGM file
 */
static int pgmHeight;

/**
 *	Maximum value of pixels in the PGM file
 */
static int pgmMaxPix;

/**
 * Opens the PGM file and sets all information, 
 * Does not read the data!
 *
 * @fileName - name of the file to be read
 * @return true if everything when ok, else false
 */
bool openPGM(string fileName);

/**
 * Closes the opened PGM file and performs memory mantainence
 */
void closePGM();

/**
 * Reads the data in the PGM File that was opened.
 * Requires that openPGM is called first!
 *
 *	@data - data location to store the data read
 */
void getPGMData(int** data);

/**
 * Writes out data to a new PGM file
 * New file must have same header information and size
 *
 * @fileName - name of the file to be written
 * @data - data to be written 
 * @return true if everything when ok, else false
 */
bool writePGM(string fileName, int** data);

/*
 * Set the header information into variables
 * Automatically calls setPGMMagic, setPGMComment, 
 * setPGMMaxPixelSize, and setPGMSize.
 */
void setPGMHeader();

/*
 * Set the magic number information into variables
 */
void setPGMMagic();

/*
 * Set the commment information into variables
 */
void setPGMComment();

/*
 *  Set the max pixel size information into variables
 */
void setPGMMaxPixelSize();

/*
 * Set the image size information into variables
 */
void setPGMSize();

/*
 * Return the with of the PGM image data (columns)
 */
int getPGMWidth();

/*
 * Return the with of the PGM image data (rows)
 */
int getPGMHeight();
