//
//  LinkList.cpp
//  CodeTraining
//
//  Created by 宣松辰 on 19/04/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#include "LinkList.hpp"

LinkList CreatList1(LinkList &L) {
    //前插法建立链表
    LNode *s; ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    L -> next = NULL;
    cin >> x;
    while (x != EndNum) {
        s = (LNode*)malloc(sizeof(LNode));
        s -> data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}

LinkList CreatList2(LinkList &L) {
    //后插法建立链表
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    L->next = NULL;
    cin>>x;
    while (x != EndNum) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
    return L;
}

void PrintList(LinkList &L) {
    //打印链表
    LNode *p = L->next;
    while(p != NULL) {
        cout << p->data;
        p=p->next;
    }
    cout<<endl;
}

void Del_X_3(LinkList &L, ElemType x) {
    //删除无头结点链表中值为x的元素
    LNode *p;
    if (L){
        if (L->data==x) {
            p = L;
            L = L->next;
            free(p);
            Del_X_3(L, x);
        } else
            Del_X_3(L->next, x);
    }
}

void Del_X_1(LinkList &L, ElemType x) {
    //删除有头结点链表中值为x的元素
    LNode *p = L, *q = p->next;
    while (q) {
        if (q->data == x) {
            p->next = q->next;
            free(q);
            q = p->next;
        } else {
            p = q;
            q = p->next;
        }
    }
}

void R_Print(LinkList &L) {
    //反向打印链表
    if (L->next)
        R_Print(L->next);
    cout << L->data;
}

void Del_Same(LinkList &L) {
    //删除相同值的元素
    LNode *p = L->next, *q;
    if (p) {
        while (p->next) {
            q = p->next;
            if (q->data == p->data) {
                p->next = q->next;
                free(q);
            } else
                p = p->next;
        }
    }
}

LinkList UnionList(LinkList &la, LinkList &lb) {
    //求两个递增链表的交集，王道代码，存疑
    LNode *pa = la->next, *pb = lb->next, *pc = la, *u;
    while(pa&&pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        } else {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(lb);
    return la;
}

LinkList Intersection (LinkList &A, LinkList &B) {
    //求两个递增链表的交集，自写代码
    LNode *pa = A->next, *pb = B->next, *pra = A;
    while (pa&&pb) {
        if (pb->data < pa->data) {
            B->next = pb->next;
            free(pb);
            pb = B->next;
        } else if(pb->data > pa->data) {
            pra->next = pa->next;
            free(pa);
            pa = pra->next;
        } else {
            if(pra->data == pa->data) {
                pra->next = pa->next;
                free(pa);
                pa = pra->next;
            } else {
                pra = pa;
                pa = pa->next;
            }
            B->next = pb->next;
            free(pb);
            pb = pb->next;
        }
    }
    if(pb)
        pa = pb;
    while(pa) {
        pra->next = pa->next;
        free(pa);
        pa = pa->next;
    }
    pra->next = NULL;
    free(B);
    return A;
}

bool Pattern(LinkList &A, LinkList &B) {
    //判断B是否为A的子序列
    LNode *pa = A->next, *pb = B->next, *c = A;
    while (pa) {
        while (pa->data == pb->data) {
            c = pa;
            pa = pa->next;
            pb = pb->next;
            if (pb == NULL)
                return true;
            if (pa == NULL)
                return false;
        }
        if(c != A)
            pa = c;
        else
            pa = pa->next;
        pb = B->next;
    }
    return false;
}
