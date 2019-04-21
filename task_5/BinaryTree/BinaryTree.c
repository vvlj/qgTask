#include <stdlib.h>
#include "BinaryTree.h"
#include <stdio.h>

Status InitBiTree(BiTree *T)
{
    *T = (BiTree)malloc(sizeof(BiTNode));
    if(NULL == *T)return ERROR;
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
    return SUCCESS;
}

Status DestroyBiTree(BiTree *T)
{
    if(NULL == *T)return ERROR;
    free(*T);
    return SUCCESS;
}

//��������������ַ���definition
Status CreateBiTree(BiTree* T, char* definition)
{
    BiTree *stack[30],curNode;   //��Žṹ�����ָ���ջ
    int index=0;
    stack[index++] = T;
    while(index > 0)   //����һЩ
    {
        if(*definition != '\0' && *definition !='#')
        {
            curNode = (BiTree)malloc(sizeof(BiTNode));   //����ǰ�ڵ�����ڴ�
            *(stack[--index]) = curNode;       //����ָ��ָ��ǰ�ڵ�
            curNode->data = *definition;
            stack[index++] = &(curNode->lchild);
            stack[index++] = &(curNode->rchild);   //����ջ
        }
        else
        {
            *(stack[--index]) = NULL;
        }
        if(*definition !='\0')
            definition++;
    }

    /*
    if(*definition == NULL || *definition == '#')
    {
        *T = NULL;
        printf("%d\n    ",*T == NULL);
        return SUCCESS;
    }
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = *definition++;
    CreateBiTree(&(*T)->lchild,definition);
    CreateBiTree(&(*T)->rchild,definition);
    */

    /*
    (*T)->data = *definition++;
    (*T)->lchild = (*T)->rchild =NULL;
    if(*definition != '\0' && *definition != '#')
    {
        BiTree lchild = (BiTree)malloc(sizeof(BiTNode)); //��ʼ���ӽڵ�
        if(lchild == NULL)return ERROR;     //�ڴ����
        (*T)->lchild = lchild;
        CreateBiTree(&(*T)->lchild,definition);
    }
    if(*definition != '\0' && *definition != '#')
    {
        BiTree rchild = (BiTree)malloc(sizeof(BiTNode)); //��ʼ���ӽڵ�
        if(rchild == NULL)return ERROR;     //�ڴ����
        (*T)->rchild = rchild;
        CreateBiTree(&(*T)->rchild,definition);
    }
    */
    return SUCCESS;
}

// �������
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T ==NULL)return ERROR;
    (*visit)(T->data);                               //����ǰ��
    PreOrderTraverse(T->lchild,visit);
    PreOrderTraverse(T->rchild,visit);
    return SUCCESS;
}

// �������
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T ==NULL)return ERROR;
    PreOrderTraverse(T->lchild,visit);
    (*visit)(T->data);              //���м�
    PreOrderTraverse(T->rchild,visit);
    return SUCCESS;
}

// �������
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL )return ERROR;
    PreOrderTraverse(T->lchild,visit);
    PreOrderTraverse(T->rchild,visit);
    (*visit)(T->data);               //�������
    return SUCCESS;
}

// ��α���
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    int size =100;
    BiTree curNode;
    BiTree queue[size];   //��Žṹָ��Ķ���
    int start=0,end = 0;
    queue[end++] = T;

    while(start != end)   //����һЩ
    {
        curNode = queue[(start++)%size];
        if(curNode !=NULL)  //����ǿ�
        {
            (*visit)(curNode->data);
            queue[(end++)%size] = curNode->lchild;
            queue[(end++)%size] = curNode->rchild;   //����
        }

    }
}

//ǰ׺���ʽ
int Value(BiTree T)
{
    if(T ==NULL)return 0;
    int l =Value(T->lchild);
    int r =Value(T->rchild);
    switch(T->data)
    {
        case '+':return l + r;
        case '-':return l - r;
        case '*':return l * r;
        case '/':return l / r;
        default:return (int)(T->data - '0');   //���ֵ����
    }
}

