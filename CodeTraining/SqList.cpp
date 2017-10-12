//
//  SqList.cpp
//  CodeTraining
//
//  Created by 宣松辰 on 02/05/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#include "SqList.hpp"

bool Del_Min(SqList &L, ElemType &value) {
    if (L.length == 0)
        return false;
    value = L.data[0];
    int minLoc = 0;
    for (int i = 0; i < L.length; i++)
        if (L.data[i] < value) {
            value = L.data[i];
            minLoc = i;
        }
    L.data[minLoc] = L.data[L.length - 1];
    L.length--;
    return true;
}

void Reverse(SqList &L) {
    ElemType temp;
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

void Del_x(SqList &L, ElemType x) {
    int count = 0;
    for (int i = 0; i < L.length; i++)
        if (L.data[i] != x)
            L.data[count++] = L.data[i];
    L.length = count;
}

bool Del_ST(SqList &L, ElemType s, ElemType t) {
    if ((s >= t) || (L.length == 0))
        return false;
    int count = 0;
    for (int i = 0; i < L.length; i++)
        if (L.data[i] < s || L.data[i] > t)
            L.data[count++] = L.data[i];
    L.length = count;
    return true;
}

bool Del_ST2(SqList &L, ElemType s, ElemType t) {
    int i, j;
    if ((s >= t) || (L.length == 0))
        return false;
    for (i = 0; i < L.length && L.data[i] < s; i++);
    if (i >= L.length)
        return false;
    for (j = i; j < L.length && L.data[i] <=t; j++);
    for (; j < L.length; i++, j++)
        L.data[i] = L.data[j];
    L.length = i;
    return true;
}

void Del_Same(SeqList &L) {
    int count = 0;
    for (int i = 1; i < L.length; i++)
        if (L.data[i] != L.data[count])
            L.data[++count] = L.data[i];
    L.length = count + 1;
}

bool merge(SeqList A, SeqList B, SeqList &C) {
    if (A.length + B.length > C.maxsize)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data [i] < B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length)
        C.data[k++] = A.data[i++];
    while (j < B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}

void Reverse_between(SeqList &L, int start, int end) {
    ElemType temp;
    for (int i = 0; i < (end - start + 2) / 2; i++) {
        temp = L.data[start + i];
        L.data[start + i] = L.data[end - i];
        L.data[end - i] = temp;
    }
}

void Reverse_mn(SeqList &L, int m, int n) {
    Reverse_between(L, 0, L.length);
    Reverse_between(L, 0, n - 1);
    Reverse_between(L, n, m + n - 1);
}

void Find_Insert_x(SeqList &L, ElemType x) {
    int j, low = 0, high = L.length - 1, mid = (low + high) / 2;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == x)
            break;
        else if (L.data[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (L.data[mid] == x && mid != L.length - 1) {
        ElemType temp = L.data[mid];
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = temp;
    }
    if (low > high) {
        for (j = L.length - 1; j > high; j--)
            L.data[j + 1] = L.data[j];
        L.data[j] = x;
        L.length++;
    }
}

void Loop_left(SeqList &L, int p) {
    Reverse_between(L, 0, L.length - 1);
    Reverse_between(L, 0, L.length - p - 1);
    Reverse_between(L, L.length - p, L.length - 1);
}

ElemType Combine_median(SeqList &A, SeqList &B) {
    int s1 = 0, d1 = A.length - 1, m1, s2 = 0, d2 = B.length - 1, m2;
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A.data[m1] == B.data[m2])
            return A.data[m1];
        if (A.data[m1] < B.data[m2]) {
            if ((s1 + d1) % 2 == 0) {
                s1 = m1;
                d2 = m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        } else {
            if ((s2 + d2) % 2 == 0) {
                s2 = m2;
                d1 = m1;
            } else {
                s2 = m2 + 1;
                d1 = m1;
            }
        }
    }
    return A.data[s1] < B.data[s2] ? A.data[s1] : B.data[s2];
}

ElemType Most_elem(SeqList &L) {
    int count = 0;
    ElemType most = L.data[0];
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == most)
            count++;
        else {
            if (count == 0) {
                count = 1;
                most = L.data[i];
            } else
                count--;
        }
    }
    if (count > 0)
        for (int i = count = 0; i < L.length; i++)
            if (L.data[i] == most)
                count++;
    if (count > L.length / 2)
        return most;
    else return -1;
}




