#include "Pixel.h"

Pixel::Pixel()
{
	blue = 0;
	green = 0;
	red = 0;
}

Pixel::Pixel(unsigned char blue_, unsigned char green_, unsigned char red_)
{
	blue = blue_;
	green = green_;
	red = red_;
}

void Pixel::AddBlue(unsigned char value)
{
	int blueInt = (int)blue;
	int valueInt = (int)value;
	blueInt += valueInt;
	if (blueInt > 255)
		blueInt = 255;
	else if (blueInt < 0)
		blueInt = 0;
	blue = (unsigned char)blueInt;
}

void Pixel::SubtractBlue(unsigned char value)
{
	int blueInt = (int)blue;
	int valueInt = (int)value;
	blueInt -= valueInt;
	if (blueInt > 255)
		blueInt = 255;
	else if (blueInt < 0)
		blueInt = 0;
	blue = (unsigned char)blueInt;
}

void Pixel::AddGreen(unsigned char value)
{
	int greenInt = (int)green;
	int valueInt = (int)value;
	greenInt += valueInt;
	if (greenInt > 255)
		greenInt = 255;
	else if (greenInt < 0)
		greenInt = 0;
	green = (unsigned char)greenInt;
}

void Pixel::SubtractGreen(unsigned char value)
{
	int greenInt = (int)green;
	int valueInt = (int)value;
	greenInt -= valueInt;
	if (greenInt > 255)
		greenInt = 255;
	else if (greenInt < 0)
		greenInt = 0;
	green = (unsigned char)greenInt;
}

void Pixel::AddRed(unsigned char value)
{
	int redInt = (int)red;
	int valueInt = (int)value;
	redInt += valueInt;
	if (redInt > 255)
		redInt = 255;
	else if (redInt < 0)
		redInt = 0;
	red = (unsigned char)redInt;
}

void Pixel::SubtractRed(unsigned char value)
{
	int redInt = (int)red;
	int valueInt = (int)value;
	redInt -= valueInt;
	if (redInt > 255)
		redInt = 255;
	else if (redInt < 0)
		redInt = 0;
	red = (unsigned char)redInt;
}

void Pixel::ScaleBlue(float scaleFactor)
{
	float blueFloat = (float)blue;
	blueFloat *= scaleFactor;
	blueFloat += 0.5f;
	if (blueFloat > 255.f)
		blueFloat = 255.f;
	else if (blueFloat < 0.f)
		blueFloat = 0.f;
	blue = (unsigned char)blueFloat;
}

void Pixel::ScaleGreen(float scaleFactor)
{
	float greenFloat = (float)green;
	greenFloat *= scaleFactor;
	greenFloat += 0.5f;
	if (greenFloat > 255.f)
		greenFloat = 255.f;
	else if (greenFloat < 0.f)
		greenFloat = 0.f;
	green = (unsigned char)greenFloat;
}

void Pixel::ScaleRed(float scaleFactor)
{
	float redFloat = (float)red;
	redFloat *= scaleFactor;
	redFloat += 0.5f;
	if (redFloat > 255.f)
		redFloat = 255.f;
	else if (redFloat < 0.f)
		redFloat = 0.f;
	red = (unsigned char)redFloat;
}

void Pixel::MultiplyBlue(const Pixel* top, const Pixel* bottom, float scaleFactor)
{
	float topBlue = (float)(top->blue) / 255.f;
	float bottomBlue = (float)(bottom->blue) / 255.f;
	float newBlue = ((scaleFactor * topBlue * bottomBlue) * 255.f) + 0.5f;
	blue = (unsigned char)(newBlue);
}

void Pixel::MultiplyGreen(const Pixel* top, const Pixel* bottom, float scaleFactor)
{
	float topGreen = (float)(top->green) / 255.f;
	float bottomGreen = (float)(bottom->green) / 255.f;
	float newGreen = ((scaleFactor * topGreen * bottomGreen) * 255.f) + 0.5f;
	green = (unsigned char)(newGreen);
}

void Pixel::MultiplyRed(const Pixel* top, const Pixel* bottom, float scaleFactor)
{
	float topRed = (float)(top->red) / 255.f;
	float bottomRed = (float)(bottom->red) / 255.f;
	float newRed = ((scaleFactor * topRed * bottomRed) * 255.f) + 0.5f;
	red = (unsigned char)(newRed);
}

void Pixel::MultiplyAll(const Pixel* top, const Pixel* bottom, float scaleFactor)
{
	MultiplyGreen(top, bottom, scaleFactor);
	MultiplyBlue(top, bottom, scaleFactor);
	MultiplyRed(top, bottom, scaleFactor);
}

void Pixel::ScreenBlue(const Pixel* top, const Pixel* bottom, float scaleFactor)
{
	float topBlue = 1.f - ((float)(top->blue) / 255.f);
	float bottomBlue = 1.f - ((float)(bottom->blue) / 255.f);
	float newBlue = ((1.f - (scaleFactor * topBlue * bottomBlue)) * 255.f) + 0.5f;
	blue = (unsigned char)(newBlue);
}

void Pixel::ScreenGreen(const Pixel* top, const Pixel* bottom, float scaleFactor)
{
	float topGreen = 1.f - ((float)(top->green) / 255.f);
	float bottomGreen = 1.f - ((float)(bottom->green) / 255.f);
	float newGreen = ((1.f - (scaleFactor * topGreen * bottomGreen)) * 255.f) + 0.5f;
	green = (unsigned char)(newGreen);
}

void Pixel::ScreenRed(const Pixel* top, const Pixel* bottom, float scaleFactor)
{
	float topRed = 1.f - ((float)(top->red) / 255.f);
	float bottomRed = 1.f - ((float)(bottom->red) / 255.f);
	float newRed = ((1.f - (scaleFactor * topRed * bottomRed)) * 255.f) + 0.5f;
	red = (unsigned char)(newRed);
}

void Pixel::ScreenAll(const Pixel* top, const Pixel* bottom, float scaleFactor)
{
	ScreenGreen(top, bottom, scaleFactor);
	ScreenBlue(top, bottom, scaleFactor);
	ScreenRed(top, bottom, scaleFactor);
}