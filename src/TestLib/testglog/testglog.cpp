// testglog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include "glog/logging.h"*/
#include "util.h"

using namespace std;
/*using namespace google;*/
int main(int argc, char** argv)
{
	util u ;
	std::string src = "{\"a\":12,\"c\":[\"a\":1,\"b\:0]}";
	bool a = u.CheckFormatJson(src);
	std::cout<<a<<std::endl;
// 	google::InitGoogleLogging("");  
// 	FLAGS_servitysinglelog = true;// �������յȼ�����log�ļ�
// 	google::SetLogDestination(google::GLOG_FATAL, "d:\\temp\\log_fatal_"); // ���� google::FATAL �������־�洢·�����ļ���ǰ׺
// 	google::SetLogDestination(google::GLOG_ERROR, "d:\\temp\\log_error_"); //���� google::ERROR �������־�洢·�����ļ���ǰ׺
// 	google::SetLogDestination(google::GLOG_WARNING, "d:\\temp\\log_warning_"); //���� google::WARNING �������־�洢·�����ļ���ǰ׺
// 	google::SetLogDestination(google::GLOG_INFO, "d:\\temp\\log_info_"); //���� google::INFO �������־�洢·�����ļ���ǰ׺
// 	FLAGS_logbufsecs = 0; //������־�����Ĭ��Ϊ30�룬�˴���Ϊ�������
// 	FLAGS_max_log_size = 100; //�����־��СΪ 100MB
// 	FLAGS_stop_logging_if_full_disk = true; //�����̱�д��ʱ��ֹͣ��־���
// 	// ������־·��  INFO WARNING ERROR FATAL    
// 	// ...    
// 	char str[202] = "�й�jkkasjfkjkasjlfkjsakljflksjadf!";    
// 	LOG(INFO) << "Found " << google::COUNTER <<endl;    
// 	LOG(INFO) << str ;//<< " cookies";    
// 	LOG(WARNING) << "warning test";  // �����һ��Warning��־    
// 	LOG(ERROR) << "error test";//�����һ��Error��־    

	return 0;  
}

