#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../inc/qgsort.h"

void showTable();
void test();
int getDigit(); //获取数字
void print(int *arr,int length);    //数组
void clr();
int initArr(int *arr,int length);

int main()
{
    test();
    return 0;
}


void showTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("选择测试功能\n");
    printf("        选项1：插入排序\n");
    printf("        选项2：归并排序\n");
    printf("        选项3：归并排序\n");
    printf("        选项4：快速排序（递归版）\n");
    printf("        选项5：快速排序（非递归版）\n");
    printf("        选项6：快速排序（枢轴存放）\n");
    printf("        选项7：计数排序\n");
    printf("        选项8：基数计数排序\n");
    printf("        选项9：颜色排序\n");
    printf("        选项0:初始化\n");
    printf("        选项11退出\n");
    printf("***************************\n");
}

void test()
{
    int num =1;                                       //选择功能、摧毁标
    int length;
    printf("请输入数组的长度：\n");
    length =getDigit();
    int *arr =(int*)malloc(sizeof(int)*length);
    initArr(arr,length);
    while(num != 11 )
    {
        clr();
        showTable();
        print(arr,length);
        printf("\n***************************\n");
        num =getDigit();
        switch(num)
        {
            case 12:
            {
                free(arr);
                printf("请输入数组的长度：\n");
                length =getDigit();
                int *arr =(int*)malloc(sizeof(int)*length);
                initArr(arr,length);
                break;
            }
            case 1:
                insertSort(arr,length);
                break;
            case 2:
            {
                int temp[length];
                MergeSort(arr,0,length-1,temp);
                break;
            }
            case 4:
                QuickSort_Recursion(arr,0,length-1);
                break;
            case 5:
                QuickSort(arr,length);
                break;
            case 6:
                Partition(arr,0,length-1);
                break;
            case 7:
                CountSort(arr,length,100);
                break;
            case 8:
                RadixCountSort(arr,length);
                break;
            case 9:
                ColorSort(arr,length);
                break;
            case 3:
                {
                    printf("请输入k的值：\n");
                    int num =getDigit();
                    findKth(arr,0,length-1,num);
                }
        }

    }
}


int getDigit()
{
    char num[20];
    gets(num);
    return atoi(num);   //异常返回0

}

void print(int *arr,int length)
{
    for(int i = 0;i < length;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void clr()
{
    printf("按回车返回:");
    getchar();
    system("CLS");
}

int initArr(int *arr,int length)
{
    printf("初始化数组：\n");
    for(int i = 0;i<length;i++)
    {
        arr[i] = getDigit();
    }
}
