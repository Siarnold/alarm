#ifndef ALARM_H
#define ALARM_H
#include <ctime>
#include <iostream>
#include <exception>
#include <Windows.h>
const int BEEP_COUNT = 15;
class Alarm{
public:
	//default constructor
	Alarm(){}
	//constructor
	Alarm(int s, int m = 0, int h = 0) {
		if(s<0) throw std::range_error("The second input is out of range!");
		if(m<0) throw std::range_error("The minute input is out of range!");
		second = s;
		minute = m;
		hour = h;
	}


	//Initialize
	void Init(){
        int s, m = 0, h = 0;
        std::cout<<"Please initialize alarm with second, minute, hour. The minute and hour can be default."<<std::endl;
        
        std::cin>>s;
		if(s<0) throw std::range_error("The second input is out of range!");
        if(std::cin.get()!='\n'){
            std::cin>>m;
            if(m<0) throw std::range_error("The minute input is out of range!");
            if(std::cin.get()!='\n'){
                std::cin>>h;
                if(h<0) throw std::range_error("The hour input is out of range!");
            }
        }
        
		second = s;
		minute = m;
		hour = h;
	}
	

	//Run
	void Run(){
		std::cout<<"It will beep in "<<hour<<" hour(s) "<<minute<<" minute(s) "<<second<<" second(s)."<<std::endl;
        Beep(2);
        std::cout<<"The alarm now starts."<<std::endl;
		unsigned int ms = hour * 3600 + minute * 60 + second;
		ms *= 1000;
        
		Sleep(ms);
		Beep();
	}
private:
	int hour;
	int minute;
	int second;


	//Beep
	void Beep(int count = BEEP_COUNT){
		for(int i=0;i<count;i++){
			Sleep(1000);
			std::cout<<"\a";
		}
	}
};
#endif