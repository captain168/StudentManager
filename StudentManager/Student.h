#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct Major{
	char name[30];
	char property[30];
}major;//����רҵ���ݽṹ����
typedef struct Teacher{
	char name[30];
	int age;
	int  sex;
}teacher;//�ον�ʦ���ݽṹ����
typedef struct Course{
	char name[30];
	int score;
    teacher t;
	struct Course *nextcourse;
}course;//�γ����ݽṹ����
typedef struct Student{
	char name[30];
	int age;
	int sex;
	int grades;
	int classes;
	course *c;
	major m;
}student;//ѧ�����ݽṹ����

