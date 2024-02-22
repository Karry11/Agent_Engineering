////
//// Created by 24536 on 2024/2/22.
////
//
//#include "SafeQueue.h"
//template <typename T>
////bool SafeQueue<T>::empty(){
////    std::unique_lock<std::mutex> lock(m_mutex_q);
////    return m_queue_q.empty();
////}
//
////template <typename T>
////int SafeQueue<T>::size(){
////    std::unique_lock<std::mutex> lock (m_mutex_q);
////    return m_queue_q;
////}
//
////template <typename T>
////void SafeQueue<T>::enqueue(T &t)
////{
////    std::unique_lock<std::mutex> lock(m_mutex_q);
////    m_queue_q.emplace(t);
////}
////template <typename T>
////bool SafeQueue<T>::dequeue(T &t)
////{
////    std::unique_lock<std::mutex> lock(m_mutex_q);
////    if (m_queue_q.empty())
////        return false;
////    t = std::move(m_queue_q.front());
////    m_queue_q.pop();
////    return true;
////}
//
//
//
