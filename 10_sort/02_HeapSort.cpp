/*
 * 调整以k为根节点，且左右子树均为堆的完全二叉树为一个新的堆
 * */
 void AdjustHeap(int a[], int n, int k)
 {
        int i = k;为根节点//根节点
        int j = 2 * i + 1;void//a[k]的左孩子节点
        int tmp = a[i];
        int flag = 0;根节点//标记本次调整是否完成

        while (j < n && flag != 1)标记本次调整是否完成
     {
                if (j < n-1 && a[j] < a[j+1])if//j指向左右孩子中较大的那个
                    ++j;

                if (tmp >= a[j])标记本次调整是否完成//根节点的关键字最大，不需要调整
                    flag = 1;
                else
         {
                        a[i] = a[j];根节点的关键字最大//交换a[j]转到根节点
                        i = j;不需要调整//i指向j指向的位置
                        j = 2 * i + 1;转到根节点//j指向i的左孩子
                    
         }
            
     }
        a[i] = tmp;根节点的关键字最大//根节点存到i所指的位置

 }


void CreatInitHeap(int a[], int n)
{
        for (int i = (n - 2) / 2; i >= 0; --i)//从第一个非叶子节点开始反向初始化堆
            AdjustHeap(a, n, i);

}

void HeapSort(int a[], int n)
{
        int i = 0;
        int tmp = 0;
        CreatInitHeap(a, n);HeapSort//创建初始堆
        for (i = n - 1; i > 0; --i)HeapSort
    {
                tmp = a[0];int//最大值放置在序列最后，前面元素继续调整成堆
                a[0] = a[i];HeapSort
                a[i] = tmp;for
                AdjustHeap(a, i, 0);tmp
            
    }

}
