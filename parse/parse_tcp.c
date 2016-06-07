#include <stdio.h>
#include <string.h>
#include <netinet/tcp.h>
#include "parse_tcp.h"
#include "parse_http.h"

void parse_tcp(const u_char *sp, char *srcip, char *desip)
{
	struct tcphdr *tcp;
	tcp = (struct tcphdr *)sp;

	int srcport = ntohs(tcp -> source);
	int destport = ntohs(tcp -> dest);
	
	printf("IP ");
	printf("%s.", srcip);
	if(!isKnowPort(srcport))
	{
		printf("%u ", srcport);
	}
	printf("> %s.", desip);
	if(!isKnowPort(destport))
	{
		printf("%u ", destport);
	}

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

	if(srcport == TCP_HTTP || destport == TCP_HTTP)
	{
		parse_http(sp + sizeof(struct tcphdr));
	}
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

int isKnowPort(int port)
{
	int ret = 1;

	switch(port)
	{
		case TCP_FTP:
			printf("ftp ");
			break;
		case TCP_SSH:
			printf("ssh ");
			break;
		case TCP_TELNET:
			printf("telnet ");
			break;
		case TCP_SMTP:
			printf("smtp ");
			break;
		case TCP_DNS:
			printf("dns ");
			break;
		case TCP_HTTP:
			printf("http ");
			break;
		case TCP_MTA:
			printf("mta ");
			break;
		case TCP_POP3:
			printf("pop3 ");
			break;
		case TCP_RFC:
			printf("rfc ");
			break;
		case TCP_IMAP:
			printf("imap ");
			break;
		case TCP_SNMP:
			printf("snmp ");
			break;
		case TCP_HTTPS:
			printf("https ");
			break;
		case TCP_IMAPSSL:
			printf("imapssl ");
			break;
		default:
			ret = 0;
			break;
	}

	return ret;
}
