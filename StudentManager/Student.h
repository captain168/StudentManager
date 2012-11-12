#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct Major{
	char name[30];
	char property[30];
}major;//主修专业数据结构定义
typedef struct Teacher{
	char name[30];
	int age;
	int  sex;
}teacher;//任课教师数据结构定义
typedef struct Course{
	char name[30];
	int score;
    teacher t;
	struct Course *nextcourse;
}course;//课程数据结构定义
typedef struct Student{
	char name[30];
	int age;
	int sex;
	int grades;
	int classes;
	course *c;
	major m;
}student;//学生数据结构定义

