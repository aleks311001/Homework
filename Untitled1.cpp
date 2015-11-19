#include <stdlib.h>


#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED

#include "defs.h"
#include "smart_ptr.h"
#include <vector>

NAMESPACE_Cornu

//This header file defines the stages and base classes for algorithms in the fitting pipeline.
//Fitting proceeds in stages, each one having access to the outputs of all the previous stages
//through the Fitter class.

enum AlgorithmStage
{
    SCALE_DETECTION,
    CURVE_CLOSING,
    CORNER_DETECTION,
    RESAMPLING,
    NUM_ALGORITHM_STAGES
};

struct AlgorithmOutputBase : public smart_base
{
};

SMART_TYPEDEFS(AlgorithmOutputBase);

template<int AlgStage>
struct AlgorithmOutput : public AlgorithmOutputBase
{
};

class Fitter;

template<int AlgStage>
class Algorithm
{
};

class AlgorithmBase
{
public:
    virtual std::string name() const { return "Default"; }
    virtual std::string stageName() const = 0;
    virtual AlgorithmOutputBasePtr run(const Fitter &) = 0;

    static int numAlgorithmsForStage(AlgorithmStage stage) { return _getAlgorithms()[stage].size(); }
    static AlgorithmBase *get(AlgorithmStage stage, int algorithm) { return _getAlgorithms()[stage][algorithm]; }

protected:
    static const std::vector<std::vector<AlgorithmBase *> > &_getAlgorithms();
    static void _addAlgorithm(int stage, AlgorithmBase *algorithm);

private:
    static bool _initializationFinished;
    static void _initialize();
    static std::vector<std::vector<AlgorithmBase *> > _algorithms;
};

template<int AlgStage>
class AlgorithmBaseTemplate : public AlgorithmBase
{
public:
    //override
    AlgorithmOutputBasePtr run(const Fitter &fitter)
    {
        smart_ptr<AlgorithmOutput<AlgStage> > out = new AlgorithmOutput<AlgStage>();
        _run(fitter, *out);
        return out;
    }

    static std::vector<std::string> names()
    {
        std::vector<std::string> out;
        for(int i = 0; i < (int)_getAlgorithms().size(); ++i)
            out.push_back(_getAlgorithms()[AlgStage][i]->name());

        return out;
    }

protected:
    AlgorithmBaseTemplate()
    {
        _addAlgorithm(AlgStage, this);
    }

    virtual void _run(const Fitter &fitter, AlgorithmOutput<AlgStage> &out) = 0;
};

END_NAMESPACE_Cornu

#endif //ALGORITHM_H_INCLUDED



int correct( int *arr, int size )
{
    while (--size > 0)
        if (arr[size - 1] > arr[size])
            return 0;
    return 1;
}
void shuffle( int *arr, int size )
{
    int i;
    for (i = 0; i < size; i++)
        swap(arr + i, arr + (rand() % size));
}
void bogoSort( int *arr, int size )
{
    while (!correct(arr, size))
        shuffle(arr, size);
}

using namespace std;

int main ()
{
int arr [11] = {15, 36, 346, 47 ,35 ,2346 , 364, 364, 36, 345, 3456};
bogoSort (arr, 11);
return (0);
}

