#ifndef UTIL_H
#define UTIL_H

class util
{
	public:
#ifdef WIN32
		void readINIFileString(std::string path,std::string root,std::string userkey,std::string &uservalue,std::string def);
		void readINIFileInt(std::string path,std::string root,std::string userkey,int &userValue,int def);
		void writeINIFileString(std::string path,std::string root,std::string userkey,std::string value);
#endif
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
		char* intTOStirng(const int n);//int to char
		char* DoubleTOString(const double n);//double to char
		int StringToInt(const char* src); //char to int
		double StringTODouble(const char* src);// char to double
		std::vector<std::string> split(std::string &str,std::string &pattern);//ȡ�ָ���֮��Ķ���ַ�
		std::string GBKToUTF8(const std::string& strGBK); //gbk to utf8
		std::string UTF8ToGBK(const std::string& strUTF8);//utf8 to gbk
		void ReplaceSrc(std::string&s1,const std::string&s2,const std::string&s3);//��ѯ�滻�ַ���
		std::string Base64Encode(const unsigned char* Data,int DataByte);//����base64
		std::string Base64Decode(const char* Data,int DataByte,int& OutByte);//����base64
		std::string UrlEncode(const std::string& szToEncode);//����url ����
		std::string UrlDecode(const std::string& szToDecode);//����url ����
		bool CheckFormatJson(std::string src);//��֤json�Ƿ�Ϸ�
};



#endif // UTIL_H
