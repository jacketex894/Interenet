#include <iostream>
#include <cmath>
using namespace std;

int main()
{
int iInput;
int iBase;
double dDigit;
int iDigit;
int i;
int j;
int iFactor[801] = {0}; //儲存測資的因數  Base最多只到800 
int iTemp;
int iZeroCount;
bool bContinue;

while (cin >> iInput >> iBase && iInput != EOF && iBase != EOF)
	{
	iZeroCount = 0;
	dDigit = 0;
	bContinue = true;
	for (i = 1 ; i <= iInput ; i ++)
	    { 
	    //log 函式皆是以10為底 故要計算logiInput 以10為底的話
	    //必須搭配換底公式 
		dDigit += log(i) / log (iBase);
		iTemp = i;
		//cout << dDigit << endl;
		//計算i的因數 
		//由i去推斷在BASE內的因數
		for (j = 2 ; j <= iBase ; j++)
		    {
		    while (iTemp % j == 0)
		        {
		        iFactor[j]++;
		        iTemp /= j;
		        }
		    }
	    } 
	//計算有幾個0 
	while (bContinue)
		{
		iTemp = iBase;
		for (i = 2 ; i <= iBase ; i++)
		    {
		        	
		    //如果判斷式中的變數所存的值>1時，也視為true 
		    //ex:15! 以10為底時 有3個2 1個3 1個5
			//2跟5都能整除10 但3不行會餘1 
			// 
		    while (iFactor[i] && iTemp % i == 0)
		        {
		        iFactor[i] --;
		        iTemp /= i;
		        }
		    }
		if (iTemp == 1)
		    iZeroCount ++;
		else
		    bContinue = false;
		}
	for (i = 1 ; i <= iBase ;i++)
	    iFactor[i] = 0;
	cout << iZeroCount << " " << (int)dDigit + 1 << endl;
	}
return 0;
} 
