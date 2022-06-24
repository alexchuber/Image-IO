#pragma once
using namespace std;

struct Pixel
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;

	Pixel();
	Pixel(unsigned char blue_, unsigned char green_, unsigned char red_);

	void AddBlue(unsigned char value);
	void AddGreen(unsigned char value);
	void AddRed(unsigned char value);

	void SubtractBlue(unsigned char value);
	void SubtractGreen(unsigned char value);
	void SubtractRed(unsigned char value);

	void ScaleBlue(float scaleFactor);
	void ScaleGreen(float scaleFactor);
	void ScaleRed(float scaleFactor);

	void MultiplyBlue(const Pixel* top, const Pixel* bottom, float scaleFactor = 1.f);
	void MultiplyGreen(const Pixel* top, const Pixel* bottom, float scaleFactor = 1.f);
	void MultiplyRed(const Pixel* top, const Pixel* bottom, float scaleFactor = 1.f);
	void MultiplyAll(const Pixel* top, const Pixel* bottom, float scaleFactor = 1.f);

	void ScreenBlue(const Pixel* top, const Pixel* bottom, float scaleFactor = 1.f);
	void ScreenGreen(const Pixel* top, const Pixel* bottom, float scaleFactor = 1.f);
	void ScreenRed(const Pixel* top, const Pixel* bottom, float scaleFactor = 1.f);
	void ScreenAll(const Pixel* top, const Pixel* bottom, float scaleFactor = 1.f);
};

