#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H
#include<condition_variable>
#include<mutex>
#include<queue>
#include<string>

class BlockingQueue{
private:
    bool closed;
    std::mutex mut;
    std::condition_variable condition;
public:
    std::queue<std::string> queue;
    BlockingQueue();
    ~BlockingQueue();
    void push(std::string s);
    std::string pop();
    void close();
};

#endif