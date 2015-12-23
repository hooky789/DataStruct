#include "String.h"
#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	DSqString S1,S2,S3,S4;
	DSqString sub;
	int pos=10;
	StrAssign_Sq(S1,"child");
	StrAssign_Sq(S2,"children");
	StrAssign_Sq(S3,"chinese chair technology");
	StrCopy_Sq(S4,S1);
	//初始子串
	StrTravers_Sq(S1);
	StrTravers_Sq(S2);
	StrTravers_Sq(S3);
	StrTravers_Sq(S4);

	cout<<"串S1长度："<<endl<<StrLength_Sq(S1)<<endl;
	cout<<"串1和串2比较："<<endl<<StrCompare_Sq(S1,S2)<<endl;
	StrConcat_Sq(S1,S2);
	cout<<"字符串S2粘贴到S1："<<endl;
	StrTravers_Sq(S1);
	cout<<"S3位置为1长度为5的子串："<<endl;
	SubString_Sq(S3,sub,1,5);
	StrTravers_Sq(sub);
	cout<<"字符串S1中查找S2："<<endl;
	if(Index_Sq(S1,S2,pos))
	{
		cout<<pos<<endl;
	}
	else
	{
		cout<<"Index false"<<endl;
	}
	StrInsert_Sq(S3,0,S2);
	StrTravers_Sq(S3);
	cout<<"子串删除"<<endl;
	StrDelet_Sq(S3,0,16);

	cout<<"字串替换"<<endl;
	StrReplace_Sq(S2,S1,S3);
	cout<<"操作后字串:"<<endl;
	StrTravers_Sq(S1);
	StrTravers_Sq(S2);
	StrTravers_Sq(S3);
	StrTravers_Sq(S4);
	DestroyString_Sq(S1);
	DestroyString_Sq(S2);
	DestroyString_Sq(S3);
	DestroyString_Sq(S4);
	//system("pause");
}