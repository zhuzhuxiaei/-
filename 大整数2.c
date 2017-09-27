/*大整数的加法，要求在主函数构造两个大整数，
且提前要求输入的个数*/ 
#include <stdlib.h>
#include <stdio.h>
typedef struct DA Node;
struct DA{
	int num;
	char fuhao;
	
};
int main()
{	Node *first,*second,*p,*longer,*shorter;
	int num1=0,num2=0;
	printf("第一个大整数有几个节点？每个节点四位！");
	scanf("%d",&num1);
	first=(Node*)malloc(sizeof(Node)*num1);//分配空间
 	printf("第二个大整数有几个节点？每个节点四位!");
 	scanf("%d",&num2);
 	second=(Node*)malloc(sizeof(Node)*num2);
 	//-------------------dajian----------------//
	p=first;
	fflush(stdin);//清除缓存中的回车符号 
	printf("请输入第一个数的符号");
	scanf("%c",&first->fuhao); 
	printf("%c",p->fuhao);
	int count=1; 
	while(true){
		
		printf("请输入第%d个节点的值",count);
		scanf("%4d",&p->num);
		p->fuhao=first->fuhao;
	
		if(count>=num1) break;		
	 	count++;
		p++;
		
		}
	//------------dajian2------------------//
	p=second;
	printf("请输入第二个数的符号\n");
	fflush(stdin);
	scanf("%c",&second->fuhao);
	printf("%c",p->fuhao);
	count=1;
	while(true){
		
		printf("请输入第%d个节点的值",count);
		scanf("%4d",&p->num);
		p->fuhao=second->fuhao;
	
		if(count>=num2) break;
		count++;
		p++;
	}

 	//搭建完毕
	//进行运算,先确定谁更长
	int times=0;//循环所需次数 
	int longernum=0,shorternum=0; 
	if(num1>=num2){
		longer=first;
		longernum=num1;
		shorter=second;
		shorternum=num2;
		times=num2; 
	}else{//需要注意，等长时longer是first 
		longer=second;
		longernum=num2;
		shorter=first;
		shorternum=num1;
		times=num1;
		
	}	 
 	//判别加减法
 
 
 

 
 	count=0;
 	if(first->fuhao=='-'){
	 	count++;
	 }

	if(second->fuhao=='-'){
		count++;
	}
	 
	
		
			
				
					
	if(count==0||count==2){
		printf("同号\n");
		Node*longerp=longer;
		Node*shorterp=shorter;
		for(;times>0;times--){
			longerp->num=longerp->num+shorterp->num;
			longerp++;
			shorterp++;			
		}
		//整理longer,对每一个节点进行检查，如果大于则进位 
		longerp=longer;
		const int longernumold=longernum;
		for(int i=1;;i++){
			if(i==longernumold&&longerp->num>9999){
				longerp->num=longerp->num-10000;
				longer=(Node*)realloc(longer,sizeof(Node)*++longernum);
				printf("longernum%d",longernum); 
				(longer+longernum-1)->fuhao=longer->fuhao;
				(longer+longernum-1)->num=1;
				
			} 
			if(longerp->num>9999){
				longerp->num=longerp->num-10000;
				(longerp+1)->num++;
				
			} 
			if(i==longernumold) break; 
			longerp++;
		} 
		//打印
		longerp=longer+longernum-1;
		printf("%c",longerp->fuhao);
		for(int i=1;;i++){
			printf(",%04d",longerp->num);
			if(i==longernum) break;
			longerp--;
			
		} 
	}
				






//-------------------------------------------------------------------------
 	if(count==1){
		printf("不同号\n"); 
		Node*longerp=longer;
		Node*shorterp=shorter;
 		//减法，如果不等长，那就好办了
		 if(num1!=num2){
		
			for(;;times--){
			longerp->num=longerp->num-shorterp->num;
			if(times==1) break;
			longerp++;
			shorterp++;			
			}
			//整理
			longerp=longer;
			for(int i=1;;i++){
				if(longerp->num<0){
					longerp->num=longerp->num+10000;
					(longerp+1)->num--;
				}
				if(i==longernum) break;
				longerp++;
			} 
			
 		} 
 		//减法，等长！
 		Node*temp; 
		if(num1==num2){
			//第一步是判断谁更大，先获得尾巴指针
			longerp=(longer+num1-1);
			shorterp=(shorter+num2-1);
			//从尾巴开始比较，判断谁更大，找到更大的然后退出
			for(int i=1;i<=num1;i++){
				if(longerp->num>shorterp->num){
					break; 
				}else if(longerp->num<shorter->num){
				//	longerp=shorter;
				//	shorterp=longer;
					temp=longer;
					longer=shorter;
					shorter=temp;
				
					break; 
				}else if(longerp->num==shorterp->num){
					if(longerp==longer){
					 printf("大小相等,结果为0"); return 0;
					 }
					longerp--;
					shorterp--;
				}
			} 
			
			
			//计算 
			longerp=longer;
			shorterp=shorter;
			for(;;times--){
				longerp->num=longerp->num-shorterp->num;
				if(times==1) break;
				longerp++;
				shorterp++;			
			}
			//整理
			longerp=longer;
			for(int i=1;;i++){//因为是等长，且是减法，所以这里
			//循环次数不用考虑太多 
				if(longerp->num<0){
					longerp->num=longerp->num+10000;
					(longerp+1)->num--;
				}
				if(i==longernum) break;
				longerp++;
			} 
			
	 	
 	}
		//dayin
		longerp=longer+longernum-1;
		printf("%c",longerp->fuhao);
		for(int i=1;;i++){
			printf(",%04d",longerp->num);
			if(i==longernum) break;
			longerp--;
			
		} 
 	}
}
//在一个语句中不要出现太多运算符，否则很容易出错。 
