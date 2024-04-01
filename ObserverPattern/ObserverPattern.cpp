#include <iostream>
#include <chrono>
#include <algorithm>
#include <thread>
#include <memory>

using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

class TimeObserver
{
public:
    virtual void Update(std::chrono::system_clock::time_point time, std::chrono::system_clock::time_point startTime) = 0;
};

class Clock : public TimeObserver
{
    virtual void Update(std::chrono::system_clock::time_point time, std::chrono::system_clock::time_point startTime)
    {
        duration<double, std::milli> ms_double = time - startTime;
        std::cout << ms_double.count() << "ms\n";
    }
};

class TimeManager
{
public:
    void RegisterObserver(std::shared_ptr<TimeObserver> observer)
    {
        observerList.push_back(observer);
    };

    void RemoveObserver(std::shared_ptr<TimeObserver> observer)
    {
        std::erase(observerList, observer);
    };

    void NotifyObservers()
    {
        for (auto& observer : observerList)
        {
                observer->Update(time, startTime);
        }
    }

    void UpdateTime()
    {
        time = std::chrono::system_clock::now();
        NotifyObservers();
    }

private:
    std::vector<std::shared_ptr<TimeObserver>> observerList;
    std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
};

int main()
{
    TimeManager timeManager{};

    std::shared_ptr<TimeObserver> clockObserver = std::make_shared<Clock>();
    timeManager.RegisterObserver(clockObserver);

    // Print initial time reading
    timeManager.UpdateTime();

    // sleep for 1s
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // Create register a second observer
    std::shared_ptr<TimeObserver> clockObserver2 = std::make_shared<Clock>();
    timeManager.RegisterObserver(clockObserver2);

    // This should print twice as we have 2 observers, should be ~1000ms
    timeManager.UpdateTime();

    // Remove both observers
    timeManager.RemoveObserver(clockObserver);
    timeManager.RemoveObserver(clockObserver2);

    // nothing should print as we have no observers
    timeManager.UpdateTime();
}