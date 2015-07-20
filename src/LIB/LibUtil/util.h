#ifndef UTIL_H
#define UTIL_H

class util
{
public:

	void UTF_8ToUnicode(wchar_t* pOut,char *pText);  // ��UTF-8ת����Unicode
	void UnicodeToUTF_8(char* pOut,wchar_t* pText);  //Unicode ת����UTF-8
	void UnicodeToGB2312(char* pOut,wchar_t uData);  // ��Unicode ת���� GB2312
	void Gb2312ToUnicode(wchar_t* pOut,char *gbBuffer);// GB2312 ת���ɡ�Unicode
	void GB2312ToUTF_8(std::string& pOut,char *pText, int pLen);//GB2312 תΪ UTF-8
	void UTF_8ToGB2312(std::string &pOut, char *pText, int pLen);//UTF-8 תΪ GB2312
	WCHAR* AnsiToUnicode( const char* szStr );//char to wchar
	char* UnicodeToAnsi( const WCHAR* szStr );//wchar to char
	char* UnicodeToUTF8( const WCHAR* szStr );//wchar to utf8
	wchar_t* Utf8ToUnicode(const char* utf);//utf8 to wchar
	char* intTOStirng(const int n);
	char* DoubleTOString(const double n);
	int StringToInt(const char* src);
	double StringTODouble(const char* src);
	
};

#endif // UTIL_H
