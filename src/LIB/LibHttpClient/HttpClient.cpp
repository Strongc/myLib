#include "StdAfx.h"
#include "HttpClient.h"
#include "WinHttpClient.h"
#include "util.h"


HttpClient::HttpClient(void)
{
}


HttpClient::~HttpClient(void)
{
}

int HttpClient::clientGet(IN std::string url,
	OUT std::string &ResponseHeader,OUT std::string &ResponseContent,
	IN std::string UserAgent/*=""*/,IN std::string Proxy/*=""*/,IN std::string Cookies/*=""*/)
{
	// Set URL.
	WinHttpClient client(util::AnsiToUnicode(url.c_str()));

	if(!UserAgent.empty())
	{
		 client.SetUserAgent(util::AnsiToUnicode(UserAgent.c_str()));
	}
	if(!Proxy.empty())
	{
		client.SetProxy(util::AnsiToUnicode(Proxy.c_str()));
	}
	if(!Cookies.empty())
	{
		 client.SetAdditionalRequestCookies(util::AnsiToUnicode(Cookies.c_str()));
	}
	// Send http request, a GET request by default.
	client.SendHttpRequest();

	// The response header.
	wstring httpResponseHeader = client.GetResponseHeader();
	ResponseHeader = util::UnicodeToAnsi(httpResponseHeader.c_str());
	// The response content.
	wstring httpResponseContent = client.GetResponseContent();
	ResponseContent = util::UnicodeToAnsi(httpResponseContent.c_str());
	return 0;
}

int HttpClient::clinetPost(IN std::string url,IN std::string contentData,
	OUT std::string &ResponseHeader,OUT std::string &ResponseContent,
	IN std::string UserAgent/*=""*/,IN std::string Proxy/*=""*/,IN std::string Cookies/*=""*/)
{
	WinHttpClient client(util::AnsiToUnicode(url.c_str()));

	// Set post data.
	string data = contentData;
	if(!contentData.empty())
	{
		client.SetAdditionalDataToSend((BYTE *)data.c_str(), data.size());
	}
	if(!UserAgent.empty())
	{
		client.SetUserAgent(util::AnsiToUnicode(UserAgent.c_str()));
	}
	if(!Proxy.empty())
	{
		client.SetProxy(util::AnsiToUnicode(Proxy.c_str()));
	}
	if(!Cookies.empty())
	{
		client.SetAdditionalRequestCookies(util::AnsiToUnicode(Cookies.c_str()));
	}
	// Set request headers.
	wchar_t szSize[50] = L"";
	swprintf_s(szSize, L"%d", data.size());
	wstring headers = L"Content-Length: ";
	headers += szSize;
	headers += L"\r\nContent-Type: application/x-www-form-urlencoded\r\n";
	client.SetAdditionalRequestHeaders(headers);

	// Send http post request.
	client.SendHttpRequest(L"POST");

	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();

	ResponseHeader = util::UnicodeToAnsi(httpResponseHeader.c_str());
	ResponseContent = util::UnicodeToAnsi(httpResponseContent.c_str());
	return 0;
}