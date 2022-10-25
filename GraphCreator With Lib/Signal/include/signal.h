#ifndef SIGNAL_H
#define SIGNAL_H
#include <stddef.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Signal_global.h"

class SIGNAL_EXPORT Signal
{
    friend std::ofstream& operator<<(std::ofstream& stream,  Signal& signal);

    friend std::ifstream& operator>>(std::ifstream& stream, Signal& signal);

    size_t size = 10;
    double discr_freq = 10000;

    public:
        double* freqVals = nullptr;


        Signal();
        Signal(size_t);
        Signal(size_t,double);
        //Signal(size_t s,double f) : size(s),freq(f){};

        void resize(size_t);
        size_t getSize(){return size;}
        double getFreq(){return discr_freq;}


        double operator [](unsigned int);
        Signal operator +(Signal);
        Signal operator -(Signal);
        Signal operator +=(Signal);
        Signal operator -=(Signal);
        Signal operator +=(double);
        Signal operator -=(double);


//        ~Signal();

};

#endif // SIGNAL_H
