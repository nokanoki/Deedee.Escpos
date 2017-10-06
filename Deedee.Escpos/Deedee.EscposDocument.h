#pragma once
#include <vector>
#include <Windows.h>

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
	void Cut(bool fullCut = 0);


	size_t GetBufferSize() const;
	const unsigned char* GetBufferPointer() const;


};