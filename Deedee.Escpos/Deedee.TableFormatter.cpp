#include "Deedee.TableFormatter.h"

#include <string>

TableFormatter::TableFormatter()
{
}


TableFormatter::~TableFormatter()
{
}

void TableFormatter::DefineColumns(int size)
{
	this->columns.push_back(size);
}

void TableFormatter::AddRow()
{
	this->buffer.push_back(L'\n');
}

void TableFormatter::SetColumnContent(int idx, const wchar_t * str, int justification)
{
	int columnSz = this->columns[idx];
	int strLen = wcslen(str);
	if (strLen >= columnSz)
	{
		this->buffer.insert(this->buffer.end(), str, str + columnSz);
		return;
	}
	int spaces = columnSz - strLen;
	switch (justification)
	{
	case 0://left
		this->buffer.insert(this->buffer.end(), str, str + strLen);
		this->AddSpaces(spaces);
		break;
	case 1://Center
	{
		if (spaces % 2)
		{
			this->AddSpaces(1);
			spaces--;
		}
		this->AddSpaces(spaces / 2);
		this->buffer.insert(this->buffer.end(), str, str + strLen);
		this->AddSpaces(spaces / 2);

	}break;
	case 2:// right
		this->AddSpaces(spaces);
		this->buffer.insert(this->buffer.end(), str, str + strLen);
		break;
	default:
		break;
	}

}

size_t TableFormatter::GetBufferSize() const
{
	return this->buffer.size();
}

const wchar_t * TableFormatter::GetBufferPointer() const
{
	return this->buffer.data();
}

void TableFormatter::AddSpaces(int n)
{
	for (size_t i = 0; i < n; i++)
	{
		this->buffer.push_back(L' ');
	}
}
