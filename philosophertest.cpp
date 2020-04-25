#include "header.h"
pthread_mutex_t chopstick1, chopstick2, chopstick3, chopstick4, chopstick0;

void* zhexuejia1(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&chopstick0);
        printf( "哲学家1拿到左边的筷子\n");
        pthread_mutex_lock(&chopstick1);
        printf( "哲学家1拿到右边的筷子\n");
        printf( "哲学家1开始吃饭\n");
        sleep(2);
        pthread_mutex_unlock(&chopstick1);
        printf( "哲学家1放下右边的筷子\n");
        pthread_mutex_unlock(&chopstick0);
        printf( "哲学家1放下左边的筷子\n");
        printf( "哲学家1开始思考\n");
        sleep(2);
    }
    

}
void* zhexuejia2(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&chopstick1);
        printf( "哲学家2拿到左边的筷子\n");
        pthread_mutex_lock(&chopstick2);
        printf( "哲学家2拿到右边的筷子\n");
        printf( "哲学家2开始吃饭\n");
        sleep(2);
        pthread_mutex_unlock(&chopstick2);
        printf( "哲学家2放下右边的筷子\n");
        pthread_mutex_unlock(&chopstick1);
        printf( "哲学家2放下左边的筷子\n");
        printf( "哲学家2开始思考\n");
        sleep(2);
    }
}
void* zhexuejia3(void* arg)
{
     while (1)
    {
        pthread_mutex_lock(&chopstick2);
        printf( "哲学家3拿到左边的筷子\n");
        pthread_mutex_lock(&chopstick3);
        printf( "哲学家3拿到右边的筷子\n");
        printf( "哲学家3开始吃饭\n");
        sleep(2);
        pthread_mutex_unlock(&chopstick3);
        printf( "哲学家3放下右边的筷子\n");
        pthread_mutex_unlock(&chopstick2);
        printf( "哲学家3放下左边的筷子\n");
        printf( "哲学家3开始思考\n");
        sleep(2);
    }
}
void* zhexuejia4(void* arg)
{
     while (1)
    {
        pthread_mutex_lock(&chopstick3);
        printf( "哲学家4拿到左边的筷子\n");
        pthread_mutex_lock(&chopstick4);
        printf( "哲学家4拿到右边的筷子\n");
        printf( "哲学家4开始吃饭\n");
        sleep(2);
        pthread_mutex_unlock(&chopstick4);
        printf( "哲学家4放下右边的筷子\n");
        pthread_mutex_unlock(&chopstick3);
        printf( "哲学家4放下左边的筷子\n");
        printf( "哲学家4开始思考\n");
        sleep(2);
    }
}
void* zhexuejia5(void* arg)
{
     while (1)
    {
        pthread_mutex_lock(&chopstick4);
        printf( "哲学家5拿到左边的筷子\n");
        pthread_mutex_lock(&chopstick0);
        printf( "哲学家5拿到右边的筷子\n");
        printf( "哲学家5开始吃饭\n");
        sleep(2);
        pthread_mutex_unlock(&chopstick0);
        printf( "哲学家5放下右边的筷子\n");
        pthread_mutex_unlock(&chopstick4);
        printf( "哲学家5放下左边的筷子\n");
        printf( "哲学家5开始思考\n");
        sleep(2);
    }
}




void philosopher() {
    pthread_mutex_init(&chopstick1, nullptr);
    pthread_mutex_init(&chopstick2, nullptr);
    pthread_mutex_init(&chopstick3, nullptr);
    pthread_mutex_init(&chopstick4, nullptr);
    pthread_mutex_init(&chopstick0, nullptr);
    pthread_t t1,t2,t3,t4,t5;
    pthread_create(&t1, nullptr, zhexuejia1, nullptr);
    pthread_create(&t2, nullptr, zhexuejia2, nullptr);
    pthread_create(&t3, nullptr, zhexuejia3, nullptr);
    pthread_create(&t4, nullptr, zhexuejia4, nullptr);
    pthread_create(&t5, nullptr, zhexuejia5, nullptr);
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    pthread_join(t3, nullptr);
    pthread_join(t4, nullptr);
    pthread_join(t5, nullptr);
}