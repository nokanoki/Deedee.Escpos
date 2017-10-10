#pragma once
#include <vector>
#include <Windows.h>
#include "Deedee.TableFormatter.h"


class EscposDocument
{
private:
	std::vector<unsigned char> buffer;
	UINT codePage;

public:
	EscposDocument();
	~EscposDocument();
	void Write(const wchar_t* str);
	void Feed(int lines = 1);
	void ReverseFeed(int lines);
	void Cut(bool fullCut = 0);
	void SetPrinterCodePage(int codepage);
	void SetDocumentCodePage(int codepage);
	//mode [0 none, 1 1dot 2 2dot]
	void SetUnderline(int mode);
	void Reset();
	void SetEmphasizedMode(bool enable);
	void SetDoubleStrike(bool enable);
	//1,2,3
	void SetFont(int font);
	//0 left, 1 center 2 right
	void SetJustificationMode(int mode);
	void SetReverseColor(bool enanle);
	void SetPrintMode(int font, bool bold, bool doubleHeight, bool doubleWidth);
	void WriteBarcode(int encoding, const wchar_t* str);
	void WriteQR(int model,int correctionLevel, const wchar_t* str);
	void WriteQR1(int magnification, int correction, const wchar_t *str);

	void SetLeftMargin(int i);
	void SetPrintableAreaWidth(int i);

	void WriteTableFormatter(const TableFormatter* formatter);


	size_t GetBufferSize() const;
	const unsigned char* GetBufferPointer() const;

private:
	int ByteSize(const wchar_t* str);


};