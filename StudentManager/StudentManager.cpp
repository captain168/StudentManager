// StudentManager.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "StudentIO.h"
#include "writefile.h"
#include "readfile.h"
#include <iostream>
#include <signal.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	signal(SIGABRT,abort_sig);//ע���������������
	//����������¼�����ݽṹ
	student *stu;
	student mystudent;
	stu=&mystudent;
	char *mode="wb";
	char *filename;
	filename=stu->num;
	input_student(stu);
	printstudent(stu);
	write_to_file(stu,filename,mode);
	mode="rb";
	student teststu;
	stu=&teststu;
	read_from_file(stu,filename,mode);
	printstudent(stu);
	return 0;
}

