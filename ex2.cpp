#include <iostream>
#include <cstdlib>
#include <pthread.h>
#define NUM_THREADS  3
using namespace std;


void *PrintSentence(void *threadid)
{
    cout<<"Je suis le TRAITEMENT 1."<<endl<<"Je suis actif...\n" ;
    pthread_exit(NULL);
}


int main ()
{
    pthread_t TH1;
    int rc;
    char TT;
    int MyThreadID;
    
    cout << "--- TP 1 EXO 2 ---" << endl;
    
    rc = pthread_create(&TH1, NULL, PrintSentence, &MyThreadID);
    pthread_join (TH1, NULL);
    cout<<"The thread ID is: "<< MyThreadID<< endl;
    
    if (rc){
     cout << "Error:unable to create thread," << rc << endl;
     exit(-1);
    }
    
    cout<<"\n Program END "<<endl<<"write a letter to end your program\n";
    cin>>TT;
    pthread_exit(NULL);
    
    return 0;
}
