#include <stdio.h>
#include <stdlib.h>
typedef struct DA da;
typedef struct TANKINFO tankInfo;
struct DA{
	int num_of_war;
	int time_of_last_war;
	int* pnum_of_tank;
	int* ptime_of_war;	 
};
struct TANKINFO{
    int numoftank;
    int numoffactory;
}
int main(){
	da* da1=createDA();	
}
da* createDA(){
	da* da1=(da*)malloc(sizeof(da));
	printf("请输入cru的挑战波数，cru淘淘的反击秒数.\n"); 
	scanf("%d %d",&da1->num_of_war,&da1->time_of_last_war);
	da1->pnum_of_tank=(int*)malloc(sizeof(int)*da1->num_of_war);
	da1->ptime_of_war=(int*)malloc(sizeof(int)*da1->num_of_war);
	for(int i=0;i<da1->num_of_war;i++){//先时间 后坦克数量 
		scanf("%d %d",&(*(da1->ptime_of_war)),&(*(da1->pnum_of_tank)));
		da1->ptime_of_war++;
		da1->pnum_of_tank++;
	}
	return da1;
} 
int tkgame(da* da1,int time_of_best){ 
	
}
int getTime(int n){
	return n=n/2;//返回最好的设置 
}
//choose==0生产factory,choose==1生产坦克 
/*正向递归*/
int digui(int mycengshu,tankInfo* lasttankinfo,int lastprinciple,int prefer,int best){
    //这个问题难在大量剪枝,prefer在不停变化。我们需要维护这个prefer
    int nextcengshu=cengshu+1;
    int myprinciple=0;
    tankInfo* mytankinfo;
    //虚拟搭建这一层
    myprinciple=suitPrinciple(prefer,mycengshu);
    mytankinfo=generate(lasttankinfo,myprinciple);
    //搭建完毕
    warInfo* warinfo=timeHeap();
    if(nextcengshu==warinfo->time){
        ---------------------------------------------------------------------------------------------------------
        if(nextcengshu>=prefer){
            temptanknum=mytankinfo->numoftank+mytankinfo->numoffactory;
            if(temptanknum>=warinfo->numoftank){
                //一切正常，进行下一个战争处理。
            }else{
                //数量不够，我们必须修改本层策略，因为下一层策略已经是最适应战争的策略了。
                mytankinfo=backGenerate(mytankinfo,myprinciple);
                mytankinfo=generate(mytankinfo,1);//强制增加战争能力
                int abletomake=((warinfo->time)-mycengshu)*(mytankinfo->numoffactory);
                if((mytankinfo->numoftank+abletomake>=warinfo->numoftank){
                    //修改本层策略可达到目标
                    //我们将直接跳到战争之后的一层进行递归
                }else{
                    return -1;//告知上一层，我们并未能达到目标，需要上一层进行额外工作。
                }
            }
        }
        ---------------------------------------------------------------------------------------------------------
        nextprinciple=suitPrinciple(prefer,nextcengshu);
        temptanknum=mytankinfo->
    }else{//下一层并无特别，只需要按照prefer进行操作。
        int signal==digui(mycengshu,tankInfo* mytankinfo,myprinciple,prefer);    
        if(signal==-1){
            //-1代表下层求救，我们需要把这一层的principle强制改为迎战模式。
            //但是回应求救需要有要求，即本层比best大,best目的是剪枝。(需要注意的是，局部prefer并不严谨，但绝不会出错
            //，目的只是大概率剪枝)
            //best在上一层策略与局部prefer中选取较大值，较大值才可达到剪枝目的。
            //对于下一个plan，我们建立在本plan基础之上，如果下一个plan不能通过，则修改本plan。达到回溯剪枝的目的
            //需要在此维护一个全局变量，或者在函数中传递参数，关于策略问题。
            if(mycengshu>=best){
                mytankinfo=backGenerate(mytankinfo,myprinciple);
                mytankinfo=generate(mytankinfo,1);
                int abletomake((warinfo->time)-mycengshu)*(mytankinfo->numoffactory);
            }
        }
        
    }
} 
int timeHeap(){
    //返回栈的顶部。

}
tankInfo* generate(tankInfo* lasttankinfo,int principle){
    if(principle){
        lasttankinfo->numoftank+=lasttankinfo->numoffactory;
    }else{
        lasttankinfo->numoffactory++;
    }
    return lasttankinfo;
}
tankInfo* backGenerate(tankInfo* tankinfo,int lastprinciple){
    if(lastprinciple){
        tankinfo->numoftank-=tankinfo->numoffactory;
    }else{
        tankinfo->numoffactory--;
    }
    return tankinfo;
}
int suitPrinciple(int prefer,int cengshu){
    if(cengshu>prefer) return 1;
    else return 0;
}
int generateTank(int factory){
    
}
int getPrefer(){

}
