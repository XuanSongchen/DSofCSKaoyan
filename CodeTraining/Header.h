//
//  Header.h
//  CodeTraining
//
//  Created by 宣松辰 on 19/04/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

//顺序表、链表、栈、队列、树、二叉树相关
#define MaxSize 100
#define EndNum 0
#define weight data

#define firstchild lchild                       //孩子兄弟表示法_第一个孩子
#define nextsibling rchild                      //孩子兄弟表示法_右兄弟
#define CSTree BiTree                           //孩子兄弟表示法_树
#define CSNode BiTNode                          //孩子兄弟表示法_树结点

typedef int ElemType;                           //结点数据类型

typedef struct {                                //顺序表定义
    ElemType data[MaxSize];
    int length;
} SqList;

typedef struct {                                //动态分配数组顺序表的定义
    ElemType *data;
    int maxsize, length;
} SeqList;

typedef struct LNode {                           //链表定义
    int data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct {                                //顺序栈定义
    ElemType data[MaxSize];
    int top;
} SqStack;

typedef struct LinkNode {                       //链栈／结点定义
    int data;
    struct LinkNode *next;
} *LiStack;

typedef struct {                                //顺序／循环队列定义
    int data[MaxSize];
    int front, rear;
} SqQueue;

typedef struct {                                //链式队列定义（LinkNode来自上方LinkNode结点定义）
    struct LinkNode *front, *rear;
} LinkQueue;

typedef struct BiTNode {                        //链式二叉树定义
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct BiTCtNode {                      //带有子树结点数量的链式二叉树定义
    ElemType data;
    int count;
    struct BiTCtNode *lchild, *rchild;
} BiTCtNode, *BiCTree;

typedef struct ThreadNode {                     //线索二叉树定义
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

typedef struct {                                //常用于后序遍历寻找祖先的栈
    BiTree t;
    int tag;                                    //tag=0表示左子女已被访问
                                                //tag=1表示右子女已被访问
} ParentsStack;

typedef struct {                                //树的结点定义
    ElemType data;
    int parent;
} PTNode;

typedef struct {                                //树的类型定义
    PTNode nodes[MaxSize];
    int n;
} PTree;


//图相关
#define MaxVertexNum 100                        //顶点数目的最大值

typedef char VertexType;                        //顶点的数据类型
typedef int EdgeType;                           //边的数据类型
typedef int InfoType;                           //网的边权值

//邻接矩阵存储结构定义
typedef struct {
    VertexType Vex[MaxVertexNum];               //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //邻接矩阵，边表
    int vexnum, arcnum;                         //图的当前顶点数和弧数
} MGraph;


//邻接表存储结构定义
typedef struct ArcNode {                        //边表结点
    int adjvex;                                 //该弧所指向的顶点的位置
    struct ArcNode *next;                       //指向下一条弧的指针
    InfoType info;                              //网的边权值
} ArcNode;

typedef struct VNode {                          //顶点表结点
    VertexType data;                            //顶点信息
    ArcNode *first;                             //指向第一条依附该结点的弧的指针
} VNode, AdjList[MaxVertexNum];

typedef struct {                                //图的邻接表存储结构定义
    AdjList vertices;                           //邻接表
    int vexnum, arcnum;                         //图的顶点数和弧数
} ALGraph;                                      //ALGraph是以邻接表存储的图类型


//十字链表存储结构定义
typedef struct ArcNode2 {                       //边表结点
    int tailvex, headvex;                       //该弧的头尾结点
    struct ArcNode2 *hlink, *tlink;             //分别指向弧头相同和弧尾相同的结点
    InfoType info;                              //相关信息指针
} ArcNode2;

typedef struct VNode2 {                         //顶点表结点
    VertexType data;                            //顶点信息
    ArcNode2 *firstin, *firstout;               //指向第一条入弧和出弧
} VNode2;

typedef struct {
    VNode2 xlist[MaxVertexNum];                 //邻接表
    int vexnum, arcnum;                         //图的顶点数和弧数
} GLGraph;                                      //GLGraph是以十字链表存储的图类型


//邻接多重表存储结构定义
typedef struct ArcNode3 {                       //边表结点
    bool mark;                                  //访问标记
    int ivex, jvex;                             //分别指向该弧的两个结点
    struct ArcNode3 *ilink, *jlink;             //分别指向两个顶点的下一条边
    InfoType info;                              //相关信息指针
} ArcNode3;

typedef struct VNode3 {                         //顶点表结点
    VertexType data;                            //顶点信息
    ArcNode3 *firstedge;                        //指向第一条依附该顶点的边
}VNode3;

typedef struct {
    VNode3 adjmulist[MaxVertexNum];             //邻接表
    int vexnum, arcnum;                         //图的顶点数和弧数
} AMLGraph;                                     //AMLGraph是以邻接多重表存储的图类型


//排序相关
typedef enum{RED, WHITE, BLUE} color;
#endif /* Header_h */
