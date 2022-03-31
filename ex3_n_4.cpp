// condition_variable::wait_for example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#define NUM_THREADS  3
using namespace std;

int value;


void *PrintSentence(void *value)
{
   cout<<"\nLa chaine transmise est : "<<(char*)value<<endl;
   pthread_exit(NULL);
}


void *Visualization(void *value)
{
    char* str = (char*)value;
    for(int i=0;i<strlen(str)/2;i++)
    {
        char temp=str[i];
        str[i]=str[strlen(str)-i-1];
        str[strlen(str)-i-1]=temp;
    }
   cout<<"La chaine inverse est : "<<str<<endl;
   pthread_exit(NULL);
}


void *Timer(void *value)
{
    time_t debut;
    time_t fin;
    do{
        time(&debut);
        time(&fin);
        while(fin - debut<5.0){
            time(&fin);
        }
        cout<<"chain (you have 5s)"<<endl;
    }while(1);
    pthread_exit(NULL);
}


void *Saisie(void *value)
{
    pthread_t TH_timer;
    int rc;
    char* TT = (char*)value;
    cout<<"chain (you have 5s)"<<endl;
    rc = pthread_create(&TH_timer, NULL, Timer, NULL);
    if (rc){
        cout << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }
    
    cin>>TT;
    pthread_cancel(TH_timer);
    pthread_exit(NULL);
}


int main ()
{
    cout << "--- TP 1 EXO 3/4 ---" << endl;
    pthread_t TH1,TH2,TH3;
    int rc1,rc2,rc3;

    char TT[150];    
    rc1 = pthread_create(&TH1, NULL, Saisie, &TT);
    pthread_join(TH1,NULL);
    if (rc1){
        cout << "Error:unable to create thread," << rc1 << endl;
        exit(-1);
    }
    rc2=pthread_create(&TH2, NULL, PrintSentence, &TT);
    pthread_join(TH2,NULL);
    if (rc1){
         cout << "Error:unable to create thread," << rc2 << endl;
         exit(-1);
    }
    rc3=pthread_create(&TH3, NULL, Visualization, &TT);
    pthread_join(TH3,NULL);
    if (rc3){
         cout << "Error:unable to create thread," << rc3 << endl;
         exit(-1);
    }
    // cout<<"\nFin du programme \nsaisir une lettre pour fermer\n";
    //pthread_exit(NULL);
    
    return 0;
}
