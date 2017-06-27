//
//  Sort.hpp
//  CodeTraining
//
//  Created by 宣松辰 on 2017/5/5.
//  Copyright © 2017年 宣松辰. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include "Header.h"

void InitByOne(ElemType[], int, int);
void Print(ElemType[], int, int);
void InsertSort_Direct(ElemType[], int);
void InsertSort_Binary(ElemType[], int);
void ShellSort(ElemType[], int);
void BubbleSort(ElemType[], int);
void QuickSort(ElemType[], int, int);
int Partition(ElemType[], int, int);
void SelectSort(ElemType[], int);
void BuildMaxHeap(ElemType[], int);
void AdjustDown(ElemType[], int, int);
void HeapSort(ElemType[], int);
void AdjustUp(ElemType[], int);
void DoubleBubbleSor(ElemType[], int);
void OddToFront(ElemType[], int);
void RandomQuickSort(ElemType[], int, int);
int RandomPartition(ElemType[], int, int);
int kth_elem(ElemType[], int, int, ElemType);
int DividedTwoParts(ElemType[], int);
void HollandFlag(color[], int);
void SelectSort_Linklist(LinkList &);
bool IsMinHeap(ElemType[], int);

#endif /* Sort_hpp */
