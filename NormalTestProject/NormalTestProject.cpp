// NormalTestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

void testChar();
void Test2();
void Test3();
void TestWcsMemCpy();
void TestStrToUpperLower1();
void TestStrToUpperLower2();
void TestAlloc();

int _tmain(int argc, _TCHAR* argv[])
{
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

    TestAlloc();

    TestStrToUpperLower1();
    TestStrToUpperLower2();

   /* TestWcsMemCpy();
    Test3();
    Test2();
	testChar();*/
	return 0;
}

//  2021/6/2
void TestAlloc()
{
    int* nArray = new int[4];
    float* data = new float();
}

//  2021/5/22
void TestStrToUpperLower1()
{
    string strTest = ".jWS";
    wstring wcsTest = L".jWS";

    printf("%s using _strlwr_s of C++ standard lib\n.", __FUNCTION__);

    _strlwr_s(const_cast<char*>(strTest.c_str()), strTest.size() + 1);
    _wcslwr_s(const_cast<wchar_t*>(wcsTest.c_str()), wcsTest.size() + 1);

    wprintf(L"result of to lower for wstring: %s\n", wcsTest.c_str());
    printf("result of to lower for string: %s\n", strTest.c_str());

    _strupr_s(const_cast<char*>(strTest.c_str()), strTest.size() + 1);
    _wcsupr_s(const_cast<wchar_t*>(wcsTest.c_str()), wcsTest.size() + 1);

    wprintf(L"result of to upper for wstring: %s\n", wcsTest.c_str());
    printf("result of to upper for string: %s\n\n", strTest.c_str());

}

void TestStrToUpperLower2()
{
    string strTest = ".jWS";
    wstring wcsTest = L".jWS";

    printf("%s using transform of algorithm\n.", __FUNCTION__);

    transform(strTest.begin(), strTest.end(), strTest.begin(), ::tolower);
    transform(wcsTest.begin(), wcsTest.end(), wcsTest.begin(), ::towlower);

    wprintf(L"result of to lower for wstring: %s\n", wcsTest.c_str());
    printf("result of to lower for string: %s\n", strTest.c_str());

    transform(strTest.begin(), strTest.end(), strTest.begin(), ::toupper);
    transform(wcsTest.begin(), wcsTest.end(), wcsTest.begin(), ::towupper);

    wprintf(L"result of to upper for wstring: %s\n", wcsTest.c_str());
    printf("result of to upper for string: %s\n\n", strTest.c_str());

}


void TestWcsMemCpy()
{
    //  TODO先暂时判断这几个参数
    const wchar_t* strCat = L"标识数据";
    const wchar_t* strName = L"ID";
    //const wchar_t* strValue = prop->getValue();
    int lenCat = wcslen(strCat);
    int lenName = wcslen(strName);
    //int lenValue = wcslen(strValue);
    unsigned int length = lenCat + lenName /*+ lenValue*/;
    wchar_t* hash = new wchar_t[length + 1];
    memcpy(hash, strCat, lenCat * 2);
    memcpy(hash + lenCat, strName, lenName * 2);
    //memcpy(hash, strValue, lenValue * 2);
    hash[length] = L'\0';
}

void Test3()
{
    float fValue = -3.3f;
    int nValue = (int)fValue;

    wstring gzSource = L"d:\\123\\";
    size_t find = gzSource.find_last_of(L'\\');
    if (find == wstring::npos || find != gzSource.size() - 1)
        gzSource += L"\\inputfile.txt";

    bool bBreak = true;
}

void Test2()
{
    char dir[256] = "C:\\Users\\heuwz\\Desktop\\新建文件夹\\PKPM\\20191031\\";

    char dir2[_MAX_PATH];
    int len = strlen(dir);
    strncpy(dir2, dir,  len - 1);
    int len2 = strlen(dir2);
    dir2[len - 1] = '\0';
    bool bbreak = true;
}

void testChar()
{
   char* strToken = "1500.000";
   int nValue;
   int nRe = sscanf_s(strToken, "%d", &nValue);
   double dValue;
   int dRe = sscanf_s(strToken, "%lf", &dValue);

   //

	char test[5] = "1234";
	string strTest(test, 3);

	//
	char* str = "12345";
	char* str2 = "\"12345\"";
	int size = strlen(str) + 3;
	char* strRe = new char[size];
	strRe[0] = '\"';
	for (int i = 0; i < size - 3; ++i)
	{
		strRe[i + 1] = str[i];
	}

	strRe[size - 2] = '\"';
	strRe[size - 1] = '\0';

	bool bRe = false;
}

