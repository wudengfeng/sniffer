#include <stdio.h>
#include <string.h>
#include <netinet/tcp.h>
#include "parse_http.h"

void parse_http(const u_char *sp)
{

//	printf("HTTP lalala ~~~\n");
	
	int m = 0;
	unsigned char *buf = sp;
/*	
	while(m < (sizeof(sp) - 1))
	{
		printf("%02x", buf[m]);
		m ++;
		if(m % 16 == 0)
		{
			printf("\n");
		}
		else
		{
			printf(":");
		}
	}
	printf("%02x", buf[m]);
	printf("\n\n");
*/		
	printf("%s\n", sp);
}
