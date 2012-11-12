// StudentManager.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Student.h"
using namespace std;
//print Major information

void printmajor(major *mymajor){
	printf("%-29s%-29s%\n","专业","专业性质");
	printf("%-29s%-29s\n",mymajor->name,mymajor->property);
}
//print teacher information
void printteacher(teacher *myteacher){
	printf("%-29s%-29s%-29s\n","任课教师","年龄","性别");
	printf("%-19s%-29d%-29d\n",myteacher->name,_countof(myteacher->name),
		myteacher->age,myteacher->sex);
}
//print all of course for the student information
int printcourse(course *mycourse){
	while(mycourse->nextcourse!=NULL){
		printf("%-29s\n%29d\n",mycourse->name,_countof(mycourse->name),
			mycourse->score);
		printteacher(&(mycourse->t));
		mycourse=mycourse->nextcourse;
	}
	return 0;
}
int printstudent(student *stu){

	return 0;
}
int readteacher(teacher *myteacher){
	errno_t err;
	err=scanf_s("%29s%d%d",myteacher->name,_countof(myteacher->name),&(myteacher->age),&(myteacher->sex));
	if(err==EINVAL){
		printf("error\n");
		return -1;
	}
	return 0;
}
int readmajor(major *mymajor){
	errno_t err;
	err=scanf_s("%29s%29s",mymajor->name,_countof(mymajor->name)
		,mymajor->property,_countof(mymajor->property));
	if(err==EINVAL){
		printf("error\n");
		return -1;
	}
	return 0;
}
int readstudent(student *mystudent){
	errno_t err;
	return 0;
}
int readcourse(course *mycourse){
	errno_t err;
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//student *stu;
	major *m;
	course  *c;
	teacher *t;
	major mymajor;
	course mycourse;
	teacher myteacher;
	m=&mymajor;
	c=&mycourse;
	t=&myteacher;
	errno_t err;//define error 
	printf("please order input name of major,property:\n");
	readmajor(m);
	printf("please order input name ,age ,sex\n");
	readteacher(t);
	printteacher(t);
	printmajor(m);
	return 0;
}

