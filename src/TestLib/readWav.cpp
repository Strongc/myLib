// readWav.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#if 0
#include "stdlib.h"
#include "stdio.h"


int main()
{
	int i;   //����ѭ������
	unsigned char ch[100];  //�����洢wav�ļ���ͷ��Ϣ
	FILE *fp;

	if((fp=fopen("1.wav","rb"))==NULL) //�����ļ�ʧ�ܣ��˳�
	{
		printf("can't open this file\n");
		exit(0);
	}

	/**********���wav�ļ���������Ϣ**********/
	printf("��wav�ļ���������Ϣ:");
	for(i=0;i<58;i++)
	{
		ch[i]=fgetc(fp); //ÿ�ζ�ȡһ���ַ�����������ch��
		if(i%16==0)      //ÿ�����16���ַ���Ӧ��ʮ��������
			printf("\n");
		if(ch[i]<16)     //��С��16��������ǰ���0��ʹ����8bit��ʾ����
			printf("0%x ",ch[i]);   
		else
			printf("%x ",ch[i]);
	}

	/*********RIFF WAVE Chunk�����*********/
	printf("\n\nRIFF WAVE Chunk��Ϣ:");
	//���RIFF��־
	printf("\nRIFF��־:");
	for(i=0;i<4;i++)
	{
		printf("%x ",ch[i]);
	}

	//���size��С
	printf("\nsize:ox");
	for(i=7;i>=4;i--) //���ֽڱ�ʾ��ֵ��λ�����ֽڱ�ʾ��ֵ��λ
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	//���WAVE��־
	printf("\nWAVE��־:");
	for(i=8;i<12;i++)
	{
		if(ch[i]<16)
			printf("0%x ",ch[i]);
		else
			printf("%x ",ch[i]);
	}

	/*******Format Chunk�����*******/
	printf("\n\nFormat Chunk��Ϣ:");
	//���fmt ��־
	printf("\nfmt ��־:");
	for(i=12;i<16;i++)
	{
		if(ch[i]<16)
			printf("0%x ",ch[i]);
		else
			printf("%x ",ch[i]);
	}

	//���size�� 
	printf("\nsize:ox");
	for(i=19;i>15;i--)
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	//������뷽ʽ
	printf("\n���뷽ʽ:ox");
	for(i=21;i>19;i--)
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	//���������Ŀ
	printf("\n������Ŀ:ox");
	for(i=23;i>21;i--)
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	if(ch[i+1]==1)   //1��ʾ��������2��ʾ˫����
		printf(" ������");
	else
		printf(" ˫����");

	//�������Ƶ�� 
	printf("\n����Ƶ��:ox");
	for(i=27;i>23;i--)
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	//���ÿ�������ֽ��� 
	printf("\nÿ�������ֽ���:ox");
	for(i=31;i>27;i--)
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	//������ݿ���뵥λ 
	printf("\n���ݿ���뵥λ:ox");
	for(i=33;i>31;i--)
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	//���ÿ����������bit�� 
	printf("\nÿ����������bit��:ox");
	for(i=35;i>33;i--)
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	//���������Ϣ
	if(ch[16]==18)  //��Format Chunk��size��СΪ18�����ģ�����������ֽ�Ϊ������Ϣ
	{               //��Ϊ16�����޸�����Ϣ
		printf("\n������Ϣ:ox");
		for(i=37;i>35;i--)
		{
			if(ch[i]<16)
				printf("0%x",ch[i]);
			else
				printf("%x",ch[i]);
		}
	}

	/*******Fact Chunk�����*******/
	printf("\n\nFact Chunk��Ϣ:");
	//���fact��־ 
	printf("\nfact��־:");
	for(i=38;i<42;i++)
	{
		if(ch[i]<16)
			printf("0%x ",ch[i]);
		else
			printf("%x ",ch[i]);
	}

	//���size 
	printf("\nsize:ox");
	for(i=45;i>41;i--)
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	//���data������
	printf("\ndata������:");
	for(i=46;i<50;i++)
	{
		if(ch[i]<16)
			printf("0%x ",ch[i]);
		else
			printf("%x ",ch[i]);
	}

	/*******Data Chunk�����*******/
	printf("\n\nData Chunk��Ϣ:");
	//���data��־
	printf("\ndata��־:");
	for(i=50;i<54;i++)
	{
		if(ch[i]<16)
			printf("0%x ",ch[i]);
		else
			printf("%x ",ch[i]);
	}

	//������ݴ�С
	printf("\n���ݴ�С:ox");
	for(i=57;i>53;i--)
	{
		if(ch[i]<16)
			printf("0%x",ch[i]);
		else
			printf("%x",ch[i]);
	}

	printf("\n");

	fclose(fp);
}

