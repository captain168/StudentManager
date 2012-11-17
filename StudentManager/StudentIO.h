#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "test.h"
using namespace std;
#pragma once 
#define BUFFER_SIZE 130
#define INPUT_ERROR(result) if(result==0||result==EOF)return -1
#define error_over_length printf("��������ַ���̫�������������룡")
#define error_illegal_character(limit) printf("������ķ����ֶεķǷ���\
		����������һ��С��limit������\n")
#define REINPUT(result,read,buff)  while(result==-1)\
        {printf("����������������룡\n");result=read(buff);}                        
#define ILLEGAL   printf("�����к��зǷ��ַ������������룡\n")
#define TEACHER printf("%-15s%-15s%-15s\n\n","�ον�ʦ","�Ա�")
#define PRINT_TEACHER printf("%-15s%-15s\n\n",myteacher->name,\
		myteacher->sex)
#define MAJOR printf("%-15s%-15s%\n\n","רҵ","רҵ����")
#define PRINT_MAJOR printf("%-15s%-15s\n\n",mymajor->name,mymajor->properties)
#define COURSE  printf("%-15s%-15s%-15s%-15s\n\n","�ον�ʦ","�Ա�",\
		"�γ���","���÷���")
#define PRINT_COURSE printf("%-15s%-15s%-15s%-15d\n\n",\
			mycourse->myteacher.name,mycourse->myteacher.sex,\
			mycourse->name,mycourse->score)
#define STUDENT printf_s("%-15s%-15s%-15s%-15s%-15s\n\n","����","ѧ��",\
		"�Ա�","�꼶","�༶")
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