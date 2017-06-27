//
//  Tree&BinaryTree.hpp
//  CodeTraining
//
//  Created by 宣松辰 on 19/04/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#ifndef Tree_BinaryTree_hpp
#define Tree_BinaryTree_hpp

#include "Header.h"

BiTree CreateBiTree(BiTree);
void visit(BiTree);
void visit(ThreadTree);
void PreOrder(BiTree);
void InOrder(BiTree);
void PostOrder(BiTree);
void PreOrder2(BiTree);
void InOrder2(BiTree);
void PostOrder2(BiTree);
void PostOrder3(BiTree);
void LevelOrder(BiTree);
void InTread(ThreadTree &,ThreadTree &);
void CreateInThread(ThreadTree);
ThreadNode *Firstnode(ThreadTree);
ThreadNode *Nextnode(ThreadNode *);
ThreadNode *Lastnode(ThreadTree);
ThreadNode *Prenode(ThreadNode *);
void InOrder(ThreadTree);
int BTDepth1(BiTree);
int BTDepth2(BiTree);
int BTDepth3(BiTree);
BiTree CreatBiTree2(ElemType[], ElemType[], int, int, int, int);
bool IsComplete(BiTree);
int DsonNodes(BiTree);
void Swap(BiTree);
ElemType PreOrderDataK(BiTree, int);
void DeleteXTree(BiTree);
void Search(BiTree, ElemType);
void PrintXParents(BiTree, ElemType);
bool printAncestors(BiTree, int);
BiTree Ancestor(BiTree, BiTNode *, BiTNode *);
BiTree Ancestor2(BiTree, BiTNode *, BiTNode *);
void PreToPost(ElemType[], int, int, ElemType[], int, int);
bool IsSimilar(BiTree, BiTree);
ThreadTree PreInPost(ThreadTree, ThreadNode *);
int wpl_PreOrder(BiTree, int);
int WPL(BiTree);
int wpl_LevelOrder(BiTree);
void Initial(int[]);
int Find(int[], int);
void Union(int[], int, int);
int ForestLeaf(CSTree);
int TreeDepth(CSTree);
BiTree BST_Search(BiTree, ElemType, BiTNode *&);
BiTree BST_Search2(BiTree, ElemType, BiTNode *&);
bool BST_Insert(BiTree &, ElemType);
void Creat_BST(BiTree &, ElemType[], int);
bool IsBST(BiTree);
int LevelInBST(BiTree, ElemType);
void IsAVL(BiTree, int &, int &);
ElemType MaxElemInBST(BiTree);
ElemType MinElemInBST(BiTree);
void BST_ElemLessThan_k(BiTree, ElemType);
BiCTree RandomBST_Smallest_k(BiCTree, int);

#endif /* Tree_BinaryTree_hpp */
