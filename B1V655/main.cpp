#include <iostream>
#include <locale>

using namespace std;
void beolvas(int S[100][100],int P[100][100],int Min[100],int Ind[100],int &N,int &M);
void feladat(const int S[100][100],const int P[100][100],const int Min[100],const int Ind[100],int tomb[100], int N, int M, int &T);
void megszamlalas(const int tomb[100],int &T);
void kiir(const int tomb[100],int T);
int main()
{
    setlocale(LC_ALL,"HUN");
    int S[100][100],P[100][100];
    int Min[100];
    int N,M;
    int Ind[100];
    int tomb[100];
    int T=0;
    beolvas(S,P,Min,Ind,N,M);
    feladat(S,P,Min,Ind,tomb,N,M,T);
    kiir(tomb,T);
    return 0;

}
void beolvas(int S[100][100],int P[100][100],int Min[100],int Ind[100], int &N, int &M)
{
    do{
    cerr<<"Adja meg az indulok számát: ";    cin>>N;
    }while(N>100||N<1);
    do{
    cerr<<"Adja meg a versenyek számát: ";    cin>>M;
    }while(M>100||M<1);
    for(int i=0;i<M;i++){cerr<<"Elvárt pontszám az "<<i+1<<". versenyen: ";       do{ cin>>Min[i]; }while(Min[i]<0||Min[i]>50);}
    for(int i=0;i<M;i++){
        cerr<<"Adja meg a(z) "<<i+1<<". versenyen indulók számát: ";       do{cin>>Ind[i];}while(Ind[i]<1||Ind[i]>100);
        for(int j=0;j<Ind[i];j++){
            cerr<<"Adja meg az induló versenyzõ sorszámát: ";    do{cin>>S[i][j];}while(S[i][j]<1||S[i][j]>N);
            cerr<<"Adja meg az induló versenyzõ elért pontszámát: ";    do{cin>>P[i][j];}while(P[i][j]<0||P[i][j]>100);
        }
    }
}

void feladat(const int S[100][100],const int P[100][100],const int Min[100],const int Ind[100],int tomb[100], int N, int M,int &T)
{
    for(int i=0;i<100;i++)tomb[i]=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<Ind[i];j++){
            if(P[i][j]>=Min[i]&&tomb[(S[i][j])-1]!=-1)tomb[(S[i][j])-1]=1;
            if(P[i][j]<Min[i])tomb[(S[i][j])-1]=-1;
        }
    }
    megszamlalas(tomb,T);
}
void megszamlalas(const int tomb[100],int &T)
{
    for(int i=0;i<100;i++)if(tomb[i]==1)T++;
}
void kiir(const int tomb[100],int T)
{

    cerr<<"A versenyeken minimális pontszámot elért tanulók száma, és azok sorszáma növekvő sorrendben: "<<endl;
    cout<<T;
    for(int i=0;i<100;i++)if(tomb[i]==1)cout<<" "<<i+1;
}
