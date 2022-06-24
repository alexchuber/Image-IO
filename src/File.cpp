#include "File.h"

File::File()
{}

File::File(string path)
{
	ifstream inFile(path, ios_base::in | ios_base::binary);

	//Getting header data
	inFile.read((char*)&fileHeader.idLength, 1);
	inFile.read((char*)&fileHeader.colorMapType, 1);
	inFile.read((char*)&fileHeader.dataTypeCode, 1);
	inFile.read((char*)&fileHeader.colorMapOrigin, 2);
	inFile.read((char*)&fileHeader.colorMapLength, 2);
	inFile.read((char*)&fileHeader.colorMapDepth, 1);
	inFile.read((char*)&fileHeader.xOrigin, 2);
	inFile.read((char*)&fileHeader.yOrigin, 2);
	inFile.read((char*)&fileHeader.width, 2);
	inFile.read((char*)&fileHeader.height, 2);
	inFile.read((char*)&fileHeader.bitsPerPixel, 1);
	inFile.read((char*)&fileHeader.imageDescriptor, 1);
	fileHeader.imageSize = (int)(fileHeader.width) * (int)(fileHeader.height);

	//Getting pixel data
	for (int i = 0; i < fileHeader.imageSize; i++)
	{
		Pixel* pixel = new Pixel;
		inFile.read((char*)&pixel->blue, 1);
		inFile.read((char*)&pixel->green, 1);
		inFile.read((char*)&pixel->red, 1);
		filePixels.push_back(pixel);
	}
}


File::File(const File& rhs)
{
	fileHeader = rhs.fileHeader;

	for (unsigned int i = 0; i < rhs.filePixels.size(); i++) {
		
		unsigned char rhsBlue = rhs.filePixels.at(i)->blue;
		unsigned char rhsGreen = rhs.filePixels.at(i)->green;
		unsigned char rhsRed = rhs.filePixels.at(i)->red;
		
		Pixel* newPixel = new Pixel(rhsBlue, rhsGreen, rhsRed);
		filePixels.push_back(newPixel);
	}
}

File::~File()
{
	for (unsigned int i = 0; i < filePixels.size(); i++)
		delete filePixels.at(i);
}

File& File::operator=(const File& rhs)
{
	File* newFile = new File(rhs);
	return *newFile;
}

bool File::operator==(File& rhs) const
{
	for (int i = 0; i < fileHeader.imageSize; i++)
	{
		unsigned char lhsblue = filePixels.at(i)->blue;
		unsigned char lhsgreen = filePixels.at(i)->green;
		unsigned char lhsred = filePixels.at(i)->red;

		unsigned char rhsblue = rhs.filePixels.at(i)->blue;
		unsigned char rhsgreen = rhs.filePixels.at(i)->green;
		unsigned char rhsred = rhs.filePixels.at(i)->red;

		if (lhsblue != rhsblue || 
			lhsgreen != rhsgreen ||
			lhsred != rhsred)
		{
			cout << "First inequality found at pixel index " << i << endl;
			cout << "My image's RGB: " << (int)lhsred << "," << (int)lhsgreen << "," << (int)lhsblue << endl;
			cout << "Example image's RGB: " << (int)rhsred << "," << (int)rhsgreen << "," << (int)rhsblue << endl;
			
			return false;
		}
	}
	return true;
}

void File::Multiply(const File& top, const File& bottom)
{
	fileHeader = top.fileHeader;
	filePixels.clear();
	
	for (int i = 0; i < fileHeader.imageSize; i++)
	{
		const Pixel* topPixel = top.filePixels.at(i);
		const Pixel* bottomPixel = bottom.filePixels.at(i);

		Pixel* newPixel = new Pixel;

		newPixel->MultiplyAll(topPixel, bottomPixel);

		filePixels.push_back(newPixel);
	}
}

void File::Subtract(const File& top, const File& bottom)
{
	fileHeader = top.fileHeader;
	filePixels.clear();

	for (int i = 0; i < fileHeader.imageSize; i++)
	{
		const Pixel* topPixel = top.filePixels.at(i);
		const Pixel* bottomPixel = bottom.filePixels.at(i);

		Pixel* newPixel = new Pixel;
		newPixel->AddBlue(bottomPixel->blue);
		newPixel->SubtractBlue(topPixel->blue);

		newPixel->AddGreen(bottomPixel->green);
		newPixel->SubtractGreen(topPixel->green);

		newPixel->AddRed(bottomPixel->red);
		newPixel->SubtractRed(topPixel->red);

		filePixels.push_back(newPixel);
	}
}

void File::Screen(const File& top, const File& bottom)
{
	fileHeader = top.fileHeader;
	filePixels.clear();

	for (int i = 0; i < fileHeader.imageSize; i++)
	{
		const Pixel* topPixel = top.filePixels.at(i);
		const Pixel* bottomPixel = bottom.filePixels.at(i);

		Pixel* newPixel = new Pixel;

		newPixel->ScreenAll(topPixel, bottomPixel);

		filePixels.push_back(newPixel);
	}
}

