#include "VerifyFileInter.h"
#include "util.h"
#include <stdio.h>

#include "Algorithms/md5.h"
#include "Algorithms/sha1.h"
#include "Algorithms/sha256.h"
#include "Algorithms/crc32.h"




extern CRITICAL_SECTION g_criticalSection;


int API_TimeToStringEX(std::string &strDateStr, const __time64_t &timeData)
{
	char chTmp[100] = {'\0'};
	struct tm *p;
	p = localtime(&timeData);
	p->tm_year = p->tm_year + 1900;
	p->tm_mon = p->tm_mon + 1;

	sprintf(chTmp, "%04d-%02d-%02d %02d:%02d:%02d",
		p->tm_year, p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
	strDateStr = chTmp;
	return 0;
}

extern "C" DLL_EXPORT int getFileVerify(std::vector<std::string> &infile, std::vector<Result> &outre)
{
	__int64 finishedSize = 0;
	std::vector<__int64> fSizes(infile.size());
	std::string strFileSize;
	std::string strFileMD5;
	std::string strFileSHA1;
	std::string strFileSHA256;
	std::string strFileCRC32;

	//��ʼ����,ѭ������ÿ���ļ�
	for (int i = 0; i < infile.size(); i++)
	{
		// Declaration for calculator
		char* path = const_cast<char*>(infile[i].c_str());
		__int64 fsize = 0;
		finishedSize = 0;
		DataBuffer databuf;

		MD5_CTX mdContext; // MD5 context

		CSHA1 sha1; // SHA1 object
		char strSHA1[256];

		SHA256_CTX sha256Ctx; // SHA256 context
		std::string strSHA256 ="";

		unsigned long ulCRC32; // CRC32 context

		ResultData result;
		result.strPath = infile[i];
		//���ļ�
		FILE *fp = fopen(infile[i].c_str(), "rb+");
		if (fp != NULL)
		{
			//�ɹ����ļ�
			MD5Init(&mdContext, 0); // MD5��ʼ
			sha1.Reset(); // SHA1��ʼ
			sha256_init(&sha256Ctx); // SHA256��ʼ
			crc32Init(&ulCRC32); // CRC32��ʼ

			//��ȡ�ļ���Ϣ
			std::string lastModifiedTime;
			struct _stat64 info;
			_wstat64(AnsiToUnicode(infile[i].c_str()), &info);
			fsize = info.st_size;
			API_TimeToStringEX(lastModifiedTime, info.st_mtime);
			do
			{
				//��ȡ�ļ�
				databuf.datalen = fread(databuf.data, 1, DataBuffer::preflen, fp);

				MD5Update(&mdContext, databuf.data, databuf.datalen); // MD5����
				sha1.Update(databuf.data, databuf.datalen); // SHA1����
				sha256_update(&sha256Ctx, databuf.data, databuf.datalen); // SHA256����
				crc32Update(&ulCRC32, databuf.data, databuf.datalen); // CRC32����

				finishedSize += databuf.datalen;

				//����ƫ��
				if (databuf.datalen >= DataBuffer::preflen)
					_fseeki64(fp, finishedSize, SEEK_SET);
			} while (databuf.datalen >= DataBuffer::preflen);
			fclose(fp);//�ر��ļ�
			MD5Final(&mdContext); // MD5���
			sha1.Final(); // SHA1���
			sha256_final(&sha256Ctx); // SHA256���
			crc32Finish(&ulCRC32); //CRC32���

			//��ʽ��У����
			char _tempmd5[256] = { '\0' };
			sprintf(_tempmd5, "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
				mdContext.digest[0],
				mdContext.digest[1],
				mdContext.digest[2],
				mdContext.digest[3],
				mdContext.digest[4],
				mdContext.digest[5],
				mdContext.digest[6],
				mdContext.digest[7],
				mdContext.digest[8],
				mdContext.digest[9],
				mdContext.digest[10],
				mdContext.digest[11],
				mdContext.digest[12],
				mdContext.digest[13],
				mdContext.digest[14],
				mdContext.digest[15]);
			strFileMD5 = _tempmd5;
			sha1.ReportHash(strSHA1, CSHA1::REPORT_HEX);
			strFileSHA1 = (strSHA1);
			sha256_digest(&sha256Ctx, &strSHA256);
			strFileSHA256 = strSHA256;
			//strFileCRC32.Format(_T("%08X"), ulCRC32);
			char _tempcrc[128] = { '\0' };
			sprintf(_tempcrc, "%08X", ulCRC32);
			strFileCRC32 = _tempcrc;

			result.bDone = TRUE;
			result.strPath = infile[i];
			result.ulSize = fsize;
			result.strMDate = lastModifiedTime;
			// ��û��ת��ǰ��������Ǵ�д��
			result.strMD5 = strFileMD5;
			result.strSHA1 = strFileSHA1;
			result.strSHA256 = strFileSHA256;
			result.strCRC32 = strFileCRC32;
			//ת����Сд
		}
		else
		{
			result.bDone = FALSE;
			result.strError = "Open file error";			
		}

		outre.push_back(result);
	}
	return 0;
}
