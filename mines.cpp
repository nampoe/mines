#include <iostream>
#include <stdlib.h>
#include <unistd.h>


using namespace std;

string bombLocation = "X";
string clearLocation = "O";
string moi = "1923786"; 
string hidden = "[]";

void createTable(int bombAmt, string (&trueBoard)[5][5])
{
    
    string hiddenBoard[5][5] =
    { 
        {hidden, hidden, hidden, hidden, hidden},
        {hidden, hidden, hidden, hidden, hidden},
        {hidden, hidden, hidden, hidden, hidden},
        {hidden, hidden, hidden, hidden, hidden},
        {hidden, hidden, hidden, hidden, hidden}
    };


    for(int i = 0; i < bombAmt; i++) // asettaa määrätyn määrän pommeja randomeille paikoille
    {
        int xAxisBomb = rand() % 5;
    
        int zAxisBomb = rand() % 5;

        if (!(trueBoard[xAxisBomb][zAxisBomb] == bombLocation))
        {
            trueBoard[xAxisBomb][zAxisBomb] = bombLocation;
        }
        else
        {
            int xAxisBomb = rand() % 5;
        
            int zAxisBomb = rand() % 5;

            i--;
        }
    }

    for(int k = 0; k < 5; k++)
    {
        for(int j = 0; j < 5; j++) // asettaa loput tyhjät paikat clearLocationeiksi
        {
            if(trueBoard[j][k] == moi)
            {
                trueBoard[j][k] = clearLocation;
            }
        }
    }
}

int main()
{

    srand(time(0));
    cout << "kerro pommien määrä mitä asetan, enintään 24" << endl;
    int a;
    cin >> a;
    if (a >= 25){
        return 1;
    }

    string trueBoard[5][5] =
    { 
        {moi, moi, moi, moi, moi},
        {moi, moi, moi, moi, moi},
        {moi, moi, moi, moi, moi},
        {moi, moi, moi, moi, moi},
        {moi, moi, moi, moi, moi}
    };
    createTable(a, trueBoard); // luo "a" määrän pommeja ja käyttää sitä lukua tuol funktios


    
	int i,j;
	
	cout<<"piirrän trueboardin bug testei varten rn:\n";
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			cout<<" "<<trueBoard[i][j];
		}
		cout<<endl;
	}



sleep(5);
return 0;

}