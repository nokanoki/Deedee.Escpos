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

void EscposDocument::SetPrintMode(int font, bool bold, bool doubleHeight, bool doubleWidth)
{
	this->buffer.push_back(0x1b);
	this->buffer.push_back(0x21);
	unsigned char bits = 0;
	if (font)
		bits |= 1;
	if (bold)
		bits |= 1 << 3;
	if (doubleHeight)
		bits |= 1 << 4;
	if (doubleWidth)
		bits |= 1 << 5;
	this->buffer.push_back(bits);
}

void EscposDocument::WriteBarcode(int encoding, const wchar_t * str)
{
	auto sz = wcslen(str);
	bool isAllDigits = true;
	bool isAllAlphaCaps = true;
	for (const wchar_t* i = str; *i ; i++)
	{
		if(isAllAlphaCaps)
			isAllDigits = iswalnum(*i);
		if (isAllAlphaCaps)
			isAllAlphaCaps = (*i >= L'A' && *i <= L'Z');
	}
	switch (encoding)
	{
	case 0:
	case 1: 
		if (!(isAllDigits && (sz == 11 || sz == 12))) 
			throw new std::exception("input fails");
		break;
	case 2: 
		if (!(isAllDigits && (sz == 7 || sz == 8))) 
			throw new std::exception("input fails");
		break;
	case 3: 
		if (!(isAllDigits && (sz == 11 || sz == 12)))
			throw new std::exception("input fails");
		break;
	case 4: 
		if (!((isAllDigits || isAllAlphaCaps) )) 
			throw new std::exception("input fails");
		break;
	case 5:
		if (!isAllDigits && !(sz % 2)) 
			throw new std::exception("input fails.");
		break;
	case 6: 
		throw new std::exception("validator not impl");
		break;

	default:
		throw new std::exception("encoding not impl");
		break;
	}
	
	this->buffer.push_back(0x1d);
	this->buffer.push_back(0x6b);
	this->buffer.push_back(encoding);
	this->Write(str);
	this->buffer.push_back(0);

}

size_t EscposDocument::GetBufferSize() const
{
	return this->buffer.size();
}

const unsigned char * EscposDocument::GetBufferPointer() const
{
	return buffer.data();
}
