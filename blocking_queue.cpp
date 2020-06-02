#include "blocking_queue.h"


BlockingQueue::BlockingQueue(): closed(false){}

void BlockingQueue::push(std::string& s){
    std::unique_lock<std::mutex> uniq_l(mut);
    queue.push(s);
    condition.notify_all();
} 

std::string BlockingQueue::pop(){
    std::unique_lock<std::mutex> uniq_l(mut);
    while (queue.empty()){
        if (closed){
            return std::string();
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