#else 

#include <STDIO.H>
#include <STDLIB.H>
#include <WINDOWS.H>
#include <TIME.H>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

typedef UCHAR Uint8;
typedef UCHAR uint8_t;
typedef USHORT Uint16;
typedef USHORT uint16_t;
typedef UINT32 Uint32;
typedef UINT32 uint32_t;

typedef struct _WavBuffer{
	Uint8* wav_buffer;//���ݻ���
	Uint32 wav_length;//���ݻ����С
	Uint8* wav_pos;//����λ��
	Uint32 wav_lastlength;//ʣ�����ݴ�С
}WavBuffer;
typedef struct _WAVE_FORMAT{
	uint16_t	wFormatTag;//��ʽһ��PCM,1
	uint16_t	nChannels;//������mono 1 ������ stereo 2 ˫����
	uint32_t	nSamplesPerSec;//������(ÿ�������) ���� 11.025 kHz,22.05  kHz,44.1   kHz,48     kHz,96     kHz
	uint32_t   nAvgBytesPerSec;//ƽ��ÿ���ֽ��� ������*������*����λ��/8
	uint16_t    nBlockAlign;//�����ֽ� ������*����λ��/8 (������8bit 1Byte ˫����16bit 4Byte)
	uint16_t    wBitsPerSample;//����λ��8bit 16bit
}WAVE_FORMAT;
//��Wav�ļ���ȡ���ݷ�����Ƶ��ʽ�����ݣ����ݳ���,0������-1����
int ReadWavFromFile(const char*filename,WAVE_FORMAT*format,uint8_t**buffer,uint32_t*length);

DWORD CALLBACK waveOutProc(HWAVEOUT hwo,UINT uMsg,DWORD dwInstance,DWORD dwParam1,DWORD dwParam2);
//ÿ�β��Ż����С
#define PLAYBUFFERLENGTH 16384

//ʹ��sndPlaySound�������ļ�����
#define USE_PLAYSOUND_FROM_FILE 0

#define WAVEHDR_NUM 2

int main(int args,char**argv){
	WavBuffer wavbuff={0};
	WAVE_FORMAT waveFormat={0};
	WAVEFORMATEX waveFormatEx={0};
	HWAVEOUT    hWaveOut=NULL;
	WAVEHDR hdr[WAVEHDR_NUM]={0};
	const char *filename="1.wav";
	int i=0;
	//sndPlaySound�����ļ�,�����ο�PlaySound
	//SND_SYNCͬ�����ţ�SND_ASYNC�첽����
#if USE_PLAYSOUND_FROM_FILE
	printf("���ļ���������!\n");
	sndPlaySound(filename,SND_SYNC);
#else

	if(ReadWavFromFile(filename,&waveFormat,&wavbuff.wav_buffer,&wavbuff.wav_length)==0){
		printf("��ȡ�ɹ�!\n");
		printf("��Ƶ����:%s(%hu)\n",waveFormat.wFormatTag==1?"PCM":"??",waveFormat.wFormatTag);
		printf("������:%hu \n",waveFormat.nChannels);
		printf("������:%u Hz\n",waveFormat.nSamplesPerSec);
		printf("λ��:%u bps\n",waveFormat.nAvgBytesPerSec*8);
		printf("�����ֽ�:%hu byte\n",waveFormat.nBlockAlign);
		printf("����λ��:%u bit\n",waveFormat.wBitsPerSample);
		printf("���ݴ�С:%u\n",wavbuff.wav_length);
		printf("Ԥ��ʱ��:%u s\n",wavbuff.wav_length/(waveFormat.nSamplesPerSec*waveFormat.nChannels*waveFormat.wBitsPerSample/8));
	}else{
		printf("��ȡʧ��!\n");
		return -1;
	}
	printf("Ĭ�Ϸ�����������!\n");
	memcpy(&waveFormatEx,&waveFormat,sizeof(WAVE_FORMAT));
	printf("��Ƶ����豸����:%u\n",waveOutGetNumDevs());
	if(waveOutOpen(&hWaveOut,0,&waveFormatEx,(DWORD)(waveOutProc),0,CALLBACK_FUNCTION)!=0){
		printf("����Ƶ�豸����\n");
		goto exit;
	}
	wavbuff.wav_pos=wavbuff.wav_buffer;
	wavbuff.wav_lastlength=wavbuff.wav_length;
	//׼����Ƶ������
	for(i=0;i<WAVEHDR_NUM;i++){
		hdr[i].dwBufferLength=PLAYBUFFERLENGTH;
		hdr[i].lpData=(LPSTR)wavbuff.wav_pos;
		hdr[i].dwUser=(DWORD_PTR)&wavbuff;
		wavbuff.wav_pos+=PLAYBUFFERLENGTH;
		wavbuff.wav_lastlength-=PLAYBUFFERLENGTH;
		waveOutPrepareHeader(hWaveOut,&hdr[i],sizeof(WAVEHDR));
	}
	//д����
	for(i=0;i<WAVEHDR_NUM;i++){
		waveOutWrite(hWaveOut,&hdr[i],sizeof(WAVEHDR));
	}

	while(wavbuff.wav_lastlength>0){
		Sleep(100);
	}
	waveOutPause(hWaveOut);
	//�ͷ�����
	for(i=0;i<WAVEHDR_NUM;i++){
		waveOutUnprepareHeader(hWaveOut,&hdr[i],sizeof(WAVEHDR));
	}

	waveOutClose(hWaveOut);
exit:
	free(wavbuff.wav_buffer);
#endif
	return 0;
}

