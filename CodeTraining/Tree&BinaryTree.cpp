//
//  Tree&BinaryTree.cpp
//  CodeTraining
//
//  Created by 宣松辰 on 19/04/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#include "Tree&BinaryTree.hpp"

BiTree CreateBiTree(BiTree T) {
    //建立二叉树
    int elem;
    scanf("%d", &elem);
    if(elem == EndNum)
        T = NULL;
    else {
        T = new BiTNode;
        T->data = elem;
        T->lchild = CreateBiTree(T->lchild);
        T->rchild = CreateBiTree(T->rchild);
    }
    return T;
}

void visit(BiTree T) {
    //访问T结点
    if(T != NULL)
        cout << T->data << " ";
}

void visit(ThreadTree T) {
    //访问T结点
    if(T != NULL)
        cout << T->data << " ";
}

void PreOrder(BiTree T) {
    //递归前序遍历
    if (T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T) {
    //递归中序遍历
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T) {
    //递归后序遍历
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void PreOrder2(BiTree T) {
    //非递归前序遍历
    stack<BiTNode *> S;
    BiTNode *p = T;
    while (p || !S.empty()) {
        if (p) {
            visit(p);
            S.push(p);
            p = p->lchild;
        } else {
            p = S.top()->rchild;
            S.pop();
        }
    }
}

void InOrder2(BiTree T) {
    //非递归中序遍历
    stack<BiTNode *> S;
    BiTNode *p = T;
    while (p || !S.empty()) {
        if (p) {
            S.push(p);
            p = p->lchild;
        } else {
            visit(p = S.top());
            S.pop();
            p = p->rchild;
        }
    }
}

void PostOrder2(BiTree T) {
    //非递归后序遍历
    stack<BiTNode *> S;
    BiTNode *cur;
    BiTNode *pre = NULL;
    S.push(T);
    while(!S.empty()) {
        cur = S.top();
        if ((cur->lchild == NULL && cur->rchild == NULL) ||
            (pre != NULL && (pre == cur->lchild ||
                             pre == cur->rchild))) {
            visit(cur);
            S.pop();
            pre = cur;
        } else {
            if (cur->rchild != NULL)
                S.push(cur->rchild);
            if (cur->lchild != NULL)
                S.push(cur->lchild);
        }
    }
}

void PostOrder3(BiTree T) {
    //非递归后序遍历-王道版
    stack<BiTNode *>S;
    BiTNode *p = T, *pre = NULL;
    while (!S.empty() || p) {
        if (p) {
            S.push(p);
            p = p->lchild;
        } else {
            p = S.top();
            if (p->rchild && p->rchild != pre) {
                p = p->rchild;
                S.push(p);
                p = p->lchild;
            } else {
                visit(pre = p = S.top());
                p = NULL;
                S.pop();
            }
        }
    }
}

void LevelOrder(BiTree T) {
    //层次遍历
    queue<BiTNode *> Q;
    BiTNode *p;
    Q.push(T);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        visit(p);
        if (p->lchild)
            Q.push(p->lchild);
        if (p->rchild)
            Q.push(p->rchild);
    }
}

void InTread(ThreadTree &p,ThreadTree &pre) {
    //中序遍历对二叉树线索化
    if (p) {
        InTread(p->lchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InTread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T) {
    //中序遍历建立中序线索二叉树
    ThreadTree pre = NULL;
    if (T) {
        InTread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

ThreadNode *Firstnode(ThreadTree p) {
    //求中序线索二叉树中序序列下的第一个结点
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

ThreadNode *Nextnode(ThreadNode *p) {
    //求中序线索二叉树中结点p在中序序列下的后继结点
    if (p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;
}

ThreadNode *Lastnode(ThreadTree p) {
    //求中序线索二叉树中序序列下的最后一个结点
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}

ThreadNode *Prenode(ThreadNode *p) {
    //求中序线索二叉树中结点p在中序序列下的前驱结点
    if (p->ltag == 0)
        return Lastnode(p->lchild);
    else
        return p->lchild;
}

void InOrder(ThreadTree T) {
    //不带头结点的中序线索二叉树的中序遍历
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
        visit(p);
}

void InvertLevel(BiTree T) {
    //从下到上、从右向左遍历二叉树
    stack<BiTNode *> S;
    queue<BiTNode *> Q;
    BiTNode *p;
    Q.push(T);
    while (!Q.empty()) {
        S.push(p = Q.front());
        Q.pop();
        if (p->lchild)
            Q.push(p->lchild);
        if (p->rchild)
            Q.push(p->rchild);
    }
    while (!S.empty()) {
        visit(S.top());
        S.pop();
    }
}

int BTDepth1(BiTree T) {
    //求二叉树深度，自写算法，前序遍历
    stack<BiTNode* > S;
    BiTNode *p = T;
    int count = 0, maxcount = count;
    while (p || !S.empty()) {
        if (p) {
            S.push(p);
            count++;
            p = p->lchild;
        } else {
            p = S.top()->rchild;
            S.pop();
            if (!p)
                count--;
        }
        maxcount = (count > maxcount) ? count : maxcount;
    }
    return maxcount;
}

int BTDepth2(BiTree T) {
    //求二叉树深度，王道算法，层次遍历
    if(T) {
        int front = -1, rear = -1;
        int last = 0, level = 0;
        BiTree Q[MaxSize];
        Q[++rear] = T;
        BiTree p;
        while (front < rear) {
            p = Q[++front];
            if (p->lchild)
                Q[++rear] = p->lchild;
            if (p->rchild)
                Q[++rear] = p->rchild;
            if (front == last) {
                level++;
                last = rear;
            }
        }
        return level;
    }
    return 0;
}

int BTDepth3(BiTree T) {
    //求二叉树深度，王道算法，递归
    if (T) {
        int ldep = BTDepth3(T->lchild);
        int rdep = BTDepth3(T->rchild);
        if (ldep > rdep)
            return ldep + 1;
        else
            return rdep + 1;
    }
    return  0;
}

BiTree CreatBiTree2(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2){
    //先序遍历和中序遍历构造一棵二叉树
    //l1 h1为先序遍历的头尾结点下标， l2 h2为中序遍历的头尾结点下标
    BiTNode *root = (BiTree)malloc(sizeof(BiTNode));
    root->data = A[l1];
    int i;
    for (i = l2; B[i] != root->data; i++);
    int llen = i - l2;
    int rlen = h2 - i;
    if (llen)
        root->lchild = CreatBiTree2(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    else
        root->lchild = NULL;
    if (rlen)
        root->rchild = CreatBiTree2(A, B, h1 - rlen + 1, h1, h2 - rlen +1, h2);
    else
        root->rchild = NULL;
    return root;
}

bool IsComplete(BiTree T) {
    //判断二叉树是否为完全二叉树
    queue<BiTNode *> Q;
    BiTNode *p;
    Q.push(T);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        if (p) {
            Q.push(p->lchild);
            Q.push(p->rchild);
        } else {
            while (!Q.empty()) {
                p = Q.front();
                Q.pop();
                if (p)
                    return false;
            }
        }
    }
    return true;
}

int DsonNodes(BiTree T){
    //确定二叉树中双分支结点的个数
    if(T == NULL)
        return 0;
    if(T->lchild && T->rchild)
        return DsonNodes(T->lchild) + DsonNodes(T->rchild) + 1;
    else
        return DsonNodes(T->lchild) + DsonNodes(T->rchild);
}

void Swap(BiTree T) {
    //交换二叉树左右子树
    if(T) {
        Swap(T->lchild);
        Swap(T->rchild);
        BiTNode *p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
    }
}

ElemType PreOrderDataK(BiTree T, int k) {
    //非递归找出先序遍历第K个结点的值
    stack<BiTNode *> S;
    BiTNode *p = T;
    int i = 1;
    while (p || !S.empty()) {
        if (p) {
            S.push(p);
            if (i++ == k)
                return p->data;
            p = p->lchild;
        } else {
            p = S.top()->rchild;
            S.pop();
        }
    }
    return 0;
}

void DeleteXTree(BiTree T) {
    //删除某一结点并释放其子树的空间
    if (T) {
        DeleteXTree(T->lchild);
        DeleteXTree(T->rchild);
        free(T);
    }
}

void Search(BiTree T, ElemType x) {
    //寻找值为x的结点，并释放其子树的空间
    queue<BiTNode *> Q;
    BiTNode *p;
    if (T) {
        if (T->data == x) {
            DeleteXTree(T);
            exit(0);
        }
        Q.push(T);
        while (!Q.empty()) {
            p = Q.front();
            Q.pop();
            if (p->lchild) {
                if (p->lchild->data == x) {
                    DeleteXTree(p->lchild);
                    p->lchild = NULL;
                } else
                    Q.push(p->lchild);
            }
            if (p->rchild) {
                if (p->rchild->data == x) {
                    DeleteXTree(p->rchild);
                    p->rchild = NULL;
                } else
                    Q.push(p->rchild);
            }
        }
    }
}

void PrintXParents(BiTree T, ElemType x) {
    //打印值为x的结点的所有祖先结点的值 王道版本
    ParentsStack s[MaxSize];
    int top = 0;
    while (T || top >0) {
        while (T && T->data != x) {
            s[++top].t = T;
            s[top].tag = 0;
            T = T->lchild;
        }
        if(!T)
            T = s[top].t;
        if (T->data == x) {
            printf("所查找的所有祖先结点的值为: ");
            for (int i = 1; i <= top; i++)
                printf("%d ", s[i].t->data);
            exit(1);
        }
        while (top && s[top].tag == 1)
            top--;
        if (top) {
            s[top].tag = 1;
            T = s[top].t->rchild;
        }
    }
}

bool printAncestors(BiTree T, int x) {
    //打印值为x的结点的所有祖先结点的值 网络版本
    if (T == NULL)
        return false;
    if (T->data == x)
        return true;
    if (printAncestors(T->lchild, x) ||printAncestors(T->rchild, x)){
        printf("%d ", T->data);
        return true;
    }
    return false;
}

BiTree Ancestor(BiTree root, BiTNode *p, BiTNode *q) {
    //寻找root为根结点的p、q指向的两个结点的公共祖先r
    stack<BiTNode *> S1, S2;//S1用来保存p的祖先结点，S2用来保存q的祖先结点
    BiTNode *m = root, *pre = NULL;
    while (m || !S1.empty()) {
        if (m) {
            if (m == p) break;
            S1.push(m);
            S2.push(m);
            m = m->lchild;
        } else {
            m = S1.top();
            if (m->rchild && m->rchild != pre) {
                m = m->rchild;
                S1.push(m);
                S2.push(m);
                m = m->lchild;
            } else {
                m = NULL;
                S1.pop();
                S2.pop();
            }
        }
    }
    while (m || !S2.empty()) {
        if (m) {
            if (m == q) break;
            S2.push(m);
            m = m->lchild;
        } else {
            m = S2.top();
            if (m->rchild && m->rchild != pre) {
                m = m->rchild;
                S2.push(m);
                m = m->lchild;
            } else {
                m = NULL;
                S2.pop();
            }
        }
    }
    for (int i = 0; i < S1.size(); i++) {
        stack<BiTNode *>S = S2;
        for (int j = 0; j < S2.size(); j++) {
            if (S1.top() == S.top())
                return S1.top();
            else
                S.pop();
        }
    }
    return NULL;
}

BiTree Ancestor2(BiTree root, BiTNode *p, BiTNode *q) {
    //寻找二叉树中pq指向的结点的最近公共祖先 王道版本
    ParentsStack s[MaxSize], s1[MaxSize];
    int top = 0, top1 = 0;
    BiTNode *bt = root;
    while (bt || top > 0) {
        while (bt && bt != p && bt != q) {//结点入栈
            while (bt) {//结点沿左分枝向下
                s[++top].t = bt;
                s[top].tag = 0;
                bt = bt->lchild;
            }
        }
        while (top && s[top].tag == 1) {
            //假定p在q左侧，遇到p时，栈内均为p的祖先
            if (s[top].t == p) {
                for (int i =1; i <= top; i++) {
                    s1[i] = s[i];
                    top1 = top;
                }
            }
            if (s[top].t == q) {//找到q结点
                for (int i = top; i > 0; i--) {//冒泡匹配
                    for (int j = top1; j > 0; j--)
                        if (s1[j].t == s[i].t)
                            return s[i].t;
                }
                top--;//退栈
            }
        }//while
        if (top) {
            s[top].tag = 1;
            bt = s[top].t->rchild;//沿右分枝向下
        }
    }//while
    return NULL;//pq无公共祖先
}

typedef struct{
    BiTree data[MaxSize];
    int level[MaxSize];
    int front, rear;
} levelqueue;

int BTWidth(BiTree T) {
    //求二叉树的宽度（即结点数最多的层的结点数) 王道版本
    BiTNode *p;
    levelqueue Qu;
    int k, max, i, n;
    Qu.front = Qu.rear = -1;
    Qu.rear++;
    Qu.data[Qu.rear] = T;
    Qu.level[Qu.rear] = 1;
    while (Qu.front < Qu.rear) {
        Qu.front++;
        p = Qu.data[Qu.front];
        k = Qu.level[Qu.front];
        if (p->lchild) {
            Qu.rear++;
            Qu.data[Qu.rear] = p->lchild;
            Qu.level[Qu.rear] = k + 1;
        }
        if (p->rchild) {
            Qu.rear++;
            Qu.data[Qu.rear] = p->rchild;
            Qu.level[Qu.rear] = k + 1;
        }
    }//while
    max = 0;
    i = 0;
    k = 1;
    while (i <= Qu.rear) {
        n = 0;
        while (i <= Qu.rear && Qu.level[i] == k) {
            n++;
            i++;
        }
        k = Qu.level[i];
        if (n > max)
            max = n;
    }
    return max;
}

void PreToPost(ElemType pre[], int l1, int h1, ElemType post[], int l2, int h2) {
    //已知满二叉树的先序序列求后序序列
    int half;
    if (h1 >= l1) {
        post[h2] = pre[l1];
        half = (h1 - l1) / 2;
        PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        PreToPost(pre, l1 + half + 1, h1, post, l1 + half, h2 - 1);
    }
}

BiTNode *head, *pre = NULL;
BiTree LeafList(BiTree T) {
    //将二叉树的叶子结点连接成单链表
    if (T) {
        LeafList(T->lchild);
        if (T->lchild == NULL && T->rchild == NULL) {
            if (pre == NULL) {
                head = T;
                pre = T;
            } else {
                pre->rchild = T;
                pre = T;
            }
        }
        LeafList(T->rchild);
        pre->rchild = NULL;
    }
    return head;
}

bool IsSimilar(BiTree A, BiTree B) {
    //判断两棵树是否相似，相似即均为空或均只有跟结点或左右子树均相似
    if (A == NULL && B == NULL)
        return true;
    else if (A == NULL || B == NULL)
        return false;
    else
        return (IsSimilar(A->lchild, B->lchild) && IsSimilar(A->rchild, B->rchild));
}

ThreadTree PreInPost(ThreadTree T, ThreadNode *p) {
    //在中序线索二叉树中寻找某结点在后序遍历下的前驱
    if (p->rtag == 0)
        return p->rchild;
    else if (p->ltag == 0)
        return p->lchild;
    else if (p->lchild == NULL)
        return NULL;
    else {
        while (p->ltag == 1 && p->lchild != NULL)
            p = p->lchild;
        return p->lchild;
    }
}

int wpl_PreOrder(BiTree root, int deep) {
    //前序遍历求二叉树所有叶结点的带权路径长度和
    static int wpl = 0;
    if (root->lchild == NULL && root->rchild == NULL)
        wpl += deep * root->weight;
    if (root->lchild != NULL)
        wpl_PreOrder(root->lchild, deep + 1);
    if (root->rchild != NULL)
        wpl_PreOrder(root->rchild, deep + 1);
    return wpl;
}

int WPL(BiTree root) {
    //求二叉树所有叶结点的带权路径长度和
    return wpl_PreOrder(root, 0);
}

int wpl_LevelOrder(BiTree root) {
    //层次遍历求二叉树所有叶结点的带权路径长度和
    BiTree q[MaxSize];                  //声明队列
    int front = 0, rear = 0;            //front rear分别为头为指针
    int wpl = 0, deep = 0;              //初始化wpl与深度
    BiTNode *lastNode = root;           //lastNode记录当前层最后一个结点
    BiTNode *newLastNode = NULL;        //newLastNode记录下一层最后一个结点
    q[rear++] = root;                   //根结点入队
    while (front != rear) {             //判断队不为空
        BiTNode *t = q[front++];        //出队
        if (!t->lchild && !t->rchild) { //如果为根结点
            wpl += deep * t->weight;    //加权
        }
        if (t->lchild) {                //如果存在左孩子
            q[rear++] = t->lchild;      //左孩子入队
            newLastNode = t->lchild;    //设下一层最后一个结点为该结点的左孩子
        }
        if (t->rchild) {                //如果存在右孩子
            q[rear++] = t->rchild;      //右孩子入队
            newLastNode = t->rchild;    //设下一层最后一个结点为该结点的右孩子
        }
        if (t == lastNode) {            //如果该结点为本层最后一个结点
            lastNode = newLastNode;     //更新lastNode
            deep += 1;                  //层数加1
        }
    }
    return wpl;                         //返回wpl
}

int UFSets[MaxSize]; //集合元素数组（树的双亲指针数组）

void Initial(int S[]) {
    //并查集的初始化操作，S为并查集
    for (int i = 0; i < MaxSize; i++)
        S[i] = -1;
}

int Find(int S[], int x) {
    //Find操作（函数在并查集S中查找并返回包含元素x的树的根）
    while (S[x] >= 0)
        x = S[x];
    return x;
}

void Union(int S[], int Root1, int Root2) {
    //Union操作（函数求两个不相交子集合的并集）
    //Root1与Root2不同并且表示子集合的名字
    S[Root2] = Root1;
}

int ForestLeaf(BiTree T) {
    //在孩子兄弟表示法中求对应森林的叶子结点个数
    if (T) {
        if (T->firstchild == NULL)
            return 1 + ForestLeaf(T->nextsibling);
        else
            return ForestLeaf(T->firstchild) + ForestLeaf(T->nextsibling);
    }
    return 0;
}

int TreeDepth(CSTree T) {
    //递归求孩子兄弟表示法中树的深度
    int childDepth, siblingDepth;
    if(T) {
        childDepth = TreeDepth(T->firstchild);
        siblingDepth = TreeDepth(T->nextsibling);
        if (childDepth + 1 > siblingDepth)
            return childDepth + 1;
        else
            return siblingDepth;
    }
    return 0;
}

void CreatCSTree_Degree(CSTree &T, ElemType e[], int degree[], int n) {
    //已知层次序列和结点的度，构造孩子兄弟链表
    CSTree pointer[MaxSize];
    int i, j, d, k = 0;//k为子女结点序号
    for (i = 0; i < n; i++) {//初始化
        pointer[i] = new CSNode;
        pointer[i]->data = e[i];
        pointer[i]->firstchild = pointer[i]->nextsibling = NULL;
    }
    for (i = 0; i < n; i++) {
        d = degree[i];
        if (d) {
            k++;
            pointer[i]->firstchild = pointer[k];
            for (j = 2; j <= d; j++) {
                k++;
                pointer[k-1]->nextsibling = pointer[k];
            }
        }
    }
    T = pointer[0];
    free(pointer);
}

BiTree BST_Search(BiTree T, ElemType key, BiTNode *&p) {
    //二叉排序树的非递归查找算法
    p = NULL;//p指向被查找结点的双亲结点，用于插入删除操作
    while (T != NULL && key != T->data) {
        p = T;
        if (key < T->data)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

BiTree BST_Search2(BiTree T, ElemType key, BiTNode *&p) {
    //二叉排序树的递归查找算法
    p = NULL;
    if (T != NULL && key != T->data) {
        p = T;
        if (key < T->data)
            return BST_Search2(T->lchild, key, p);
        else
            return BST_Search2(T->rchild, key, p);
    }
    return T;
}

bool BST_Insert(BiTree &T, ElemType key) {
    //在二叉排序树T中插入一个关键字为T的结点
    if (T == NULL) {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        return true;
    } else if (key == T->data)
        return false;
    else if (key < T->data)
        return BST_Insert(T->lchild, key);
    else
        return BST_Insert(T->rchild, key);
}

void Creat_BST(BiTree &T, ElemType key[], int n) {
    //用关键字数组key[]建立一个二叉排序树
    T = NULL;
    int i = 0;
    while (i < n)
        BST_Insert(T, key[i++]);
}

//while (p || !S.empty()) {
//    if (p) {
//        S.push(p);
//        p = p->lchild;
//    } else {
//        visit(p = S.top());
//        S.pop();
//        p = p->rchild;
//    }
//}


bool IsBST(BiTree T) {
    //判断二叉树是不是二叉排序树
    stack<BiTNode *> s;
    BiTNode *p = T, *pre = NULL;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();
            if (pre == NULL)
                pre = s.top();
            else if (pre->data >= p->data)
                    return false;
            s.pop();
            p = p->rchild;
        }
    }
    return true;
}

int LevelInBST(BiTree T, ElemType e) {
    //求指定结点在二叉搜索树中的层次
    if (!T)
        return 0;
    int level = 1;
    BiTNode *p = T;
    while (p->data != e) {
        if (e > p->data)
            p = p->rchild;
        else
            p = p->lchild;
        level++;
    }
    return level;
}

void IsAVL(BiTree T, int &balance, int &height) {
    //判断二叉树是不是平衡二叉树
    int balancel, balancer, heightl, heightr;
    if(!T) {
        height = 0;
        balance = 1;
    } else if (!T->lchild && !T->rchild) {
        height = 1;
        balance = 1;
    } else {
        IsAVL(T->lchild, balancel, heightl);
        IsAVL(T->rchild, balancer, heightr);
        height = (heightl > heightr ? heightl : heightr) + 1;
        if (abs(heightl - heightr) < 2)
            balance = balancel & balancer;
        else
            balance = 0;
    }
}

ElemType MaxElemInBST(BiTree T) {
    //求出二叉排序树中最大关键字
    while (T->rchild)
        T = T->rchild;
    return T->data;
}

ElemType MinElemInBST(BiTree T) {
    //求出二叉排序树中最小关键字
    while (T->lchild)
        T = T->lchild;
    return T->data;
}

void BST_ElemLessThan_k(BiTree T, ElemType k) {
    //从大到小输出二叉排序树中不小于k的关键字
    if (T != NULL) {
        BST_ElemLessThan_k(T->rchild, k);
        if (T->data >= k)
            cout << T->data << " ";
        BST_ElemLessThan_k(T->lchild, k);
    }
}

BiCTree RandomBST_Smallest_k(BiCTree T, int k) {
    //找出随机构造的二叉排序树中第k小的元素
    /*
     算法思想：
        1.如果k大于根结点的count值，或者小于1，返回NULL
        2.如果左孩子不存在：
            1.如果k等于1，返回该结点
            2.如果k大于1，递归右孩子，k-1
        3.如果左孩子存在：
            1.如果k小于结点左孩子结点的count值+1，递归左孩子
            2.如果k等于结点左孩子结点的count值+1，返回该结点
            3.如果k大于结点左孩子结点的count值+1，递归右孩子，k-结点左孩子count值-1
     */
    if (k < 1 || k > T->count)
        return NULL;
    if (T->lchild == NULL) {
        if (k == 1)
            return T;
        else
            return RandomBST_Smallest_k(T->rchild, k-1);
    } else {
        if (k < T->lchild->count + 1)
            return RandomBST_Smallest_k(T->lchild, k);
        if (k == T->lchild->count + 1)
            return T;
        if (k > T->lchild->count + 1)
            return RandomBST_Smallest_k(T->rchild, k - T->lchild->count - 1);
    }
    return NULL;
}















