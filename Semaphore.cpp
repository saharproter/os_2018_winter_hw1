//
// Created by danielle on 21/12/2018.
//

#include "Headers.hpp"
#include "Semaphore.hpp"


Semaphore::Semaphore(): count(0), mutex(), cond() {} // Constructs a new
// semaphore with a counter of 0
Semaphore::Semaphore(unsigned val): count(val), mutex(), cond() {}
 // Constructs a new semaphore with a counter of val

//up = post, down = wait
void Semaphore::up(){
    pthread_mutex_lock(this->mutex);
    this->count++;
    pthread_cond_brodcast(this->cond);
    pthread_mutex_unlock(this->mutex);
} // Mark: 1 Thread has left the critical section

void Semaphore::down(){
    pthread_mutex_lock(this->mutex);
    while (this->count == 0){
        pthread_cond_wait(this->cond, this->mutex);
    }
    this->count--;
    pthread_mutex_unlock(this->mutex);
} // Block untill counter >0, and mark - One thread has
// entered the critical section.