
#pragma once

#include <stdio.h>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

template<class T>
class SafeQueue {
public:
    void push(const T& val) {
        std::lock_guard<std::mutex> lock(_m);
        _q.push(val);
        _cv.notify_one();
    }

    bool pop(T& val) {
        std::unique_lock<std::mutex> lock(_m);
        _cv.wait(lock, [this] { return !_q.empty() || stop; });
        if (!_q.empty()) {
            val = _q.front();
            _q.pop();
            return true;
        }
        return false;
    }

    void signalStop() {
        std::lock_guard<std::mutex> lock(_m);
        stop = true;
        _cv.notify_all();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(_m);
        return _q.empty();
    }

private:
    std::queue<T> _q;
    mutable std::mutex _m;
    std::condition_variable _cv;
    bool stop = false;  // Signal to stop all threads
};


