
##动态线性表


提供如下功能:

### 1. 初始化线性表
void InitList_Sq(SqList &L,int maxsize = LIST_INIT_SIZE, int incresize = LISTINCREAMENT);

### 2. 计算线性表长度
int  ListLengh_Sq(SqList L);

### 3. 查找元素e的位置
int  LocateElem_Sq(SqList L,ElemType e);

### 4. 插入元素
bool ListInsert_Sq(SqList &L,int i,ElemType e);

### 5. 删除元素
bool ListDelete_Sq(SqList &L,int i,ElemType &e);

### 6. 遍历元素
void ListTraverse_Sq(SqList L);

### 7. 获取元素
bool GetElem_Sq(SqList L,int i,ElemType &e);




