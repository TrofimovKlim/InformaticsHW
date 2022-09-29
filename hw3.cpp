#include<iostream>
#include<vector>
#include<set>
#include<array>
#include<chrono>
#include<algorithm>

class Timer
{
public:
    using clock_t = std::chrono::steady_clock;
    using time_point_t = clock_t::time_point;
    Timer() : m_begin(clock_t::now()), duration(0) {}
    ~Timer() {
        this->pause();
        std::cout << duration << " milliseconds" << std::endl;
    }
    
    void pause() {
        auto end = clock_t::now();
        duration += std::chrono::duration_cast <std::chrono::milliseconds> (end - m_begin).count();
    }
    
    void goon() {
        m_begin = clock_t::now();
    }
private:
    time_point_t m_begin;
    int duration;
};

int main()
{
    srand(0);
    std::array <int, 1600000> a;
    for (int i = 0; i < a.size(); ++i)
        a[i] = rand();
    std::cout << "n=" << a.size() << std::endl;
    std::sort(a.begin(), a.end());
    {
        std::set <int> s;
        Timer t;
        for (int i = 0; i < a.size(); ++i)
            s.insert(a[i]);
        t.pause();
        std::cout << "set time = ";
    }
    {
        std::vector <int> v;
        Timer t;
        for (int i = 0; i < a.size(); ++i)
            v.push_back(a[i]);
        std::sort(v.begin(), v.end());
        t.pause();
        std::cout << "vector time = ";
    }
    return 0;
}

//n = 10000
//set time = 14 milliseconds
//vector time = 4 milliseconds

//n = 50000
//set time = 134 milliseconds
//vector time = 46 milliseconds

//n = 100000
//set time = 222 milliseconds
//vector time = 82 milliseconds
//
//n = 200000
//set time = 650 milliseconds
//vector time = 252 milliseconds

//n = 400000
//set time = 966 milliseconds
//vector time = 306 milliseconds

//n = 800000
//set time = 1516 milliseconds
//vector time = 454 milliseconds
