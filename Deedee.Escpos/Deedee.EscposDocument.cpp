#include "Deedee.EscposDocument.h"


EscposDocument::EscposDocument()
{
	this->codePage = 1253;
}

EscposDocument::~EscposDocument()
{
}

void EscposDocument::Write(const wchar_t * str)
{
	
	auto sz = WideCharToMultiByte(this->codePage, 0, str, -1, NULL, 0, NULL, NULL);
	auto tmp = new unsigned char[sz];
	auto res = WideCharToMultiByte(this->codePage, 0, str, -1, (char*)tmp, sz, NULL, NULL);
	if (res < 1)
	{
		delete tmp;
		throw new std::exception("Convertion fails.");
	}
	//this->buffer.assign(tmp, tmp + (res - 1));
	this->buffer.insert(this->buffer.end(), tmp, tmp + (res - 1));
	delete tmp;
}

void EscposDocument::Feed(int lines)
{
	buffer.push_back(0x1b);
	buffer.push_back(0x64);
	buffer.push_back(lines);
}

void EscposDocument::ReverseFeed(int lines)
{
	this->buffer.push_back(0x1b);
	this->buffer.push_back(0x65);
	this->buffer.push_back(lines);
}

void EscposDocument::Cut(bool fullCut)
{
	this->buffer.push_back(29);
	this->buffer.push_back('V');
	if (fullCut)
		this->buffer.push_back('A');
	else
		this->buffer.push_back('B');
	this->buffer.push_back(50);
}

void EscposDocument::SetPrinterCodePage(int codepage)
{
	this->buffer.push_back(0x1b);
	this->buffer.push_back(0x74);
	this->buffer.push_back(codepage);
}

void EscposDocument::SetDocumentCodePage(int codepage)
{
	this->codePage = codepage;
}

void EscposDocument::SetUnderline(int mode)
{
	this->buffer.push_back(0x1b);
	this->buffer.push_back(0x2d);
	this->buffer.push_back(mode);
}

void EscposDocument::Reset()
{
	this->buffer.push_back(0x1b);
	this->buffer.push_back(0x40);
}

void EscposDocument::SetEmphasizedMode(bool enable)
{
	this->buffer.push_back(0x1b);
	this->buffer.push_back(0x45);
	this->buffer.push_back(enable);
}

void EscposDocument::SetDoubleStrike(bool enable)
{
	this->buffer.push_back(0x1b);
	this->buffer.push_back(0x47);
	this->buffer.push_back(enable);
}

void EscposDocument::SetFont(int font)
{
	this->buffer.push_back(0x1b);
	this->buffer.push_back(0x4d);
	this->buffer.push_back(font);
}

void EscposDocument::SetJustificationMode(int mode)
{
	this->buffer.push_back(0x1b);
	this->buffer.push_back(0x61);
	this->buffer.push_back(mode);
}

void EscposDocument::SetReverseColor(bool enanle)
{
	this->buffer.push_back(0x1d);
	this->buffer.push_back(0x42);
	this->buffer.push_back(enanle);
}

size_t EscposDocument::GetBufferSize() const
{
	return this->buffer.size();
}

const unsigned char * EscposDocument::GetBufferPointer() const
{
	return buffer.data();
}
