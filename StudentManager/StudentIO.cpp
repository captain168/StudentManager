#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <ctype.h>
#include "StudentIO.h"
#include "test.h"
using namespace std;
void abort_sig(int sig){
	printf("��������ˣ�������������\n");
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
		printf("�������ον�ʦ������:\n");
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
		printf("�������ον�ʦ���Ա�\n");
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
		if(strcmp(myteacher->sex,"��")&&strcmp(myteacher->sex,"Ů")){
			printf("���������룡�Ա�ֻ�����л�Ů.\n");
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
		printf("����������רҵ:\n");
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
		printf("������רҵ����\n");
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
		printf("������γ���:\n");
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
		printf("������γ̷���:\n");
		result=scanf_s("%d",&(mycourse->score));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(mycourse->score<0||mycourse->score>10000){
			printf("������ķ����ֶεķǷ�������������һ������\n");
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
		printf("����������:\n");
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
		printf("������ѧ��:\n");
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
				printf("�����������֣����������룡\n");
				size=-1;
				break;
			}
		}
		if(size==-1)
			continue;
		if(mystudent->num<0){
			printf("�������������ѧ�ţ�������������\n");
			continue;
		}
		else{
			break;
		}
	}
	while(true){
		printf("�������Ա�:\n");
		result=scanf_s("%9s",mystudent->sex,_countof(mystudent->sex));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		size=getSize(mystudent->sex);
		if(size>8){
			error_over_length;
			continue;
		}
		if(strcmp(mystudent->sex,"��")!=0&&strcmp(mystudent->sex,"Ů")!=0){
			printf("�����������Ա��л�Ů��\n");
			continue;
		}
		else{
			break;
		}
	}
	while(true){
		printf("�������꼶:\n");
		result=scanf_s("%d",&(mystudent->grades));
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(mystudent->grades<0||mystudent->grades>100){
			printf("����������ݷǷ�������������С��100������\n");
			continue;
		}
		else{
			break;
		}
	}
	while(true){
		printf("������༶:\n");
		result=scanf_s("%d",&(mystudent->classes));		
		while((c=getchar())!='\n'&&c!=EOF);
		INPUT_ERROR(result);
		if(mystudent->classes<0){
			printf("����������ݷǷ�������������һ������!\n");
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
		if((*c>0&&*c<65)||(*c>90&&*c>122)){//����ǲ��������ַ�
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
	int coursenum=0;//�γ���
	int result;
	/*¼��ѧ��������
	*/
	printf("����������������ѧ�š��Ա��꼶���༶��\n");
	result=readstudent(stu);
	REINPUT(result,readstudent,stu);
	printf("���������޵�רҵ��רҵ����:\n");
	result=readmajor(m);
	REINPUT(result,readmajor,m);
	while(true){
		printf("��������ѡ�޵Ŀγ�����\n");
		scanf_s("%d",&coursenum);
		if(coursenum<0||coursenum>19){
			printf("����������ݷǷ������������룡\n");
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
		printf("������γ����֡��γ̳ɼ�:\n");
		courses[i]=(course*)malloc(sizeof(course));
		result=readcourse(courses[i]);
		REINPUT(result,readcourse,courses[i]);
		printf("�������ο���ʦ���������Ա�\n");
		result=readteacher(t);
		REINPUT(result,readteacher,t);
		courses[i]->myteacher=*t;
		lastcourse->nextcourse->nextcourse=courses[i];//��courses[i]��Ϊlast
		lastcourse->nextcourse=courses[i];//����lastָ��
		if(i==coursenum-1){
			courses[i]->nextcourse=NULL;
		}

	}
	stu->mycourse=firstcourse->nextcourse;
	stu->mymajor=mymajor;
}