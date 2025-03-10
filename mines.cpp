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

void clearSpace(int clearX,int clearY, string (&trueBoard)[5][5], string (&hiddenBoard)[5][5])
{
    if (trueBoard[clearX][clearY] == bombLocation)
        hiddenBoard[clearX][clearY] = bombLocation;

    else
        hiddenBoard[clearX][clearY] = clearLocation;
}

double getMulti(double bombAmt, double availableTileAmt)
{
    double multipros;
    double multi;


    multipros = (availableTileAmt - bombAmt) / 25;
    multipros = (multipros * 100);
    multi = 100 / (multipros);

    return multi;
}

int main()
{

    srand(time(0));
    cout << "kerro pommien määrä mitä asetan, enintään 24" << endl;

    int a,b;
    cin >> a; // pommien määrä
    b = a; // muunneltava pommien määrä
    int c = 25;
    

    if (a >= 25){ 
        return 1;
    }

    string trueBoard[5][5] = // luo oikean tablen johon ne pommit asetetaan createTable funktios
    { 
        {moi, moi, moi, moi, moi},
        {moi, moi, moi, moi, moi},
        {moi, moi, moi, moi, moi},
        {moi, moi, moi, moi, moi},
        {moi, moi, moi, moi, moi}
    };

    string hiddenBoard[5][5] = // luo pöydän joka näytetään pelaajalle
    { 
        {hidden, hidden, hidden, hidden, hidden},
        {hidden, hidden, hidden, hidden, hidden},
        {hidden, hidden, hidden, hidden, hidden},
        {hidden, hidden, hidden, hidden, hidden},
        {hidden, hidden, hidden, hidden, hidden}
    };

    createTable(a, trueBoard); // luo "a" määrän pommeja ja käyttää sitä lukua tuol funktios

    while(true)                 // main peli loop
    { 
        cout<<"pelilaudalla on " << a << " miinaa\n";

        int i,j;
        for(i=0;i<5;i++)        // piirtää hiddenboardin pelaajalle näkyväksi
        {
            for(j=0;j<5;j++)
            {
                cout<<hiddenBoard[i][j]<<"\t";
            }
            cout<<"\n"<<endl;
        }
        
        cout<< "Kerro laatan X kordinaatti jonka haluat avata, 1 - 5" << endl;
        int clearx,cleary;
        cin>>cleary;

        cout<< "Kerro laatan Y kordinaatti jonka haluat avata, 1 - 5" << endl;
        cin>>clearx;
        if(clearx >= 6 || cleary >= 6 || clearx <= 0 || cleary <= 0)
            return 2;

        clearx--;
        cleary--;
        
        clearSpace(clearx,cleary,trueBoard,hiddenBoard);


        // double multiplier =  // hankkii multiplierin, ottaa pommien määrän "b" ja turvallisten määrän "c"
        cout << "Vetokerroin on "<< getMulti(b,c)<< "x " << endl;
        c--; // vähentää valikoimasta yhen, piti laittaa c'n definaus alkuu jostai vitun syyst
        

        if(trueBoard[clearx][cleary] == bombLocation)
        {
            cout<< "räjähdit :(" << endl;

            for(i=0;i<5;i++)        // piirtää trueboardin pelaajalle näkyväksi häviön jälkeen
            {
                for(j=0;j<5;j++)
                {
                    cout<<trueBoard[i][j]<<"\t";
                }
                cout<<"\n"<<endl;
            }
            break;
        }
        
    }

    sleep(5);
    return 0;

}