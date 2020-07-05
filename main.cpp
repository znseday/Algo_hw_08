#include <iostream>
#include <fstream>

//#include "sumsolver.h"

#include <vector>
#include <cstdint>

#include <iostream>

class SumSolver
{
protected:

    size_t N = 0;
    std::vector<uint64_t> a;

    bool Built = false;

    void Update(size_t i);

public:

    SumSolver() = delete;
    SumSolver(size_t N);

    void Add(size_t i, int x);

    void BuildTree();

    uint64_t CalcSum(size_t L, size_t R);

    friend std::ostream & operator<<(std::ostream &s, const SumSolver &ob)
    {
        for (const auto &x : ob.a)
        {
            s << x << "  ";
        }


        return s;
    }

};

#include <cmath>
//#include "sumsolver.h"

using namespace std;

SumSolver::SumSolver(size_t _N)
{
    size_t p = ceil(log2(_N));

    N = pow(2, p);

    a.resize(2*N, 0);
}

void SumSolver::Add(size_t i, int x)
{
    a[i+N] = x;

    // перевычислять узлы сейчас или потом?
    if (Built)
        Update(i+N);
}

void SumSolver::Update(size_t i)
{
    while (i > 0)
    {
        i /= 2;
        a[i] = a[2*i] + a[2*i+1];
    }
}

uint64_t SumSolver::CalcSum(size_t L, size_t R)
{
    uint64_t res = 0;

    L += N;
    R += N;

    while (L <= R)
    {
        if ( L%2 )
            res += a[L];

        if ( !(R%2) )
            res += a[R];

        L = (L+1)/2;
        R = (R-1)/2;
    }

    return res;
}


void SumSolver::BuildTree()
{
//    cout << *this << endl; // для отладки


    for (size_t i = N-1; i >= 1; --i)
        a[i] = a[2*i] + a[2*i+1]; // Можно попробовать заменить на произвольную ассоциативную ф-цию

    Built = true;
}





using namespace std;

int main()
{
    size_t N, K;
    ifstream f_in("sum.in");
    if (!f_in)
    {
        perror("sum.in");
        exit(0);
    }

    f_in >> N >> K;

    SumSolver sumSolver(N);

    char cmd;
    size_t p1, p2;

    bool firstQ = true;

    ofstream f_out("sum.out");
    if (!f_out)
    {
        perror("sum.out");
        exit(0);
    }

    for (size_t i = 0; i < K; ++i)
    {
        f_in >> cmd >> p1 >> p2;

        switch (cmd)
        {
        case 'A':
            sumSolver.Add(p1-1, p2);
        break;

        case 'Q':
            if (firstQ)
            {
                firstQ = false;
                sumSolver.BuildTree();
            }
            f_out << sumSolver.CalcSum(p1-1, p2-1) << "\n";

        break;

        default:
            cerr << "Unknown command" << endl;
            exit(0);
        }
    }

    //cout << sumSolver << endl;

    f_in.close();
    f_out.close();

    return 0;
}
