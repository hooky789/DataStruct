#include "graph.h"
#include "string.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//查找
int LocateVex_M(MGraph G,VertexType u)
{
	int i = 0;
	for(;i < G.vexnum; ++i)
	{
		if(strcmp(u.name,G.vexs[i].name) == 0)
		{
			return i;
		}
	}
	return -1;//查找失败
}

//创建图
int IncInfo;
bool CreateGraph_M(MGraph &G)
{
	int i,j,k;
	int kind;
	VertexType v1,v2;
	VRType w;
	cout<<"输入图的类型（有向图-0；有向网-1；无向图-2；无向网-3）"<<endl;
	cin>>kind;
	G.kind = kind;
	cout<<"输入图的顶点数，边数，边是否包含相关信息（是-1；否-0）"<<endl;
	cin>>G.vexnum>>G.arcnum>>IncInfo;
	cout<<"输入"<<G.vexnum<<"个顶点值（名称小于"<<MAX_NAME<<"个字符）"<<endl;
	for(i=0;i < G.vexnum;++i)
	{
		cin>>G.vexs[i].name;
	}
	for(i = 0;i < G.vexnum;++i)
	{
		for(j=0;j<G.vexnum;++j)
		{
			if(!(G.kind%2))
			{
				G.arcs[i][j].adj = 0;
			}
			else
			{
				G.arcs[i][j].adj = MAX_VALUE;
			}
			G.arcs[i][j].info = NULL;
		}
	}

	for(k=0;k < G.arcnum;++k)
	{
		cout<<"请输入第"<<k+1<<"条弧的的弧尾（顶点1）弧头（顶点2）:";
		cin>>v1.name>>v2.name;
		i = LocateVex_M(G,v1);
		j = LocateVex_M(G,v2);
		if( i < 0 || j < 0 )
		{
			cout<<"输入的顶点1或顶点2不存在！"<<endl;
			return false;
		}
		if(!(G.kind%2))
		{
			G.arcs[i][j].adj = 1;
		}
		else
		{
			cout<<"请输入权值:";
			cin>>w;
			G.arcs[i][j].adj = w;
		}
		if(IncInfo)
		{
			cout<<"请输入该弧的相关信息（小于"<<MAX_INFO<<"个字符）"<<endl;
			G.arcs[i][j].info = (char*)malloc((MAX_INFO)*sizeof(char));
			cin>>G.arcs[i][j].info;
		}
		if(G.kind > 1)
		{
			G.arcs[j][i] = G.arcs[i][j];
		}
	}
}

//获取图中序号为v的的顶点值
VertexType GetVer_M(MGraph G,int v)
{
	if(v > G.vexnum || v < 0)
	{
		exit(0);
	}
	else
	{
		return G.vexs[v];
	}
}

bool PutVer_M(MGraph &G,VertexType v,VertexType value)
{
	int locate = LocateVex_M(G,v);
	if(locate == -1)
	{
		cout<<"该顶点不存在"<<endl;
		return false;
	}
	G.vexs[locate] = value;
	return true;
}


int FirstAdjVex_M(MGraph G,int v)
{
	int i;
	VRType j = 0;
	if( (G.kind % 2) )
	{
		j = MAX_VALUE;
	}
	for(i = 0;i < G.vexnum; ++i)
	{
		if(G.arcs[v][i].adj != j)
		{
			return i;
		}
	}
	return -1;
}


int NextAdjVex_M(MGraph G,int v,int w)
{
	int i;
	VRType j = 0;
	if((G.kind%2))
	{
		j = MAX_VALUE;
	}
	for(i = w + 1;i < G.vexnum;++i)
	{
		if(G.arcs[i][j].adj != j)
		{
			return i;
		}
	}
	return -1;
}


void InsertVex_M(MGraph &G,VertexType v)
{
	int i;
	VRType j = 0;
	if((G.kind%2))
	{
		j = MAX_VALUE;
	}
	G.vexs[G.vexnum] = v;
	for(i = 0;i <= G.vexnum; ++i)
	{
		G.arcs[G.vexnum][i].adj = j;
		G.arcs[i][G.vexnum].adj = j;
		G.arcs[G.vexnum][i].info = NULL;
		G.arcs[i][G.vexnum].info = NULL;
	}
	G.vexnum++;
}


