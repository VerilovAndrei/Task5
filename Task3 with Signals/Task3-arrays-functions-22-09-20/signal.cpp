#include "signal.h"
#include <math.h>
#include <stddef.h>
#include <iostream>

Signal::Signal()
{
    freqVals = new double[size];
    std::fill(freqVals,freqVals+size-1,0.0);
}

Signal::Signal(size_t size) : size(size)
{
    freqVals = new double[size];
    std::fill(freqVals,freqVals+size,0.0);
}

Signal::Signal(size_t size, double discr_freq) : size(size),discr_freq(discr_freq)
{
    freqVals = new double[size];
    std::fill(freqVals,freqVals+size,0.0);
}



void Signal::resize(size_t newSize)
{
    double* PFreqVals = freqVals;
    freqVals = new double[newSize];

    std::fill(freqVals,freqVals + newSize,0.0);
    std::copy(PFreqVals, PFreqVals + size ,  freqVals);

    size = newSize;
    delete[] PFreqVals;
}

double Signal::operator[](unsigned int index)
{
    return freqVals[index];
}

Signal Signal::operator +(Signal signal)
{
    size_t biggestSize = std::max(size, signal.size);
    Signal newSignal = Signal(biggestSize);

    for(auto i = 0; i < biggestSize; i++)
        newSignal.freqVals[i] = freqVals[i] + signal.freqVals[i];

    return newSignal;
}

Signal Signal::operator -(Signal signal)
{
    auto biggestSize = std::max(size, signal.size);
    Signal newSignal = Signal(biggestSize);

    for(int i = 0; i < biggestSize; i++)
        newSignal.freqVals[i] = freqVals[i] - signal.freqVals[i];
    return newSignal;
}

Signal Signal::operator +=(Signal signal)
{
    auto biggestSize = std::max(size, signal.size);
    resize(biggestSize);

    for(int i = 0; i < biggestSize; i++)
        freqVals[i] = freqVals[i] + signal.freqVals[i];

    return *this;
}

Signal Signal::operator -=(Signal signal)
{
    size_t biggestSize = std::max(size, signal.size);
    resize(biggestSize);

    for(int i = 0; i < size; i++)
        freqVals[i] = freqVals[i] - signal.freqVals[i];

    return *this;
}

Signal Signal::operator +=(double d)
{
    for(int i = 0; i < size; i++)
        freqVals[i] = freqVals[i] + d;

    return *this;
}

Signal Signal::operator -=(double d)
{
    for(int i = 0; i < size; i++)
        freqVals[i] = freqVals[i] - d;

    return *this;
}

std::ofstream& operator<<(std::ofstream& stream,  Signal& signal)
{
    stream  << '\n' << signal.discr_freq<< '\n' << signal.size << '\n';
    for(int i  = 0; i < signal.size; i++)
        stream << signal.freqVals[i] << '\n';
    return stream;
}

std::ifstream& operator>>(std::ifstream& stream,  Signal& signal)
{
    stream >> signal.discr_freq >> signal.size;

    for(int i  = 0; i < signal.size; i++)
        stream >> signal.freqVals[i];
    return stream;
}
