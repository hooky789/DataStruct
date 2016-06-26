#include "String.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	DSqString S1,S2,S3,S4;
	DSqString sub;
	int pos=10;
	StrAssign_Sq(S1,"child");
	StrAssign_Sq(S2,"children");
	StrAssign_Sq(S3,"chinese chair technology");
	StrCopy_Sq(S4,S1);
	//³õÊ¼×Ó´®
	StrTravers_Sq(S1);
	StrTravers_Sq(S2);
	StrTravers_Sq(S3);
	StrTravers_Sq(S4);

	cout<<"string \"S1\" length: "<< endl<<StrLength_Sq(S1)<<endl;
	cout<<"compare S1 to S2" <<endl<<StrCompare_Sq(S1,S2)<<endl;
	StrConcat_Sq(S1,S2);
	cout<<"S2 string concat to S1: "<<endl;
	StrTravers_Sq(S1);
	cout<<"S3 sub String is :"<<endl;
	SubString_Sq(S3,sub,1,5);
	StrTravers_Sq(sub);
	cout<<"Find S2 in S1: "<<endl;
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
	cout<<"delete sub String "<<endl;
	StrDelet_Sq(S3,0,16);

	cout<<"replace string " <<endl;
	StrReplace_Sq(S2,S1,S3);
	cout<<"after opration " <<endl;
	StrTravers_Sq(S1);
	StrTravers_Sq(S2);
	StrTravers_Sq(S3);
	StrTravers_Sq(S4);
	DestroyString_Sq(S1);
	DestroyString_Sq(S2);
	DestroyString_Sq(S3);
	DestroyString_Sq(S4);
	return 0;
}

