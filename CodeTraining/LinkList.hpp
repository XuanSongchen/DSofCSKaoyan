//
//  LinkList.hpp
//  CodeTraining
//
//  Created by 宣松辰 on 19/04/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#ifndef LinkList_hpp
#define LinkList_hpp

#include "Header.h"

LinkList CreatList1(LinkList &);
LinkList CreatList2(LinkList &);
void PrintList(LinkList &);
void Del_X_3(LinkList &, int);
void Del_X_1(LinkList &, int);
void R_Print(LinkList &);
void Del_Same(LinkList &);
LinkList UnionList(LinkList &, LinkList &);
LinkList Intersection (LinkList &, LinkList &);
bool Pattern(LinkList &, LinkList &);

#endif /* LinkList_hpp */
