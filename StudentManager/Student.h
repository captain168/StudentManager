#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma once
typedef struct Major{
	char name[30];
	char properties[30];
}major;//主修专业数据结构定义
typedef struct Teacher{
	char name[30];
	char sex[10];
}teacher;//任课教师数据结构定义
typedef struct Course{
	char name[30];
	int score;
    teacher myteacher;
	struct Course *nextcourse;
}course;//课程数据结构定义
typedef struct Student{
	char name[30];
	char num[20];
	char sex[10];
	int grades;
	int classes;
	major mymajor;
	course *mycourse;
}student;//学生数据结构定义
