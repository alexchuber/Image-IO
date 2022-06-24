#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Header.h"
#include "Pixel.h"

class File
{

private:

	vector<Pixel*> filePixels;
	Header fileHeader;

public:

	File();
	File(string path);
	File(const File& rhs);
	~File();

	File& operator=(const File& rhs);
	bool operator==(File& rhs) const;

	void Multiply(const File& top, const File& bottom);
	void Subtract(const File& top, const File& bottom);
	void Screen(const File& top, const File& bottom);
	void Overlay(const File& top, const File& bottom);

	void AddToGreenChannel(unsigned char value);

	void ScaleBlueChannel(float scaleFactor);
	void ScaleGreenChannel(float scaleFactor);
	void ScaleRedChannel(float scaleFactor);

	void AllBlueChannel();
	void AllGreenChannel();
	void AllRedChannel();

	void Combine(const File& blue, const File& green, const File& red);

	void Rotate180();

	void WriteTo(string path) const;
};

