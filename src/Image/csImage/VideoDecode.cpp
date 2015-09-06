#include "stdafx.h"
#include "VideoDecode.h"

namespace cs
{
	VideoDecode::VideoDecode(void)
		:mCapture(NULL)
		,frame_count(0)
		,mw(0)
		,mh(0)
		,md(0)
		,mc(0)
	{
	}
	VideoDecode::~VideoDecode(void)
	{
		ReleaseOperCV();
	}

	int VideoDecode::initVideoOpenCVOperate()
	{
		mVideoInfo.height = 0;
		mVideoInfo.width = 0;
		mVideoInfo.VIDuration = 0;
		frame_count = 0;
		mw=0,mh=0,md =0,mc=0;
		if(mCapture)
			cvReleaseCapture(&mCapture);
		return 0;
	}

	int VideoDecode::openVideoOpenCVFile(char* paht)
	{
		frame_count = 0;
		mCapture = cvCreateFileCapture(paht);  //��ȡ��Ƶ
		if(mCapture==NULL) 
		{
			return -1;
		}   

		double frames=cvGetCaptureProperty(mCapture,CV_CAP_PROP_FRAME_COUNT);//��ȡ��Ƶ���ж���֡
		IplImage * frame;
		frame = cvQueryFrame(mCapture);//ץȡ֡
		FillVideoInfo(frames,frame->width,frame->height,frame->nChannels,frame->depth);
		mw = frame->width;
		mh = frame->height;
		md = frame->depth;
		mc = frame->nChannels;
		return 0;
	}

	IplImage* VideoDecode::getVideoOpenCVFrame(int conut)
	{
		cvSetCaptureProperty(mCapture, CV_CAP_PROP_POS_FRAMES, conut);//������Ƶ֡�Ķ�ȡλ��
		IplImage * frame1;
		frame1 = cvQueryFrame(mCapture);//ץȡ֡
		if(frame1 == NULL)
			return NULL;
		else
			return frame1;	
	}

	void VideoDecode::ReleaseOperCV()
	{
		if(mCapture!=NULL)
			cvReleaseCapture(&mCapture);
	}

	double VideoDecode::getVideoFrameTime()
	{
		double _tepFrameTime =0.0;
		if(mCapture)
			_tepFrameTime =cvGetCaptureProperty(mCapture, CV_CAP_PROP_POS_MSEC );   //��ȡ��Ƶ��֡��
		return _tepFrameTime;
	}

	double VideoDecode::getVideoFrameCount()
	{
		double _tempFrameCout=0.0;
		if(mCapture)
			_tempFrameCout = cvGetCaptureProperty(mCapture,CV_CAP_PROP_FRAME_COUNT);//��ȡ��Ƶ���ж���֡
		return _tempFrameCout;
	}

	bool VideoDecode::FillVideoInfo(double duration,int width, int height,int Channels,int d)
	{
		mVideoInfo.width = width;
		mVideoInfo.height = height;
		mVideoInfo.VIDuration = duration;
		mVideoInfo.Channels = Channels;
		mVideoInfo.depthi = d;
		double _fps=cvGetCaptureProperty(mCapture, CV_CAP_PROP_FPS );   //��ȡ��Ƶ��֡��
		int _vfps = 1000 / _fps;                                        //����ÿ֡���ŵ�ʱ��
		mVideoInfo.vfps = _vfps;
		mVideoInfo.fps = _fps;
		return 0;
	}

	double VideoDecode::getVideoFrameInfo(int &w,int &h,int &d,int &c)
	{
		w = mw;
		h = mh;
		d = md;
		c = mc;
		double _fps =0.0;
		if(mCapture)
			_fps=cvGetCaptureProperty(mCapture, CV_CAP_PROP_FPS );   //��ȡ��Ƶ��֡��
		return _fps;
	}

}

