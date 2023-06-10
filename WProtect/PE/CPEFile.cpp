#include "CPEFile.h"

#include <cstdio>

CPEFile::CPEFile()
{
	this->m_pFile = new MAP_FILE_STRUCT;
	memset(m_pFile, 0, sizeof(MAP_FILE_STRUCT));
}

bool CPEFile::LoadPEFile(const char* filename)
{
	FILE* pFile = nullptr;
	ULONG64 ulSize = 0;

	if (this->m_pFile->ImageBase)
	{
		delete[] this->m_pFile->ImageBase;
		this->m_pFile->ImageBase = nullptr;
		this->m_pFile->Size = 0;
	}

	pFile = fopen(filename, "rb");
	if (!pFile)
	{
		return false;
	}

	fseek(pFile, 0, SEEK_END);
	ulSize = ftell(pFile);
	if (ulSize <= 0)
	{
		return false;
	}
	m_pFile->ImageBase = new unsigned char[ulSize];
	rewind(pFile);
	fread(m_pFile->ImageBase, 1, ulSize, pFile);
	fclose(pFile);
	m_pFile->Size = ulSize;
	return true;
}

bool CPEFile::IsPEFile()
{
	PIMAGE_DOS_HEADER pDosHdr = GetDosHeader();
	if (pDosHdr->e_magic == IMAGE_DOS_SIGNATURE)
	{
		auto pNtHdr = GetNtHeader();
		if (pNtHdr->Signature == IMAGE_NT_SIGNATURE)
		{
			return true;
		}
	}
	return false;
}

void CPEFile::Free()
{
	if (m_pFile->ImageBase)
	{
		delete[] m_pFile->ImageBase;
		m_pFile->ImageBase = NULL;
		m_pFile->Size = 0;
	}
	if (m_pFile)
	{
		delete[] m_pFile;
		m_pFile = NULL;
	}
}

void* CPEFile::GetImage()
{
	return m_pFile->ImageBase;
}

PIMAGE_DOS_HEADER CPEFile::GetDosHeader()
{
	return reinterpret_cast<PIMAGE_DOS_HEADER>(GetImage());
}

PIMAGE_NT_HEADERS32 CPEFile::GetNtHeader()
{
	PIMAGE_DOS_HEADER pDosHdr = GetDosHeader();
	if (pDosHdr)
	{
		return reinterpret_cast<PIMAGE_NT_HEADERS32>((DWORD)GetImage() + pDosHdr->e_lfanew);
	}
	return nullptr;
}

PIMAGE_FILE_HEADER CPEFile::GetNtFileHeader()
{
	PIMAGE_NT_HEADERS32 pNth = GetNtHeader();
	if (pNth)
	{
		return reinterpret_cast<PIMAGE_FILE_HEADER>(&pNth->FileHeader);
	}
	return nullptr;
}
