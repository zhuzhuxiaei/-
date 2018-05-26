#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE* f;
	FILE* f2;
	f=fopen("topo","r");
	f2=fopen("node.txt","w");
	char* buf=(char*)malloc(sizeof(char)*8);
	char* buf2;
	int num;
	int num2;
	int count=0;
	fgets(buf,8,f);
	printf("%s\n",buf);
	num=atoi(buf);
	memset(buf,0,8);
	int node[num][num];
	for(int i=0;i<=99;i++){
		for(int j=0;j<=99;j++){
			node[i][j]=0;
		}
	}
	while(fgets(buf,8,f)!=NULL){	
		buf2=buf+2;
		printf("%s",buf);
		num=atoi(buf);
		num2=atoi(buf2);
		printf("---%d---\n---%d---\n",num,num2);
		memset(buf,0,8);
		if(node[num][num2]){
			//原先已被置位， 
		}else{
			node[num][num2]=1;
			node[num2][num]=1;
		}
	}
	fclose(f);
	for(int i=0;i<=99;i++){
		count=0;
		for(int j=0;j<=99;j++){
			if(node[i][j]){
				count++; 
			}
		}
		memset(buf,0,8);
		printf("i -- %d \n",i);
		printf("count -- %d\n",count);
		itoa(i,buf,10);
		printf("string  %s\n",buf);
		printf("string2 %s\n",buf2);
	}
	fclose(f2);
	return 0;
}
