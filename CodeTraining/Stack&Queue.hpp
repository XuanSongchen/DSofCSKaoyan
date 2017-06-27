//
//  Stack&Queue.hpp
//  CodeTraining
//
//  Created by 宣松辰 on 19/04/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#ifndef Stack_Queue_hpp
#define Stack_Queue_hpp

#include "Header.h"

void InitStack(SqStack &);
bool StackEmpty(SqStack);
bool Push(SqStack &, ElemType);
bool Pop(SqStack &, ElemType &);
bool GetTop(SqStack &, ElemType &);
bool IfLegal(char []);
void InitQueue(SqQueue &);
bool QueueEmpty(SqQueue &);
bool EnQueue(SqQueue &, ElemType &);
bool DeQueue(SqQueue &, ElemType &);
void InitQueue(LinkQueue &);
bool QueueEmpty(LinkQueue &);
void EnQueue(LinkQueue &, ElemType);
bool DeQueue(LinkQueue &, ElemType &);
bool BracketsCheck(char []);
ElemType EvaluationRPN(char [], ElemType &);
int Fib(int);
void Train_Arrange(ElemType []);
ElemType Pn_x(int, ElemType);
void ShipManage(SqQueue &, SqQueue &);

#endif /* Stack_Queue_hpp */


