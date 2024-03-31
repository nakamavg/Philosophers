#include <stdio.h>
#include <sys/time.h>


int main()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("Seconds since Jan. 1, 1970: %ld\n", tv.tv_sec);
	printf("Microseconds: %ld\n", tv.tv_usec);
	return (0);
}