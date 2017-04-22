 /**
 *
 *           demo for showing thread specific data
 *           4/21/2017
 *                               
 *
 */  
#include<stdio.h>  
#include<pthread.h>  
#include<string.h>  

pthread_key_t p_key;  
       
void func1()  
{  
	// data is shared  within all functions running in the same thread
	int *t = (int*)pthread_getspecific(p_key);
	printf("%d is runing in %s\n", *t, __func__);  

}  

void *thread_func(void *args)  
{  
    int i;
   
	pthread_setspecific(p_key,args);  

	int *t = (int*)pthread_getspecific(p_key);
	printf("%d is runing in %s\n",*t,__func__);  

	for (i=0; i<100; i++) {
		// modify the shared data 
		*t *= 100;
       
		func1();
		sleep(1);
	}
}

int main()  
{  
	pthread_t p1, p2;  
	int a=1;  
	int b=2;  
	pthread_key_create(&p_key,NULL);  
	pthread_create(&p1, NULL,thread_func,&a);  
	pthread_create(&p2, NULL,thread_func,&b);  
	pthread_join(p1, NULL);  
	pthread_join(p2, NULL);  
	return 0;  
}  
