#include "StudentPreProcessing.h"
#include "ImageIO.h"
#include "ImageFactory.h"
#include <chrono>  // for high_resolution_clock
#include <iostream> //std::cout
#include <ctime>
#include <ratio>

#include <iostream>
#include <fstream>


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {


	IntensityImage * ItsImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	int SIZE = ItsImage->getHeight() * ItsImage->getWidth();

	for (int i = 0; i < SIZE; ++i) {
		RGB rgbConvert = image.getPixel(i);
		Intensity IntensityConvert = (Intensity)(rgbConvert.r * 0.299) + (rgbConvert.g * 0.587) + (rgbConvert.b * 0.114); // (luminosity Algorithm), Reference: Three algorithms for converting color to grayscalePosted on 24 August 2009 by John
		ItsImage->setPixel(i, IntensityConvert);
	}		
	 

	/* Pixel test */

	std::ofstream myfile;
	myfile.open("Student.txt");
	for (int i = 0; i < SIZE; ++i) {
		myfile << int(ItsImage->getPixel(i)) << "\n";
	}

	myfile.close();

	


	return ItsImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}