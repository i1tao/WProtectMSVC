#pragma once
#ifndef WINDOWS_H
#define WINDOWS_H
#include <windows.h>
#endif

typedef struct _MAP_FILE_STRUCT
{
	void* ImageBase;
	unsigned long Size;
}MAP_FILE_STRUCT, * PMAP_FILE_STRUCT;

class CPEFile
{
public:
	MAP_FILE_STRUCT* m_pFile;
public:
	CPEFile();
	bool LoadPEFile(const char* filename);
	bool IsPEFile();
	void Free();

	void* GetImage();
	PIMAGE_DOS_HEADER GetDosHeader();
	PIMAGE_NT_HEADERS32 GetNtHeader();
	PIMAGE_FILE_HEADER GetNtFileHeader();
	PIMAGE_OPTIONAL_HEADER32 GetNtOptionalHeader();
	PIMAGE_DATA_DIRECTORY GetDataDirectory();
	PIMAGE_DATA_DIRECTORY GetDataDirectory(int index);
	int GetSectionCount();
	PIMAGE_SECTION_HEADER GetFirstSectionHeader();
	bool SavePEFile(char* save_file_name);
	PMAP_FILE_STRUCT GetInfo();
	bool SetInfo(PMAP_FILE_STRUCT pMapFile);
	PIMAGE_SECTION_HEADER GetSection(int index);
	void* GetDirectoryEntryToData(unsigned short DirectoryEntry);
	PIMAGE_SECTION_HEADER ImageRvaToSection(
			PIMAGE_NT_HEADERS32 NtHeader,
			void* BaseAddress,
			ULONG Rva);
	void* ImageRvaToVa(
		PIMAGE_NT_HEADERS32 NtHeader,
		void* BaseAddress,
		ULONG Rva,
		PIMAGE_SECTION_HEADER* SectionHeader);
	void* RvaToPtr(DWORD dwRVA);
	void* VaToPtr(DWORD dwVA);
};