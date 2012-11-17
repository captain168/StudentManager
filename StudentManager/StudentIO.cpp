#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <ctype.h>
#include "StudentIO.h"
#include "test.h"
using namespace std;
void abort_sig(int sig){
	printf("程序崩溃了！请重新启动！\n");
}
//print teacher information
void printteacher(teacher *myteacher){
	TEACHER;
	PRINT_TEACHER;
}
void printmajor(major *mymajor){
	MAJOR;
	PRINT_MAJOR;
}
//print all of course for the student information
void printcourse(course *mycourse){
	COURSE;
	while(mycourse!=NULL){
		PRINT_COURSE;
		mycourse=mycourse->nextcourse;
	}
}
void printstudent(student *stu){
	STUDENT;
	PRINT_STUDENT;
	printcourse(stu->mycourse);
	printmajor(&(stu->mymajor));
}
int readteacher(teacher *myteacher){
	int result;
	char c;
	int size;
	while(true){
		printf("请输入任课教师的姓名:\n");
		result=scanf_s("%29s",myteacher->name,_countof(myteacher->name));
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(isillegalCharacter(myteacher->name)){
			ILLEGAL;
			continue;
		}
		size=getSize(myteacher->name);
		if(size>20){
			error_over_length;
			continue;
		}
		else{
			break;
		}
	}
	while(true){
		printf("请输入任课教师的性别：\n");
		result=scanf_s("%9s",myteacher->sex,_countof(myteacher->sex));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		size=getSize(myteacher->sex);
		if(size>8){
			error_over_length;
			continue;
		}
		if(isillegalCharacter(myteacher->sex)){
			ILLEGAL;
			continue;
		}
		if(strcmp(myteacher->sex,"男")&&strcmp(myteacher->sex,"女")){
			printf("请重新输入！性别只能是男或女.\n");
			continue;
		}
		else{
			break;
		}
	}
	return 0;
}
int readmajor(major *mymajor){
	int result;
	char c;
	int size;
	while(true){
		printf("请输入主修专业:\n");
		result=scanf_s("%29s",mymajor->name,_countof(mymajor->name));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(isillegalCharacter(mymajor->name)){
			ILLEGAL;
			continue;
		}
		size=getSize(mymajor->name);
		if(size>20){
			error_over_length;
			continue;
		}		
		else{
			break;
		}
	}
	while(true){
		printf("请输入专业性质\n");
		result=scanf_s("%29s",mymajor->properties,_countof(mymajor->properties));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(isillegalCharacter(mymajor->properties)){
			ILLEGAL;
			continue;
		}
		size=getSize(mymajor->properties);
		if(size>20){
			error_over_length;
			continue;
		}
		else{
			break;
		}		
	}
	return 0;
}
int readcourse(course *mycourse){
	int result;
	char c;
	int size;
	while(true){
		printf("请输入课程名:\n");
		result=scanf_s("%29s",mycourse->name,_countof(mycourse->name));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(isillegalCharacter(mycourse->name)){
			ILLEGAL;
			continue;
		}
		size=getSize(mycourse->name);
		if(size>20){
			error_over_length;
			continue;
		}
		else{
			break;
		}
	}
	while(true){
		printf("请输入课程分数:\n");
		result=scanf_s("%d",&(mycourse->score));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(mycourse->score<0||mycourse->score>10000){
			printf("您输入的分数字段的非法，请重新输入一个正数\n");
			continue;
		}
		else{
			break;
		}
	}
	return 0;
}
int readstudent(student *mystudent){
	int result;
	char c;
	int size;
	while(true){
		printf("请输入姓名:\n");
		result=scanf_s("%29s",mystudent->name,_countof(mystudent->name));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(isillegalCharacter(mystudent->name)){
			ILLEGAL;
			continue;
		}
		size=getSize(mystudent->name);
		if(size>20){
			error_over_length;
			continue;
		}
		else{
			break;
		}
	}
	while(true){
		printf("请输入学号:\n");
		result=scanf_s("%19s",mystudent->num,_countof(mystudent->num));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		size=getSize(mystudent->num);
		if(size>18){
			error_over_length;
			continue;
		}
		for(int i=0;i<sizeof(mystudent->num);i++){
			if(mystudent->num[i]=='\0'){
				break;
			}
			if((mystudent->num[i])<48||(mystudent->num[i])>57){
				printf("必须输入数字，请重新输入！\n");
				size=-1;
				break;
			}
		}
		if(size==-1)
			continue;
		if(mystudent->num<0){
			printf("请重新输入你的学号，你输入正数！\n");
			continue;
		}
		else{
			break;
		}
	}
	while(true){
		printf("请输入性别:\n");
		result=scanf_s("%9s",mystudent->sex,_countof(mystudent->sex));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		size=getSize(mystudent->sex);
		if(size>8){
			error_over_length;
			continue;
		}
		if(strcmp(mystudent->sex,"男")!=0&&strcmp(mystudent->sex,"女")!=0){
			printf("请重新输入性别，男或女！\n");
			continue;
		}
		else{
			break;
		}
	}
	while(true){
		printf("请输入年级:\n");
		result=scanf_s("%d",&(mystudent->grades));
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(mystudent->grades<0||mystudent->grades>100){
			printf("你输入的数据非法，请重新输入小于100的整数\n");
			continue;
		}
		else{
			break;
		}
	}
	while(true){
		printf("请输入班级:\n");
		result=scanf_s("%d",&(mystudent->classes));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(mystudent->classes<0){
			printf("你输入的数据非法，请重新输入一个正数!\n");
			continue;
		}
		else{
			break;
		}
	}
	return 0;
}
int getSize(char *c){
	int size=0;
	while(*c!='\0'){
		size++;
		c++;
	}
	return size;
}
int isillegalCharacter(char *c){
	while(*c!='\0'){
		if((*c>0&&*c<65)||(*c>90&&*c>122)){//检查是不是其它字符
			return 1;
		}
		c++;
	}
	return 0;
}
void input_student(student *stu){
	major *m;
	teacher *t;
	major mymajor;
	course mycourse;
	teacher myteacher;
	course *firstcourse;
	course *lastcourse;
	m=&mymajor;
	firstcourse=&mycourse;
	t=&myteacher; 
	int coursenum=0;//课程数
	int result;
	/*录入学生的数据
	*/
	printf("请输入您的姓名、学号、性别、年级、班级：\n");
	result=readstudent(stu);
	REINPUT(result,readstudent,stu);
	printf("请输入主修的专业、专业性质:\n");
	result=readmajor(m);
	REINPUT(result,readmajor,m);
	while(true){
		printf("请输入您选修的课程数：\n");
		scanf_s("%d",&coursenum);
		if(coursenum<0||coursenum>19){
			printf("你输入的数据非法，请重新输入！\n");
			scanf_s("%d",&coursenum);
			continue;
		}
		else{
			break;
		}
	}
	course *courses[20];
	firstcourse=(course*)malloc(sizeof(course));
	lastcourse=(course*)malloc(sizeof(course));
	lastcourse->nextcourse=firstcourse;
	for(int i=0;i<coursenum;i++){
		printf("请输入课程名字、课程成绩:\n");
		courses[i]=(course*)malloc(sizeof(course));
		result=readcourse(courses[i]);
		REINPUT(result,readcourse,courses[i]);
		printf("请输入任课老师的姓名、性别：\n");
		result=readteacher(t);
		REINPUT(result,readteacher,t);
		courses[i]->myteacher=*t;
		lastcourse->nextcourse->nextcourse=courses[i];//让courses[i]成为last
		lastcourse->nextcourse=courses[i];//保存last指针
		if(i==coursenum-1){
			courses[i]->nextcourse=NULL;
		}

	}
	stu->mycourse=firstcourse->nextcourse;
	stu->mymajor=mymajor;
}