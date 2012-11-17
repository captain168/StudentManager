#include "stdafx.h"
#include "StudentIO.h"
#include "readfile.h"
#include <iostream>
using namespace std;
int read_from_buff(char *buff,char *c,int startptr,int size){
	if((sizeof(buff)-startptr)>(unsigned)size){
		return 0;
	}
	buff=buff+startptr;
	while(true){
		size--;
		*c=*buff;
		c++;
		buff++;
		if(size==0){
			break;
		}
	}
	*c='\0';
	return 1;
}
int read_from_file(student *stu,char *filename,char *mode){
	FILE *fp;
	int err;
	err=fopen_s(&fp,filename,mode);
	if(err!=0){
		return 0;
	}
	err=fread(stu,sizeof(student),1,fp);
	fclose(fp);
	return 1;
}