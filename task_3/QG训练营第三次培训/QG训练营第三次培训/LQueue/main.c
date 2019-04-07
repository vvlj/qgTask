#include <stdio.h>
#include <stdlib.h>
#include "../代码和头文件/头文件/._LQueue.h"
#include <string.h>
void choose();  //选择队列的类型
void showSqStackTable();    //界面显示函数
void SqStackTest(); //交互函数
Status ifInit(int destroyStatus);   //是否初始化

int main()
{
    SqStackTest();
    return 0;
}

void showSqStackTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("选择测试链队列功能\n");
    printf("        选项1：初始化\n");
    printf("        选项2：摧毁\n");
    printf("        选项3：压入\n");
    printf("        选项4：弹出\n");
    printf("        选项5：清空\n");
    printf("        选项6：判断栈是否为空\n");
    printf("        选项7：得到顶元素\n");
    printf("        选项8：检测长度\n");
    printf("        选项0:退出\n");
    printf("***************************\n");

}


void SqStackTest()
{
    int num,destroyStatus =1;                                       //选择功能、摧毁标志
    LQueue *test;
    int e;

    while(num)
    {
        showSqStackTable();
        if(!destroyStatus)
        {
            if(flag == 1)printf("当前队列类型为double\n");
            if(flag == 2)printf("当前队列类型为char\n");
            if(flag == 3)printf("当前队列类型为int\n");
            TraverseLQueue(test,LPrint);
            printf("\n***************************\n");
        }
        while(1)        //只能输入0-9
        {
            num =getchar();
            num -='0';
            if(num >-1 && num <10){
                getchar();
                break;
            }
        }

        switch(num)
        {
            case 1:{
                if(destroyStatus){
                    test = (LQueue*)malloc(sizeof(LQueue));            //分配内存
                    choose();
                    if(flag == 1)
                    {
                        test->length = sizeof(double);
                        double e;
                    }
                    if(flag == 2)
                    {
                        test->length = sizeof(char);
                        char e;
                    }
                    if(flag == 3)
                    {
                        test->length = sizeof(int);
                        int e;
                    }
                    InitLQueue(test);
                    printf("    初始化成功\n");
                    destroyStatus =0;
                    }
                }
                break;

            case 2:
                if(ifInit(destroyStatus))
                {
                    DestoryLQueue(test);
                    printf("    摧毁成功\n");
                    destroyStatus =1;
                }
                break;
            case 3:
                if(ifInit(destroyStatus))
                {
                    printf("输入一个值压入：\n");
                    if(flag == 1)scanf("%lf",&e);
                    if(flag == 2)scanf("%c",&e);
                    if(flag == 3)scanf("%d",&e);
                    getchar();
                    if(EnLQueue(test,&e))printf("    压入成功\n");
                    else{printf("    压入失败\n");}
                }
                break;
            case 4:
                if(ifInit(destroyStatus))
                {
                    if(DeLQueue(test))printf("    弹出成功\n");
                    else{printf("    弹出失败\n");}
                }
                break;
            case 5:
                if(ifInit(destroyStatus))
                {
                    ClearLQueue(test);
                    printf("    清空成功\n");
                }
                break;
            case 6:
                if(ifInit(destroyStatus))
                {
                    if(IsEmptyLQueue(test))printf("    为空\n");
                    else{printf("    不为空\n");}
                }
                break;
            case 7:
                if(ifInit(destroyStatus))
                {
                    if(GetHeadLQueue(test,&e)){
                    if(flag == 1)printf("    该元素是%f\n",e);
                    if(flag == 2)printf("    该元素是%c\n",e);
                    if(flag == 3)printf("    该元素是%d\n",e);
                    }
                    else{printf("    得到失败\n");}
                }
                break;
            case 8:
                if(ifInit(destroyStatus))
                {
                    int length;
                    length = LengthLQueue(test);
                    printf("    该栈长度%d\n",length);
                }
                break;
        }
        printf("按回车返回:");
        getchar();
        system("CLS");
    }
}


void choose()
{
    printf("    仅测以一下三种类型,默认为int：\n");
    printf("    输入1：double型\n");
    printf("    输入2：char型\n");
    printf("    输入3：int型\n");
    while(TRUE)        //只能输入0-9
        {
            flag =getchar();
            flag -='0';
            if(flag >0 && flag <4){
                getchar();
                break;
            }
        }
}

Status ifInit(int destroyStatus)
{
    if(destroyStatus){
        printf("        未初始化\n");
        return FALSE;
    }
    return TRUE;
}
