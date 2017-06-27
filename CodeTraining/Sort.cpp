//
//  Sort.cpp
//  CodeTraining
//
//  Created by 宣松辰 on 2017/5/5.
//  Copyright © 2017年 宣松辰. All rights reserved.
//

#include "Sort.hpp"

void InitByOne(ElemType A[], int low, int high) {
    for (int i = low; i <= high; i++)
        A[i] = high - i + 1;
}

void Print(ElemType A[], int low, int high) {
    for (int i = low; i <= high; i++)
        cout << A[i] << " ";
    cout << endl;
}


void InsertSort_Direct(ElemType A[], int n) {
    //直接插入排序
    int i, j;
    for (i = 2; i <= n; i++)                    //依次将A[2]～A[n]插入到前面已排好的序列
        if (A[i] < A[i - 1]) {                  //若A[i]的关键码小鱼其前驱，需将A[i]插入有序表
            A[0] = A[i];                        //复制为哨兵，A[0]不存放元素
            for (j = i - 1; A[0] < A[j]; --j)   //从后往前查找待插入位置
                A[j+1] = A[j];                  //向后挪位
            A[j + 1] = A[0];                    //复制到插入位置
        }
}

void InsertSort_Binary(ElemType A[], int n) {
    //折半插入排序
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++) {                  //依次将A[2]～A[n]插入到前面已排序序列
        A[0] = A[i];                            //将A[i]暂存到A[0]
        low = 1; high = i - 1;                  //设置折半查找的范围
        while (low <= high) {                   //折半查找（默认递增有序）
            mid = (low + high) / 2;             //取中间点
            if (A[mid] > A[0]) high = mid - 1;  //查找左子表
            else low = mid + 1;                 //查找右子表
        }
        for (j = i - 1; j >= high + 1; --j)
            A[j + 1] = A[j];                    //统一后移元素，空出插入位置
        A[high + 1] = A[0];                     //插入操作
    }
}

void ShellSort(ElemType A[], int n) {
    //希尔排序，对顺序表做希尔插入排序，比直接插入排序有如下修改
    //1.前后记录的增量是dk，不是1
    //2.r[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
    int i, j, dk;                               //dk为步长
    for (dk = n / 2; dk >= 1; dk = dk / 2)      //步长变化
        for (i = dk + 1; i <= n; ++i)
            if (A[i] < A[i - dk]) {             //需将A[i]插入有序增量子表
                A[0] = A[i];                    //暂存在A[0]
                for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk)
                    A[j + dk] = A[j];           //记录后移，查找插入的位置
                A[j + dk] = A[j];               //插入
            }//if
}

void BubbleSort(ElemType A[], int n) {
    //冒泡排序
    bool flag;
    for (int i = 0; i < n - 1; i++) {
        flag = false;
        for (int j = n - 1; j > i; j--)
            if (A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        if (flag == true) return;
    }
}

void QuickSort(ElemType A[], int low, int high) {
    //快速排序
    if (low < high) {                           //递归跳出的条件
        int pivotpos = Partition(A, low, high); //划分
        QuickSort(A, low, pivotpos - 1);        //依次对两个子表进行递归排序
        QuickSort(A, pivotpos + 1, high);
    }
}

int Partition(ElemType A[], int low, int high) {
    //严版教材中的划分算法（一趟排序过程）
    ElemType pivot = A[low];                    //将当前表中第一个元素设为枢轴值，对表进行划分
    while (low < high) {                        //循环跳出条件
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];                       //将比枢轴值小的元素移动到左端
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low];                       //将比枢轴值大的元素移动到右端
    }
    A[low] = pivot;                             //枢轴元素存放到最终位置
    return low;                                 //返回存放枢轴元素的位置
}

void SelectSort(ElemType A[], int n) {
    //对表A进行简单的选择排序，A[]从0开始存放元素
    for (int i = 0; i < n - 1; i++) {           //一共进行n-1趟
        int min = i;                            //记录最小元素位置
        for (int j = i + 1; i < n; j++)         //在A[1...n-1]中选择最小的元素
            if (A[j] < A[min]) min = j;         //更新最小元素的位置
        if (min != i) swap(A[i], A[min]);       //与第i个位置互换
    }
}

void BuildMaxHeap(ElemType A[], int len) {
    //建立大根堆
    for (int i = len / 2; i > 0; i--)           //从i=[n/2]～1，反复调整堆
        AdjustDown(A, i, len);
}

void AdjustDown(ElemType A[], int k, int len) {
    //将元素k向下进行调整
    A[0] = A[k];                                //A[0]暂存
    for (int i = 2 * k; i <= len; i *= 2) {     //沿key较大的子结点向下筛选
        if (i < len && A[i] < A[i + 1])
            i++;                                //取key较大的子结点的下标
        if (A[0] >= A[i]) break;                //筛选结束
        else {
            A[k] = A[i];                        //将A[i]调整到双亲结点上
            k = i;                              //修改k值，以便继续向下筛选
        }
    }//for
    A[k] = A[0];                                //被筛选结点的值放入最终位置
}

void HeapSort(ElemType A[], int len) {
    //堆排序
    BuildMaxHeap(A, len);                       //建立初始堆
    for (int i = len; i > 1; i--) {             //n-1趟的交换和建堆过程
        swap(A[i], A[1]);                       //输出堆顶的元素（和堆底元素交换）
        AdjustDown(A, 1, i - 1);                //整理，把剩余的i-1个元素整理成堆
    }
}

