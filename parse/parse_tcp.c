#include <stdio.h>
#include <string.h>
#include <netinet/tcp.h>
#include "parse_tcp.h"

void parse_tcp(const u_char *sp, char *srcip, char *desip)
{
	struct tcphdr *tcp;
	tcp = (struct tcphdr *)sp;
	
	printf("IP ");
	printf("%s.", srcip);
	printf("%u > ", ntohs(tcp -> source));
	printf("%s.", desip);
	printf("%u ", ntohs(tcp -> dest));

	print_flag(tcp);

	if(tcp -> syn == 1)
	{
		printf("seq %u ", ntohs(tcp -> seq));
	}
	if(tcp -> ack == 1)
	{
		printf("ack %u ", ntohs(tcp -> ack_seq));
	}

	printf("win %u", ntohs(tcp -> window));

	printf("\n");
}

void print_flag(struct tcphdr *tcp)
{
	int flag = 0;
	printf("Flag [");
	if(tcp -> syn == 1)
	{
		printf("S");
		flag ++;
	}
	if(tcp -> fin == 1)
	{
		printf("F");
		flag ++;
	}
	if(tcp -> rst == 1)
	{
		printf("R");
		flag ++;
	}
	if(tcp -> psh == 1)
	{
		printf("P");
		flag ++;
	}

	if(flag == 0)
	{
		printf(".");
	}
	printf("] ");
}
