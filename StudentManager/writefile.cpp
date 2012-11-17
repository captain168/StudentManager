#include "stdafx.h"
#include "StudentIO.h"
#include "writefile.h"
#include <iostream>
#include <string.h>
using namespace std;
int write_to_buff(char *buff,char *c){
	int buffsize=0;
	while(buff!='\0'){
		buffsize++;
		buff++;
	}
	if((sizeof(buff)-buffsize)<sizeof(c)){
		return 0;
	}
	strcat_s(buff,sizeof(buff),c);
	return 1;
}
int write_to_file(student *stu,char *filename,char *mode){
	FILE *fp;
	int err;
	err=fopen_s(&fp,filename,mode);
	if(err!=0){
		return 0;
	}
	if(stu==NULL){
		return 0;
	}
	err=fwrite(stu,sizeof(student),1,fp);
	while(stu->mycourse!=NULL){	
		err=fwrite(stu->mycourse,
			sizeof(course),1,fp);
		if(err==0) return 0;
		stu->mycourse=stu->mycourse->nextcourse;
	}
	fclose(fp);
	return 1;
	
}