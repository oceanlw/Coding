#include "pthread.h"
#include "stdio.h"

#define BSIZE   100

typedef struct {
    int buffer[BSIZE];
    int count;
    int put;
    int get;
    pthread_mutex_t mutex;
    pthread_cond_t more;
    pthread_cond_t less;
} PCBuffer;

void producer(PCBuffer *b, int item) 
{
    pthread_mutex_lock(&b->mutex);

    while (b->count >= BSIZE) {
        pthread_cond_wait(&b->less, &b->mutex);
    }

    b->buffer[b->put++] = item;
    b->put %= BSIZE;
    b->count++;

    pthread_cond_signal(&b->more);
    pthread_mutex_unlock(&b->mutex);
}

int consumer(PCBuffer *b)
{
    int item;

    pthread_mutex_lock(&b->mutex);

    while (b->count == 0) {
        pthread_cond_wait(&b->more, &b->mutex);
    }

    item = b->buffer[b->get++];
    b->get %= BSIZE;
    b->count--;

    pthread_cond_signal(&b->less);
    pthread_mutex_unlock(&b->mutex);

    return item;
}

int main(int args, char **argv)
{
    PCBuffer buf;
//    buf.more = PTHREAD_COND_INITIALIER;
//    buf.less = PTHREAD_COND_INITIALIER;

    pthread_mutex_init(&buf.mutex, NULL);
    pthread_cond_init(&buf.less, NULL);
    pthread_cond_init(&buf.more, NULL);
    buf.put = buf.get = buf.count = 0;

    producer(&buf, 1);
    int item = consumer(&buf);

    printf("consum %d\n", item);

    pthread_mutex_destroy(&buf.mutex);
    pthread_cond_destroy(&buf.less);
    pthread_cond_destroy(&buf.more);
}
