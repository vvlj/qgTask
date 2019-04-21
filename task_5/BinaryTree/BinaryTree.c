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

//二叉树先序遍历字符串definition
Status CreateBiTree(BiTree* T, char* definition)
{
    BiTree *stack[30],curNode;   //存放结构体二级指针的栈
    int index=0;
    stack[index++] = T;
    while(index > 0)   //考虑一些
    {
        if(*definition != '\0' && *definition !='#')
        {
            curNode = (BiTree)malloc(sizeof(BiTNode));   //给当前节点分配内存
            *(stack[--index]) = curNode;       //二级指针指向当前节点
            curNode->data = *definition;
            stack[index++] = &(curNode->lchild);
            stack[index++] = &(curNode->rchild);   //加入栈
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
        BiTree lchild = (BiTree)malloc(sizeof(BiTNode)); //初始化子节点
        if(lchild == NULL)return ERROR;     //内存错误
        (*T)->lchild = lchild;
        CreateBiTree(&(*T)->lchild,definition);
    }
    if(*definition != '\0' && *definition != '#')
    {
        BiTree rchild = (BiTree)malloc(sizeof(BiTNode)); //初始化子节点
        if(rchild == NULL)return ERROR;     //内存错误
        (*T)->rchild = rchild;
        CreateBiTree(&(*T)->rchild,definition);
    }
    */
    return SUCCESS;
}

// 先序遍历
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T ==NULL)return ERROR;
    (*visit)(T->data);                               //放最前面
    PreOrderTraverse(T->lchild,visit);
    PreOrderTraverse(T->rchild,visit);
    return SUCCESS;
}

// 中序遍历
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T ==NULL)return ERROR;
    PreOrderTraverse(T->lchild,visit);
    (*visit)(T->data);              //放中间
    PreOrderTraverse(T->rchild,visit);
    return SUCCESS;
}

// 后序遍历
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL )return ERROR;
    PreOrderTraverse(T->lchild,visit);
    PreOrderTraverse(T->rchild,visit);
    (*visit)(T->data);               //放最后面
    return SUCCESS;
}

// 层次遍历
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    int size =100;
    BiTree curNode;
    BiTree queue[size];   //存放结构指针的队列
    int start=0,end = 0;
    queue[end++] = T;

    while(start != end)   //考虑一些
    {
        curNode = queue[(start++)%size];
        if(curNode !=NULL)  //如果非空
        {
            (*visit)(curNode->data);
            queue[(end++)%size] = curNode->lchild;
            queue[(end++)%size] = curNode->rchild;   //队列
        }

    }
}

//前缀表达式
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
        default:return (int)(T->data - '0');   //数字的情况
    }
}

