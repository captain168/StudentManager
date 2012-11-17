// StudentManager.cpp : 定义控制台应用程序的入口点。
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
	signal(SIGABRT,abort_sig);//注册程序崩溃处理程序
	//创建基本的录入数据结构
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

