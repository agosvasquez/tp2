#ifndef THREAD_H
#define THREAD_H

#include <thread>

class Thread {
public:
	Thread();
	void start();
	void join();
	virtual void run() = 0;
	virtual ~Thread();
	Thread(const Thread&) = delete;
	Thread& operator=(const Thread&) = delete;
private:
	std::thread thread;
};

#endif 