void File::Overlay(const File& top, const File& bottom)
{
	fileHeader = top.fileHeader;
	filePixels.clear();

	for (int i = 0; i < fileHeader.imageSize; i++)
	{
		const Pixel* topPixel = top.filePixels.at(i);
		const Pixel* bottomPixel = bottom.filePixels.at(i);

		Pixel* newPixel = new Pixel;

		float bottomBlue = (float)(bottomPixel->blue) / 255.f;
		if (bottomBlue <= .5f)
			newPixel->MultiplyBlue(topPixel, bottomPixel, 2.f);
		else
			newPixel->ScreenBlue(topPixel, bottomPixel, 2.f);

		float bottomGreen = (float)(bottomPixel->green) / 255.f;
		if (bottomGreen <= .5f)
			newPixel->MultiplyGreen(topPixel, bottomPixel, 2.f);
		else
			newPixel->ScreenGreen(topPixel, bottomPixel, 2.f);

		float bottomRed = (float)(bottomPixel->red) / 255.f;
		if (bottomRed <= .5f)
			newPixel->MultiplyRed(topPixel, bottomPixel, 2.f);
		else
			newPixel->ScreenRed(topPixel, bottomPixel, 2.f);

		filePixels.push_back(newPixel);
	}
}

void File::AddToGreenChannel(unsigned char value)
{
	for (unsigned int i = 0; i < filePixels.size(); i++)
		filePixels.at(i)->AddGreen(value);
}

void File::ScaleBlueChannel(float scaleFactor)
{
	for (unsigned int i = 0; i < filePixels.size(); i++)
		filePixels.at(i)->ScaleBlue(scaleFactor);
}

void File::ScaleGreenChannel(float scaleFactor)
{
	for (unsigned int i = 0; i < filePixels.size(); i++)
		filePixels.at(i)->ScaleGreen(scaleFactor);
}

void File::ScaleRedChannel(float scaleFactor)
{
	for (unsigned int i = 0; i < filePixels.size(); i++)
		filePixels.at(i)->ScaleRed(scaleFactor);
}

void File::AllBlueChannel()
{
	for (unsigned int i = 0; i < filePixels.size(); i++)
	{
		filePixels.at(i)->red = filePixels.at(i)->blue;
		filePixels.at(i)->green = filePixels.at(i)->blue;
	}
}

void File::AllGreenChannel()
{
	for (unsigned int i = 0; i < filePixels.size(); i++)
	{
		filePixels.at(i)->red = filePixels.at(i)->green;
		filePixels.at(i)->blue = filePixels.at(i)->green;
	}
}

void File::AllRedChannel()
{
	for (unsigned int i = 0; i < filePixels.size(); i++)
	{
		filePixels.at(i)->green = filePixels.at(i)->red;
		filePixels.at(i)->blue = filePixels.at(i)->red;
	}
}

void File::Combine(const File& blue, const File& green, const File& red)
{
	fileHeader = blue.fileHeader;
	filePixels.clear();

	for (unsigned int i = 0; i < blue.filePixels.size(); i++)
	{
		Pixel* newPixel = new Pixel;

		newPixel->blue = blue.filePixels.at(i)->blue;
		newPixel->green = green.filePixels.at(i)->green;
		newPixel->red = red.filePixels.at(i)->red;

		filePixels.push_back(newPixel);
	}
}

void File::Rotate180()
{
	vector<Pixel*> newFilePixels;
	for (unsigned int i = filePixels.size(); i > 0; i--)
		newFilePixels.push_back(filePixels.at(i-1));
	filePixels = newFilePixels;
}

void File::WriteTo(string path) const
{
	fstream file(path, ios_base::out | ios_base::binary);

	file.write((char*)&fileHeader.idLength, 1);
	file.write((char*)&fileHeader.colorMapType, 1);
	file.write((char*)&fileHeader.dataTypeCode, 1);
	file.write((char*)&fileHeader.colorMapOrigin, 2);
	file.write((char*)&fileHeader.colorMapLength, 2);
	file.write((char*)&fileHeader.colorMapDepth, 1);
	file.write((char*)&fileHeader.xOrigin, 2);
	file.write((char*)&fileHeader.yOrigin, 2);
	file.write((char*)&fileHeader.width, 2);
	file.write((char*)&fileHeader.height, 2);
	file.write((char*)&fileHeader.bitsPerPixel, 1);
	file.write((char*)&fileHeader.imageDescriptor, 1);

	for (unsigned int i = 0; i < filePixels.size(); i++)
	{
		Pixel* pixel = filePixels.at(i);
		file.write((char*)&pixel->blue, 1);
		file.write((char*)&pixel->green, 1);
		file.write((char*)&pixel->red, 1);
	}
}