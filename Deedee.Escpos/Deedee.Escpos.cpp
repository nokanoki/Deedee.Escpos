#include "Deedee.Escpos.h"
#include "Deedee.EscposDocument.h"
#include <string>

#define asDoc(doc) ((EscposDocument*)doc)


INT32 DEEDEEAPI DeedeeDocCreate(void ** doc)
{
	void *tmp = new EscposDocument();
	if (!tmp)
		return -1;
	*doc = tmp;
	return 0;
}

INT32 DEEDEEAPI DeedeeDocDestroy(void * doc)
{
	delete (EscposDocument*)doc;
	return 0;
}

INT32 DEEDEEAPI DeedeeDocWrite(void * doc, const wchar_t * str)
{
	if (!doc || !str)
		return -1;
	try
	{
		((EscposDocument*)doc)->Write(str);
	}
	catch (std::exception &e)
	{
		return -1;
	}

	return 0;
}

INT32 DEEDEEAPI DeedeeDocFeedLines(void * doc, int lines)
{
	asDoc(doc)->Feed(lines);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocFeed(void * doc)
{
	asDoc(doc)->Feed(1);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocCut(void * doc, int fullcut)
{
	asDoc(doc)->Cut(fullcut);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocReverseFeed(void * doc, int lines)
{
	asDoc(doc)->ReverseFeed(lines);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocSetPrinterCodePage(void *doc, int codePage)
{
	asDoc(doc)->SetPrinterCodePage(codePage);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocSetCodePage(void * doc, int codePage)
{
	asDoc(doc)->SetDocumentCodePage(codePage);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocSetJustificationMode(void * doc, int mode)
{
	asDoc(doc)->SetJustificationMode(mode);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocSetUnderlineMode(void * doc, int mode)
{
	asDoc(doc)->SetUnderline(mode);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocSetEmphasized(void * doc, int enable)
{
	asDoc(doc)->SetEmphasizedMode(enable);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocSetFont(void * doc, int font)
{
	asDoc(doc)->SetFont(font);
	return 0;
}

INT32 DEEDEEAPI DeedeeDocReset(void * doc)
{
	asDoc(doc)->Reset();
	return 0;
}

INT32 DEEDEEAPI DeedeeDocSetDoubleStrike(void * doc, int enable)
{
	asDoc(doc)->SetDoubleStrike(enable);
	return 0;
}



INT32 DEEDEEAPI DeedeePrint(const wchar_t* printerName, const void* doc)
{
	DOC_INFO_1 docInfo = {};
	docInfo.pDatatype = __TEXT("RAW");
	docInfo.pDocName = __TEXT("deedeedoc");
	WCHAR printerName0[512] = { 0 };
	wcscpy_s(printerName0, printerName);

	const EscposDocument *d = (EscposDocument*)doc;
	INT32 error = 0;

	HANDLE hPrinter = NULL;
	//dafuq non-constant name
	if (!OpenPrinter(printerName0, &hPrinter, NULL))
		return -1;
	if (StartDocPrinter(hPrinter, 1, (BYTE*)&docInfo))
	{
		if (StartPagePrinter(hPrinter))
		{
			DWORD dwWritten = 0;
			BOOL bSuccess = 
				WritePrinter(hPrinter, (LPVOID)d->GetBufferPointer(), d->GetBufferSize(), &dwWritten);
			EndPagePrinter(hPrinter);
			if (!bSuccess)
				error = -2;
			if (dwWritten != d->GetBufferSize())
				error = -3;
		}
		EndDocPrinter(hPrinter);
	}
	ClosePrinter(hPrinter);

	return error;
}

