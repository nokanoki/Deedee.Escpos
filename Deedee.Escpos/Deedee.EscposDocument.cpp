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
	if (!res)
	{
		delete tmp;
		throw new std::exception("Convertion fails.");
	}
	this->buffer.assign(tmp, tmp + res);
	delete tmp;
}

void EscposDocument::Feed(int lines)
{
	buffer.push_back(27);
	buffer.push_back('d');
	buffer.push_back(lines);
}

void EscposDocument::Cut(bool fullCut)
{
	buffer.push_back(29);
	buffer.push_back('V');
	buffer.push_back(fullCut);
}

size_t EscposDocument::GetBufferSize() const
{
	return this->buffer.size();
}

const unsigned char * EscposDocument::GetBufferPointer() const
{
	return buffer.data();
}
