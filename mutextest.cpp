#include "header.h"
int i;

pthread_mutex_t lock;
pthread_cond_t cond;


void* func1(void* arg)
{

    pthread_mutex_lock(&lock);
    printf( "线程1加锁成功\n");
   
    ++i;
  
    printf( "线程1退出临界区\n");
    pthread_cond_signal(&cond);
    printf( "线程1发出信号\n");
    pthread_mutex_unlock(&lock);
    
}

void* func2(void* arg)
{

    pthread_mutex_lock(&lock);
    printf( "线程2加锁成功\n");
    printf( "线程2等待条件变量...\n");
    pthread_cond_wait(&cond, &lock);
    --i;
    printf( "线程2退出临界区\n");
    pthread_mutex_unlock(&lock);
    
}

void mute_test() {

    pthread_t t1, t2;
    pthread_mutex_init(&lock, nullptr);
    pthread_cond_init(&cond, nullptr);
    pthread_create(&t2, nullptr, func2, nullptr);
    sleep(2);
    pthread_create(&t1, nullptr, func1, nullptr);

    
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

   
    printf("%d\n", i) ;
}