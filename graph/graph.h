#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MAX_VALUE 32767			//代替无穷大，表示权最大值
#define MAX_VERTEX_NUM 100		//最大顶点个数
#define MAX_NAME 9				//顶点名称的字符串最大长度+1
#define MAX_INFO 20				//弧边的相关信息字符串最大长度+1

typedef char *InfoType;			//边的相关信息类型
typedef int VRType;				//定义顶点关系类型为整型
typedef struct
{
	char name[MAX_NAME];		
}VertexType;					//顶点信息类型

//边信息结构
typedef struct
{
	VRType adj;			//顶点间关系
	InfoType info;		//该弧相关信息的指针
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//邻接矩阵

//图的信息结构
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];	//顶点向量
	AdjMatrix arcs;						//邻接矩阵
	int vexnum,arcnum;					//图的当前顶点数和弧数
	int kind;							//图的种类标志
}MGraph;								//图的结构


int LocateVex_M(MGraph G,VertexType u);	//在图中查找顶点值为u的顶点
bool CreateGraph_M(MGraph &G);
VertexType GetVer_M(MGraph G,int v);
bool PutVer_M(MGraph &G,int v);
int FirstAdjVex_M(MGraph G,int v);
int NextAdjVex_M(MGraph G,int v,int w);
void InsertVex_M(MGraph &G,VRType v);
bool InsertArc_M(MGraph &G,VertexType w);
bool DeletArc_M(MGraph &G,VertexType v,VertexType w);
bool DeletVex_M(MGraph &G,VertexType v);
void PrintGraph_M(MGraph G);
void DestroyGraph_M(MGraph &G);


#endif