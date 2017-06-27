//
//  Search.cpp
//  CodeTraining
//
//  Created by 宣松辰 on 02/05/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#include "Search.hpp"

int Binary_Search(SeqList L, ElemType key) {
   //在有序表L中查找关键字为key的元素，若存在则分会其位置，不存在返回-1
   //折半查找、二分查找
    int low = 0, high = L.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == key)
            return mid;
        else if(L.data[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
