#ifndef __STRING_H__
#define __STRING_H__

#define STRING_INITSIZE 256

typedef char ElemType;

typedef struct 
{
	ElemType *str;
	int length;
}DSqString;

bool StrAssign_Sq(DSqString &s,char *chars);
bool StrCopy_Sq(DSqString &S,DSqString T);
int  StrLength_Sq(DSqString S);
int  StrCompare_Sq(DSqString S,DSqString T);
bool StrConcat_Sq(DSqString &S,DSqString T);
bool SubString_Sq(DSqString S,DSqString &sub,int pos,int len);
bool Index_Sq(DSqString S,DSqString T,int &pos);
bool StrInsert_Sq(DSqString &S,int pos,DSqString T);
bool StrDelet_Sq(DSqString &S,int pos,int len);
void StrReplace_Sq(DSqString &S,DSqString T,DSqString V);
void StrTravers_Sq(DSqString S);
void DestroyString_Sq(DSqString &S);



#endif