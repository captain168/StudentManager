#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "test.h"
using namespace std;
#pragma once 
#define BUFFER_SIZE 130
#define INPUT_ERROR(result) if(result==0||result==EOF)return -1
#define error_over_length printf("你输入的字符串太长！请重新输入！")
#define error_illegal_character(limit) printf("您输入的分数字段的非法，\
		请重新输入一个小于limit的正数\n")
#define REINPUT(result,read,buff)  while(result==-1)\
        {printf("输入错误！请重新输入！\n");result=read(buff);}                        
#define ILLEGAL   printf("输入中含有非法字符！请重新输入！\n")
#define TEACHER printf("%-15s%-15s%-15s\n\n","任课教师","性别")
#define PRINT_TEACHER printf("%-15s%-15s\n\n",myteacher->name,\
		myteacher->sex)
#define MAJOR printf("%-15s%-15s%\n\n","专业","专业性质")
#define PRINT_MAJOR printf("%-15s%-15s\n\n",mymajor->name,mymajor->properties)
#define COURSE  printf("%-15s%-15s%-15s%-15s\n\n","任课教师","性别",\
		"课程名","所得分数")
#define PRINT_COURSE printf("%-15s%-15s%-15s%-15d\n\n",\
			mycourse->myteacher.name,mycourse->myteacher.sex,\
			mycourse->name,mycourse->score)
#define STUDENT printf_s("%-15s%-15s%-15s%-15s%-15s\n\n","姓名","学号",\
		"性别","年级","班级")
#define PRINT_STUDENT  printf_s("%-15s%-15s%-15s%-15d%-15d\n\n",\
		stu->name,stu->num,&(stu->sex),(stu->grades),(stu->classes))
void abort_sig(int sig);
void printteacher(teacher *myteacher);
void printmajor(major *mymajor);
void printcourse(course *mycourse);
void printstudent(student *mystudent);
int readteacher(teacher *myteacher);
int readmajor(major *mymajor);
int readcourse(course *mycourse);
int readstudent(student *mystudent);
int getSize(char *c);
int isillegalCharacter(char *c);
int writetofile(student *stu);
int readtofile(student *stu);
void input_student(student *stu);