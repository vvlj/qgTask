#include "../inc/qgsort.h"
#include    <stdio.h>
void insertSort(int *a,int n)
{
    int i,j;
    int temp;  //定义一个临时变量，用于交换数据时存储
    for (i = 1; i < n; i++)// 循环从第二个数组元素开始
    {
        temp = a[i];//temp标记为未排序的第一个元素
        j = i -1;
        while (j >= 0 && a[j] > temp) //将temp与已排序元素从大到小比较，寻找temp应插入的元素
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        //print(a,n);     //实时输出
    }

}

void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    if(begin >= end)return;
    int begin1 = begin, end1 = mid;                     //第一部分
    int begin2 = mid + 1, end2 = end;                   //第二部分
    if(((end1 -begin1)>> 1 )!=- 1)
        MergeArray(a,begin1,((end1 -begin1)>> 1) +begin1,end1,temp);    //mid =整除2
    if((end2 -begin2)>> 1 !=- 1)
        MergeArray(a,begin2,((end2 -begin2)>> 1) +begin2,end2,temp);
    int k =begin;
    while(begin1 <= end1 && begin2 <= end2)
    {
        temp[k++] = a[begin1] < a[begin2] ? a[begin1++] : a[begin2++];  //两部分的最小的比较
    }
    while(begin1 <= end1)            //这两个while总有一个没有执行
    {
        temp[k++] = a[begin1++];
    }
    while(begin2 <= end2)            //这两个while总有一个没有执行
    {
        temp[k++] = a[begin2++];
    }
    for(k=begin;k<=end;k++)
        a[k] = temp[k];
}

void MergeSort(int *a,int begin,int end,int *temp)
{
    MergeArray(a,begin,(end-begin) >> 1,end,temp);
}

//快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end)
{
    if(begin >= end) return;
    int board =a[begin];    //找一个板
    int p1=begin,p2=begin+1;
    while(p2<=end)
    {
        if(a[p2] < board)
        if(p1+1 != begin)
        {
            a[begin] = a[++p1];
            a[p1] = a[p2];
            a[p2] = a[begin];
        }
        p2++;
    }
    a[begin] = a[p1];   //最后一个交换的元素
    a[p1] = board;
    QuickSort_Recursion(a,begin,p1-1);  //左分
    QuickSort_Recursion(a,p1+1,end); //右分
}

//快速排序（非递归版）
void QuickSort(int *a,int size)
{
    int stack[40];  //深度为40的栈
    int point = -1; //指向栈顶
    stack[++point] = 0;
    stack[++point] = size-1;
    int begin,end,p1,p2,board;
    while(point !=-1)
    {
        end = stack[point--];
        begin =stack[point--];
        if(begin >= end)continue;   //相当于return
        board =a[begin];
        p1 = begin;
        p2 =begin + 1;
        while(p2<=end)
        {
            if(a[p2] < board)
                if(p1!=begin)
                {
                    a[begin] = a[++p1];
                    a[p1] = a[p2];
                    a[p2] = a[begin];
                }
                else{p1++;}
            p2++;
        }
        a[begin] = a[p1];   //最后一个交换的元素
        a[p1] = board;
        printf("%d",p1);
        stack[++point] = begin; //左分
        stack[++point] = p1-1;
        stack[++point] = p1+1;
        stack[++point] = end;   //右分
    }
}

//快速排序（枢轴存放）
int Partition(int *a, int begin, int end)
{
    if(begin >= end)return;
    int board = a[begin];   //板
    int left =begin+1,right =end;
    while(left < right)
    {
        while(a[left] < board && left < right)
            left++;
        while(a[right] >= board && left < right)
            right--;
        a[begin] = a[left];
        a[left] = a[right];
        a[right] = a[begin];
    }
    if(left > right)     //交叉
        left = right;
    if(a[left] == board) //相同
        left--;
    a[begin] = a[left];
    a[left] = board;
    Partition(a,begin,left-1);
    Partition(a,left+1,end);
}

//计数排序
void CountSort(int *a, int size , int max)
{
    int countArr[max];
    for(int i = 0;i<max;i++)
        countArr[i] =0;             //初始化
    for(int i = 0;i < size; i++)
        countArr[a[i]]++;           //统计
    for (int i = 1; i < max; i++)
        countArr[i] += countArr[i - 1]; //统计累计
    for (int i = size; i > 0; i--)
        a[--countArr[a[i - 1]]] = a[i - 1]; //分配
}

//基数排序
void RadixCountSort(int *a,int size)
{
    int i, b[20], maxVal = a[0], exp = 1;   //b[
    for (i = 1; i < size; i++)     //最大值
        if (a[i] > maxVal)
            maxVal = a[i];

    while (maxVal / exp > 0)
    {
        int bucket[10] = { 0 };
        for (i = 0; i < size; i++)
        {
            bucket[(a[i] / exp) % 10]++;    //统计
        }
        for (i = 1; i < 10; i++)
        {
            bucket[i] += bucket[i - 1];     //累计
        }
        for (i = size - 1; i >= 0; i--)
        {
            b[--bucket[(a[i] / exp) % 10]] = a[i];
        }
        for (i = 0; i < size; i++)
        {
            a[i] = b[i];        //分配
        }
        exp *= 10;
    }
}

//颜色排序
void ColorSort(int *a,int size)
{
    int left=0,right =size -1,p;
	while(a[left]==0 && left<size)  //不是0
        left++;
	while(a[right]==2 && right>=0)    //不是2
        right--;
	p=left;     //p从left的位置开始遍历
	while(p<=right)
	{
		if(a[p]==1)
			p++;
		else if(a[p]==0)
        {
            a[p] = a[left];     //交换
            a[left] =0;
            while(a[left]==0 && left<size)  //不是0
                left++;
        }
		else
        {
            a[p] = a[right--];
            while(a[right]==2 && right>=0)    //不是2
                right--;
        }

    }
}

void findKth(int *a,int begin, int end,int k)
{
    int board =a[begin];    //找一个板
    int p1=begin,p2=begin+1;
    while(p2<=end)
    {
        if(a[p2] < board)
            if(p1+1 != begin)
        {
            a[begin] = a[++p1];
            a[p1] = a[p2];
            a[p2] = a[begin];
        }
        p2++;
    }
    if(p1+1 >k)
    findKth(a,begin,p1-1,k);    //从左边寻找
    if(p1+1 <k)
    findKth(a,p1+1,end,k-p1-1);          //从右边寻找
    if(p1+1 ==k)
    printf("%d",a[p1]);     //这里没写退出标志
}
