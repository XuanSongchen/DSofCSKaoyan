//
//  Stack&Queue.cpp
//  CodeTraining
//
//  Created by 宣松辰 on 19/04/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#include "Stack&Queue.hpp"

void InitStack(SqStack &S) {
    //初始化顺序栈
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    //判断顺序栈是否为空
    if (S.top == -1) return true;
    else return false;
}

bool Push(SqStack &S, ElemType x) {
    //顺序栈进栈操作
    if (S.top == MaxSize - 1) return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    //顺序栈出栈操作
    if (S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack &S, ElemType &x) {
    //获取顺序栈栈顶元素
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

bool IfLegal(char A[]) {
    //判断进栈、出栈操作是否合法
    int count = 0;
    for(int i = 0; i < strlen(A); i++) {
        if (A[i] == 'I') count++;
        else count--;
        if (count < 0) return false;
    }
    if (count > 0) return false;
    return true;
}

void InitQueue(SqQueue &Q) {
    //初始化循环队列
    Q.rear = Q.front = 0;
}

bool QueueEmpty(SqQueue &Q) {
    //判断循环队列是否为空
    return Q.rear == Q.front ? true : false;
}

bool EnQueue(SqQueue &Q, ElemType &x) {
    //循环队列的入队操作
    if ((Q.rear + 1) % MaxSize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    //循环队列的出队操作
    if (Q.rear == Q.front)
        return false;
    else {
        x = Q.data[Q.front];
        Q.front = (Q.front + 1) % MaxSize;
    }
    return true;
}

void InitQueue(LinkQueue &Q) {
    //初始化链式队列
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool QueueEmpty(LinkQueue &Q) {
    //判断链式队列是否为空
    return Q.front == Q.rear ? true : false;
}

void EnQueue(LinkQueue &Q, ElemType x) {
    //链式队列入队操作
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x) {
    //链式队列出队操作
    if (Q.front == Q.rear) return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return true;
}

bool BracketsCheck(char A[]) {
    //括号匹配，包含{}[]()三种类型
    SqStack s;
    InitStack(s);
    ElemType x;
    for (int i = 0; i < strlen(A); i++) {
        switch (A[i]) {
            case '[': Push(s, A[i]); break;
            case '(': Push(s, A[i]); break;
            case '{': Push(s, A[i]); break;
            case ']': Pop(s, x);
                if (x != '[') return false;
                break;
            case '}': Pop(s, x);
                if (x != '{') return false;
                break;
            case ')': Pop(s, x);
                if (x != '(') return false;
                break;
            default:
                break;
        }
    }
    if (!StackEmpty(s))
        return false;
    else
        return true;
}

ElemType EvaluationRPN(char A[], ElemType &x) {
    //逆波兰式计算
    SqStack s;
    InitStack(s);
    ElemType num1, num2;
    for (int i = 0; i < strlen(A); i++) {
        if (A[i] >= 48 && A[i] <= 57 )
            Push(s, (ElemType)(A[i] - '0'));
        else {
            if (Pop(s, num1) == false) {
                printf("输入错误\n");
                return 0;
            }
            if (Pop(s, num2) == false) {
                printf("输入错误\n");
                return 0;
            }
            switch (A[i]) {
                case '+': num2 += num1; break;
                case '-': num2 -= num1; break;
                case '*': num2 *= num1; break;
                case '/': num2 /= num1; break;
                case '%': num2 %= num1; break;
                default : printf("输入非法字符\n");
                    return 0;
            }
            Push(s, num2);
        }
    }
    Pop(s, x);
    if (!StackEmpty(s)) {
        printf("输入错误\n");
        return 0;
    } else
        return x;
}

int Fib(int n) {
    //斐波那契数列递归函数
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        return Fib(n-1) + Fib(n-2);
    }
}

void Train_Arrange(ElemType train[]) {
    //交换火车顺序（王道数据结构P87-2）
    SqStack s;
    InitStack(s);
    int p = 0, i = 0;
    while (train[i] == 'H' || train[i] == 'S') {
        if (train[i] == 'S') {
            train[p++] = train[i++];
        }
        else {
            Push(s, train[i++]);
        }
    }
    while (!StackEmpty(s)) {
        ElemType c;
        Pop(s, c);
        train[p++] = c;
    }
}

ElemType Pn_x(int n, ElemType x) {
    //非递归计算P_n(x)=1                          n=0
    //              =2x                         n=1
    //              =2xP_n-1(x)-2(n-1)P_n-2(x)  n>1
    //(王道数据结构P87-3）
    struct {
        int no;
        ElemType val;
    } st[MaxSize];
    int top = -1;
    ElemType fv1 = 1, fv2 = x * 2;
    for (int i = n; i >= 2; i--) {
        top++;
        st[top].no = i;
    }
    while (top >= 0) {
        cout << "st[top].no - 1=" << st[top].no - 1;
        cout << " x=" << x;
        cout << " fv1=" << fv1;
        cout << " fv2=" << fv2 << endl;
        st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if (n == 0)
        return fv1;
    return fv2;
}

void ShipManage(SqQueue &H, SqQueue &K) {
    //轮船调度问题(王道数据结构P87-4）
    SqQueue Q;
    InitQueue(Q);
    int i = 0, j = 0;
    ElemType x;
    while (j < 10) {
        if (!QueueEmpty(K) && i < 4) {
            DeQueue(K, x);
            EnQueue(Q, x);
            i++;
            j++;
        } else if (i == 4 && !QueueEmpty(H)) {
            DeQueue(H, x);
            EnQueue(Q, x);
            j++;
            i = 0;
        } else {
            while (j < 10 && i < 4 && !QueueEmpty(H)) {
                DeQueue(H, x);
                EnQueue(Q, x);
                i++;
                j++;
            }
            i = 0;
        }
        if (QueueEmpty(H) && QueueEmpty(K))
            j = 11;
    }
}
