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
int iFactor[801] = {0}; //�x�s���ꪺ�]��  Base�̦h�u��800 
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
	    //log �禡�ҬO�H10���� �G�n�p��logiInput �H10��������
	    //�����f�t�������� 
		dDigit += log(i) / log (iBase);
		iTemp = i;
		//cout << dDigit << endl;
		//�p��i���]�� 
		//��i�h���_�bBASE�����]��
		for (j = 2 ; j <= iBase ; j++)
		    {
		    while (iTemp % j == 0)
		        {
		        iFactor[j]++;
		        iTemp /= j;
		        }
		    }
	    } 
	//�p�⦳�X��0 
	while (bContinue)
		{
		iTemp = iBase;
		for (i = 2 ; i <= iBase ; i++)
		    {
		        	
		    //�p�G�P�_�������ܼƩҦs����>1�ɡA�]����true 
		    //ex:15! �H10������ ��3��2 1��3 1��5
			//2��5����㰣10 ��3����|�l1 
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