bool InsertArc_M(MGraph &G,VertexType v,VertexType w)
{
	int i,v1,w1;
	v1 = LocateVex_M(G,v);
	w1 = LocateVex_M(G,w);
	if(v1 < 0 || w1<0)
	{
		return false;
	}
	++(G.arcnum);
	if(G.kind%2)
	{
		cout<<"请输入此边的权值:"<<endl;
		cin>>G.arcs[v1][w1].adj;
	}
	else
	{
		G.arcs[v1][w1].adj = 1;
	}
	cout<<"是否有该边的相关信息？（0-无；1-有）"<<endl;
	cin>>i;
	if(i)
	{
		cout<<"请输入该边的相关信息（小于"<<MAX_INFO<<"个字符)"<<endl;
		cin>>G.arcs[v1][w1].info;
	}
	if(G.kind>1)
	{
		G.arcs[w1][v1] = G.arcs[v1][w1];
	}
	return true;
}


bool DeletArc_M(MGraph &G,VertexType v,VertexType w)
{
	int v1,w1;
	VRType j = 0;
	if(G.kind%2)
	{
		j = MAX_VALUE;
	}
	v1 = LocateVex_M(G,v);
	w1 = LocateVex_M(G,w);
	if(v1 < 0 || w1 < 0)
	{
		return false;
	}
	if(G.arcs[v1][w1].adj != j)
	{
		G.arcs[v1][w1].adj = j;
		if(G.arcs[v1][w1].info)
		{
			free(G.arcs[v1][w1].info);
			G.arcs[v1][w1].info = NULL;
		}
		if(G.kind >= 2)
		{
			G.arcs[w1][v1] = G.arcs[v1][w1];
		}
		--(G.arcnum);
	}
	return true;
}

bool DeletVex_M(MGraph &G,VertexType v)
{
	int i,j,k;
	k = LocateVex_M(G,v);
	if(k < 0)
	{
		return false;
	}
	for(i = 0;i < G.vexnum; ++i)
	{
		DeletArc_M(G,v,G.vexs[i]);
	}
	if(G.kind<2)
	{
		for(i = 0;i<G.vexnum;++i)
		{
			DeletArc_M(G,G.vexs[i],v);
		}
	}
	for(j=k+1;j<G.vexnum;++j)
	{
		G.vexs[j-1] = G.vexs[j];
	}
	for(i=0;i<G.vexnum;++i)
	{
		for(j=k+1;j<G.vexnum;++j)
		{
			G.arcs[j-1][i] = G.arcs[j][i];
		}

	}
	--(G.vexnum);
	return true;
}

void PrintGraph_M(MGraph G)
{
	int i,j;
	char s[10] = {"无向网"};
	char s1[4] = {"边"};
	switch(G.kind)
	{
	case 0:	strcpy(s,"有向图");
			strcpy(s1,"弧");
			break;
	case 1: strcpy(s,"有向网");
			strcpy(s1,"弧");
			break;
	case 2:	strcpy(s,"无向图");
			break;
	case 3:	break;
	default:break;
	}
	cout<<G.vexnum<<"个顶点"<<G.arcnum<<"条"<<s1<<"的"<<s<<".顶点依次是：";
	for(i=0;i < G.vexnum;++i)
	{
		
		cout<<setw(5)<<GetVer_M(G,i).name;
	}
	cout<<endl<<"邻接矩阵为："<<endl;
	for(i=0;i<G.vexnum;++i)
	{
		for(j=0;j<G.vexnum;++j)
		{
			cout<<setw(8)<<G.arcs[i][j].adj;
		}
		cout<<endl;
	}
	if(IncInfo)
	{
		cout<<"弧的相关信息:"<<endl;
		if(G.kind < 2)
		{
			cout<<"弧尾 弧头 该"<<s1<<"的信息："<<endl;
		}
		else
		{
			cout<<"顶点1 顶点2 该"<<s1<<"的信息："<<endl;
		}
		for(i=0;i<G.vexnum;++i)
		{
			if(G.kind<2)
			{
				for(j=0;j<G.vexnum;++j)
				{
					if(G.arcs[i][j].info)
					{
						cout<<setw(5)<<G.vexs[i].name<<setw(5)<<G.vexs[j].name;
						cout<<setw(9)<<G.arcs[i][j].info<<endl;
					}
				}
			}
			else
			{
				for(j=i+1;j<G.vexnum;++j)
				{
					if(G.arcs[i][j].info)
					{
						cout<<setw(5)<<G.vexs[i].name<<setw(5)<<G.vexs[j].name;
						cout<<setw(9)<<G.arcs[i][j].info<<endl;
					}
				}
			}
		}
	}
}


void DestroyGraph_M(MGraph &G)
{
	int i;
	for(i=G.vexnum-1;i >= 0;--i)
	{
		DeletVex_M(G,G.vexs[i]);
	}
}


