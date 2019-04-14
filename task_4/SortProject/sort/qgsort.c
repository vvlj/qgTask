#include "../inc/qgsort.h"
#include    <stdio.h>
void insertSort(int *a,int n)
{
    int i,j;
    int temp;  //����һ����ʱ���������ڽ�������ʱ�洢
    for (i = 1; i < n; i++)// ѭ���ӵڶ�������Ԫ�ؿ�ʼ
    {
        temp = a[i];//temp���Ϊδ����ĵ�һ��Ԫ��
        j = i -1;
        while (j >= 0 && a[j] > temp) //��temp��������Ԫ�شӴ�С�Ƚϣ�Ѱ��tempӦ�����Ԫ��
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        //print(a,n);     //ʵʱ���
    }

}

void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    if(begin >= end)return;
    int begin1 = begin, end1 = mid;                     //��һ����
    int begin2 = mid + 1, end2 = end;                   //�ڶ�����
    if(((end1 -begin1)>> 1 )!=- 1)
        MergeArray(a,begin1,((end1 -begin1)>> 1) +begin1,end1,temp);    //mid =����2
    if((end2 -begin2)>> 1 !=- 1)
        MergeArray(a,begin2,((end2 -begin2)>> 1) +begin2,end2,temp);
    int k =begin;
    while(begin1 <= end1 && begin2 <= end2)
    {
        temp[k++] = a[begin1] < a[begin2] ? a[begin1++] : a[begin2++];  //�����ֵ���С�ıȽ�
    }
    while(begin1 <= end1)            //������while����һ��û��ִ��
    {
        temp[k++] = a[begin1++];
    }
    while(begin2 <= end2)            //������while����һ��û��ִ��
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

//�������򣨵ݹ�棩
void QuickSort_Recursion(int *a, int begin, int end)
{
    if(begin >= end) return;
    int board =a[begin];    //��һ����
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
    a[begin] = a[p1];   //���һ��������Ԫ��
    a[p1] = board;
    QuickSort_Recursion(a,begin,p1-1);  //���
    QuickSort_Recursion(a,p1+1,end); //�ҷ�
}

//�������򣨷ǵݹ�棩
void QuickSort(int *a,int size)
{
    int stack[40];  //���Ϊ40��ջ
    int point = -1; //ָ��ջ��
    stack[++point] = 0;
    stack[++point] = size-1;
    int begin,end,p1,p2,board;
    while(point !=-1)
    {
        end = stack[point--];
        begin =stack[point--];
        if(begin >= end)continue;   //�൱��return
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
        a[begin] = a[p1];   //���һ��������Ԫ��
        a[p1] = board;
        printf("%d",p1);
        stack[++point] = begin; //���
        stack[++point] = p1-1;
        stack[++point] = p1+1;
        stack[++point] = end;   //�ҷ�
    }
}

//�������������ţ�
int Partition(int *a, int begin, int end)
{
    if(begin >= end)return;
    int board = a[begin];   //��
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
    if(left > right)     //����
        left = right;
    if(a[left] == board) //��ͬ
        left--;
    a[begin] = a[left];
    a[left] = board;
    Partition(a,begin,left-1);
    Partition(a,left+1,end);
}

//��������
void CountSort(int *a, int size , int max)
{
    int countArr[max];
    for(int i = 0;i<max;i++)
        countArr[i] =0;             //��ʼ��
    for(int i = 0;i < size; i++)
        countArr[a[i]]++;           //ͳ��
    for (int i = 1; i < max; i++)
        countArr[i] += countArr[i - 1]; //ͳ���ۼ�
    for (int i = size; i > 0; i--)
        a[--countArr[a[i - 1]]] = a[i - 1]; //����
}

//��������
void RadixCountSort(int *a,int size)
{
    int i, b[20], maxVal = a[0], exp = 1;   //b[
    for (i = 1; i < size; i++)     //���ֵ
        if (a[i] > maxVal)
            maxVal = a[i];

    while (maxVal / exp > 0)
    {
        int bucket[10] = { 0 };
        for (i = 0; i < size; i++)
        {
            bucket[(a[i] / exp) % 10]++;    //ͳ��
        }
        for (i = 1; i < 10; i++)
        {
            bucket[i] += bucket[i - 1];     //�ۼ�
        }
        for (i = size - 1; i >= 0; i--)
        {
            b[--bucket[(a[i] / exp) % 10]] = a[i];
        }
        for (i = 0; i < size; i++)
        {
            a[i] = b[i];        //����
        }
        exp *= 10;
    }
}

//��ɫ����
void ColorSort(int *a,int size)
{
    int left=0,right =size -1,p;
	while(a[left]==0 && left<size)  //����0
        left++;
	while(a[right]==2 && right>=0)    //����2
        right--;
	p=left;     //p��left��λ�ÿ�ʼ����
	while(p<=right)
	{
		if(a[p]==1)
			p++;
		else if(a[p]==0)
        {
            a[p] = a[left];     //����
            a[left] =0;
            while(a[left]==0 && left<size)  //����0
                left++;
        }
		else
        {
            a[p] = a[right--];
            while(a[right]==2 && right>=0)    //����2
                right--;
        }

    }
}

void findKth(int *a,int begin, int end,int k)
{
    int board =a[begin];    //��һ����
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
    findKth(a,begin,p1-1,k);    //�����Ѱ��
    if(p1+1 <k)
    findKth(a,p1+1,end,k-p1-1);          //���ұ�Ѱ��
    if(p1+1 ==k)
    printf("%d",a[p1]);     //����ûд�˳���־
}