DWORD CALLBACK waveOutProc(HWAVEOUT hwo,UINT uMsg,DWORD dwInstance,DWORD dwParam1,DWORD dwParam2){
	WAVEHDR*pHDR=(WAVEHDR*)dwParam1;
	switch (uMsg){
	case WOM_OPEN:
		printf("WOM_OPEN\n");
		break;
	case WOM_CLOSE:
		printf("WOM_CLOSE\n");
		break;
	case WOM_DONE:{
		WavBuffer*pwavbuff=NULL;
		int templength=0;			
		pwavbuff=(WavBuffer*)pHDR->dwUser;
		templength=pwavbuff->wav_lastlength<PLAYBUFFERLENGTH?pwavbuff->wav_lastlength:PLAYBUFFERLENGTH;
		pHDR->lpData=(LPSTR)pwavbuff->wav_pos;
		pHDR->dwBufferLength=templength;
		pwavbuff->wav_pos+=templength;
		pwavbuff->wav_lastlength-=templength;
		waveOutWrite(hwo,pHDR,sizeof(WAVEHDR));
				  }
				  break;
	default:
		printf("%x\n",uMsg);
	}
	return 0;
}

typedef struct _RIFF_HEADER{
	uint32_t RiffID;//'RIFF'
	uint32_t RiffSize;//�ļ��ܳ���-8
	uint32_t RiffFormat;//����'WAVE'
}RIFF_HEADER;
typedef struct _BLOCK_HEADER{
	uint32_t BlockID;//'fmt ' 'fact' 'Data'
	uint32_t BlockSize;//
}BLOCK_HEADER;
#define MAKETAG(a,b,c,d)   ((a&0xff)|((b<<8)&(0xff00))|((c<<16)&(0xff0000))|((d<<24)&(0xff000000)))

int ReadWavFromFile(const char*filename,WAVE_FORMAT*format,uint8_t**buffer,uint32_t*length){
	RIFF_HEADER Riff_Header={0};
	BLOCK_HEADER BlockHeader={0};
	uint32_t dataPos=0;
	uint32_t dataSize=0;
	FILE*fp=fopen(filename,"rb");
	if(fp==NULL)
		return -1;
	fread(&Riff_Header,1,sizeof(Riff_Header),fp);
	//���WAVE��ǩ
	if((Riff_Header.RiffID==MAKETAG('R','I','F','F'))&&(Riff_Header.RiffFormat==MAKETAG('W','A','V','E'))){
		printf("����WAV�ļ�\n");
	}else{
		printf("�ⲻ��WAV�ļ�\n");
		fclose(fp);
		return -1;
	}
	while(fread(&BlockHeader,1,sizeof(BlockHeader),fp)==sizeof(BlockHeader)){
		//		printf("BlockID:%0.4s BlockSize:%u\n",(char*)&(BlockHeader.BlockID),BlockHeader.BlockSize);
		//��ȡ��ʽ��Ϣ
		if(BlockHeader.BlockID==MAKETAG('f','m','t',' ')){
			uint32_t Pos=ftell(fp);
			fread(format,1,sizeof(WAVE_FORMAT),fp);
			fseek(fp,Pos,SEEK_SET);
		}
		//��ȡ������Ϣ
		if(BlockHeader.BlockID==MAKETAG('d','a','t','a')){
			dataPos=ftell(fp);
			dataSize=BlockHeader.BlockSize;
		}
		if(BlockHeader.BlockSize>0){
			fseek(fp,BlockHeader.BlockSize,SEEK_CUR);
		}else{
			break;
		}
	}
	if(dataSize>0){
		fseek(fp,dataPos,SEEK_SET);
		*buffer=(uint8_t*)malloc(dataSize*sizeof(uint8_t));
		*length=dataSize;
		fread(*buffer,1,dataSize,fp);
	}
	fclose(fp);
	return dataSize>0?0:-1;
}
#endif