void AdjustUp(ElemType A[], int k) {
    //参数k为向上调整的结点，也为堆的元素个数
    A[0] = A[k];
    int i = k / 2;                              //若结点值大于双亲结点，
                                                //则将双亲结点下调，并继续向上比较
    while (i > 0 && A[i] < A[0]) {              //循环退出条件
        A[k] = A[i];                            //双亲结点下调
        k = i;
        i = k / 2;                              //继续向上比较
    }
    A[k] = A[0];                                //复制到最终位置
}

void DoubleBubbleSor(ElemType A[], int n) {
    //双向冒泡排序
    bool flag = true;
    int low = 0, high = n - 1;
    while (low < high && flag) {
        flag = false;
        for (int i = low; i < high; i++)
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                flag = true;
            }
        high--;
        for (int i = high; i > low; i--)
            if (A[i] < A[i - 1]) {
                swap(A[i], A[i - 1]);
                flag = true;
            }
        low++;
    }
}

void OddToFront(ElemType A[], int n) {
    //将所有奇数放在偶数前
    int i = 1, j = n - 1;
    while (i < j) {
        while (i < j && A[i] % 2 == 0) --j;
        while (i < j && A[i] % 2 == 1) ++i;
        if (i < j)
            swap(A[i], A[j]);
        i++; j--;
    }
}
void RandomQuickSort(ElemType A[], int low, int high) {
    //随机枢轴值快速排序
    if (low < high) {
        int pivotpos = RandomPartition(A, low, high); //划分
        RandomQuickSort(A, low, pivotpos - 1);        //依次对两个子表进行递归排序
        RandomQuickSort(A, pivotpos + 1, high);
    }
}

int RandomPartition(ElemType A[], int low, int high) {
    //随机枢轴值快速排序划分
    int rand_Index = low + rand() % (high - low + 1);
    swap(A[rand_Index], A[low]);
    ElemType pivot = A[low];
    int i = low;
    for (int j = low + 1; j <= high; j++)
        if (A[j] < pivot)
            swap(A[++i], A[j]);
    swap(A[i], A[low]);
    return i;
}

int kth_elem(ElemType A[], int low, int high, ElemType k) {
    //寻找第k小的元素
    int pivot = A[low];
    int low_temp = low, high_temp = high;
    while (low < high) {
        while (low < high && A[high] > pivot) high--;
        A[low] = A[high];
        while (low < high && A[low] < pivot) low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    if (low == k)
        return A[low];
    else if (low > k)
        return kth_elem(A, low_temp, low - 1, k);
    else
        return kth_elem(A, low + 1, high_temp, k - low);
}

int DividedTwoParts(ElemType A[], int n) {
    //将数列分为几乎等长的和差最大的两部分
    int low = 0, low0 = 0, high = n - 1, high0 = n - 1;
    int pivotkey = A[low], flag = 1, k = n / 2, i, s1 = 0, s2 = 0;
    while (flag) {
        pivotkey = A[low];
        while (low < high && A[high] > pivotkey) --high;
        A[low] = A[high];
        while (low < high && A[low] < pivotkey) ++low;
        A[high] = A[low];
        A[low] = pivotkey;
        if (low == k - 1)
            flag = 0;
        else {
            if (low < k - 1) {
                low0 = ++low;
                high = high0;
            } else {
                high0 = --high;
                low = low0;
            }
        }
    }
    for (i = 0; i < k; i++) s1 += A[i];
    for (i = k; i < n; i++) s2 += A[i];
    return s2 - s1;
}


void HollandFlag(color A[], int n) {
    //荷兰国旗问题
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        switch (A[j]) {
            case RED:
                cout<<A[i]<<" "<<A[j]<<endl;
                swap(A[i], A[j]);
                cout<<A[i]<<" "<<A[j]<<endl;
                i++;
                j++;
                for (int i = 0; i < 10; i++)
                    cout << A[i] << " ";
                cout << endl;
                break;
            case WHITE:
                j++;
                for (int i = 0; i < 10; i++)
                    cout << A[i] << " ";
                cout << endl;
                break;
            default:
                swap(A[j], A[k]);
                k--;
                for (int i = 0; i < 10; i++)
                    cout << A[i] << " ";
                cout << endl;
        }
    }
}

void SelectSort_Linklist(LinkList &L) {
    //假设L不带表头结点
    LNode *h = L, *p, *pre, *maxpre, *max;
    L = NULL;
    while (h != NULL) {
        p = max = h;
        pre = maxpre = NULL;
        while (p != NULL) {
            if (p->data > max->data) {
                max = p;
                maxpre = pre;
            }
            pre = p; p = p->next;
        }
        if (max == h)
            h = h->next;
        else
            maxpre->next = max->next;
        max->next = L;
        L = max;
    }
}

bool IsMinHeap(ElemType A[], int len) {
    //判断一个数组是不是小根堆
    if (len % 2 == 0) {
        if (A[len / 2] > A[len])
            return false;
        for (int i = len / 2 - 1; i >= 1; i--)
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
                return false;
    } else {
        for (int i = len / 2; i >= 1; i--)
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
                return false;
    }
    return true;
}

void CountSort(ElemType A[], ElemType B[], int n) {
    //计数排序，对于每个元素扫描一遍数组，统计比它小的元素数目，确定位置
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (A[j] < A[i])
                count++;
        B[count] = A[i];
        count = 0;
    }
}











