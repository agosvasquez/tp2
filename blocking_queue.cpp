#include "blocking_queue.h"


class ClosedExeption: public std::exception{
public:
    const char*closed(){
        return "Queue is closed";
    }
};

BlockingQueue::BlockingQueue(): closed(false){}

void BlockingQueue::push(std::string s){
    std::unique_lock<std::mutex> uniq_l(mut);
    queue.push(s);
    condition.notify_all();
} 

std::string BlockingQueue::pop(){
    std::unique_lock<std::mutex> uniq_l(mut);

    while(queue.empty()){
        if(closed){
            throw ClosedExeption();
        }
        condition.wait(uniq_l);
    }
    std::string s = queue.front();
    queue.pop();
    return s;
}

void BlockingQueue::close(){
    std::unique_lock<std::mutex> unique_l(mut);
    closed = true;
    condition.notify_all();
}

BlockingQueue::~BlockingQueue(){}

