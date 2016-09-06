//Alarm.cpp
#include "alarm.h"
using namespace std;
int main(){
    Alarm *alarm = new Alarm;
    try{
    alarm -> Init();
    alarm -> Run();
    }catch(range_error &e){
        cout<<"Range error: "<<e.what()<<endl;
    }
    delete alarm;
    return 0;
}