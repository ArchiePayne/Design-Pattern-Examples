#include <iostream>

class Singleton
{
public:
    static Singleton& GetInstance()
    {
        // Thread-safe in C++11 and later
        static Singleton instance;
        return instance;
    }

    // Deleted copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    void DoWork() const
    {
        std::cout << "Work Done!" << "\n";
    }

private:
    // Private constructor
    Singleton() 
    {
        std::cout << "Singleton Constructed!" << "\n";
    }

    // Optional: Private destructor to prevent external deletion
    ~Singleton() 
    {
        std::cout << "Singleton Destroyed!" << "\n";
    } 
};

int main()
{
    const auto& singletonObject = Singleton::GetInstance();
    singletonObject.DoWork();
}