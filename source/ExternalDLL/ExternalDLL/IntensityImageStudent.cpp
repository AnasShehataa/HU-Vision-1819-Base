#include "IntensityImageStudent.h"
#include "RGBImageStudent.h"
#include "ImageFactory.h"


IntensityImageStudent::IntensityImageStudent() : IntensityImage(), pixelMap(nullptr) { }

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()), pixelMap(nullptr) {
	const int SIZE = other.getWidth() * other.getHeight();

	if (SIZE > 0) {
		pixelMap = new Intensity[SIZE];
		for (int i = 0; i < SIZE; i++) {
			pixelMap[i] = other.getPixel(i);
		}
	}
}



IntensityImageStudent::IntensityImageStudent(const IntensityImage &other) : IntensityImage(other.getWidth(), other.getHeight()), pixelMap(nullptr) {
	const int SIZE = other.getWidth() * other.getHeight();
	if (SIZE > 0) {
		pixelMap = new Intensity[SIZE];
		for (int i = 0; i < SIZE; i++) {
			pixelMap[i] = other.getPixel(i);
		}
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height), pixelMap(nullptr) {
	const int SIZE = width * height;
	if (SIZE > 0) {
		pixelMap = new Intensity[SIZE]{};
	}
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] pixelMap;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	const int SIZE = (width * height);

	if (SIZE > 0) {
		delete[] pixelMap;
		pixelMap = new Intensity[width * height];
	}
}

void IntensityImageStudent::set(const IntensityImage &other) {
	const int	SIZE = other.getWidth() * other.getHeight();
	IntensityImage::set(other.getWidth(), other.getHeight());

	if (SIZE > 0) {
		delete[] pixelMap;
		pixelMap = new Intensity[SIZE];
		for (int i = 0; i < SIZE; i++) {
			pixelMap[i] = other.getPixel(i);
		}
	}
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	const int	SIZE = other.getWidth() * other.getHeight();
	IntensityImage::set(other.getWidth(), other.getHeight());

	if (SIZE > 0) {
		delete[] pixelMap;
		pixelMap = new Intensity[SIZE];
		for (int i = 0; i < SIZE; i++) {
			pixelMap[i] = other.getPixel(i);
		}
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixelMap[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixelMap[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixelMap[y * getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixelMap[i];
}

/* 
IntensityImage * IntensityImageStudent::RgbToIntensity(RGBImage & rgbImage)
{
	IntensityImage * outputImage = ImageFactory::newIntensityImage(rgbImage.getWidth(), rgbImage.getHeight());
	int SIZE = rgbImage.getWidth() * rgbImage.getHeight();

	for (int i = 0; i < SIZE; i++) {
		RGB RgbPixel = rgbImage.getPixel(i);

		Intensity OutputPixel = (Intensity)(RgbPixel.r * 0.2126) + (RgbPixel.g * 0.7152) + (RgbPixel.b * 0.0722); //Luminosity grayscaling algorithm ( Three algorithms for converting color to grayscalePosted on 24 August 2009 by John)
		outputImage->setPixel(i, OutputPixel);
	}
	return outputImage;
}*/
