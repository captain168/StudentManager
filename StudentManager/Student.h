#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma once
typedef struct Major{
	char name[30];
	char properties[30];
}major;//����רҵ���ݽṹ����
typedef struct Teacher{
	char name[30];
	char sex[10];
}teacher;//�ον�ʦ���ݽṹ����
typedef struct Course{
	char name[30];
	int score;
    teacher myteacher;
	struct Course *nextcourse;
}course;//�γ����ݽṹ����
typedef struct Student{
	char name[30];
	char num[20];
	char sex[10];
	int grades;
	int classes;
	major mymajor;
	course *mycourse;
}student;//ѧ�����ݽṹ����
