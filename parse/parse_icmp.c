#include <stdio.h>
#include <netinet/ip_icmp.h>
#include "parse_icmp.h"

void parse_icmp(const u_char *sp, char *srcip, char *desip)
{
	struct icmphdr *icmp;
	icmp = (struct icmphdr *)sp;

	printf("IP ");
	printf("%s > ", srcip);
	printf("%s ", desip);

	switch(icmp -> type)
	{
		case ICMP_ECHOREPLY:
			if(icmp -> code == 0)
			{
				printf("ICMP echo reply ");

				printf("id %u ", ntohs(icmp -> un.echo.id));
				printf("seq %u", ntohs(icmp -> un.echo.sequence));
			}
			break;
		case ICMP_DEST_UNREACH:
			icmp_unreach(icmp -> type);
			break;
		case ICMP_SOURCE_QUENCH:
			if(icmp -> code == 0)
			{
				printf("Quench");
			}
			break;
		case ICMP_REDIRECT:
			icmp_redirect(icmp -> type);
			break;
		case ICMP_ECHO:
			if(icmp -> code == 0)
			{
				printf("ICMP echo request ");
				printf("id %u ", ntohs(icmp -> un.echo.id));
				printf("seq %u", ntohs(icmp -> un.echo.sequence));
			}
			break;
		case ICMP_TIME_EXCEEDED:
			icmp_time_exceeded(icmp -> code);
			break;
		case ICMP_PARAMETERPROB:
			if(icmp -> code == 0)
			{
				printf("Bad IP Header");
			}
			else if(icmp -> code == 1)
			{
				printf("Lack Necessary Parameter");
			}
			break;
		case ICMP_TIMESTAMP:
			if(icmp -> code == 0)
			{
				printf("Time Stamp");
			}
			break;
		case ICMP_TIMESTAMPREPLY:
			if(icmp -> code == 0)
			{
				printf("Time Stamp Reply");
			}
			break;
		case ICMP_INFO_REQUEST:
			if(icmp -> code == 0)
			{
				printf("Information Request");
			}
			break;
		case ICMP_INFO_REPLY:
			if(icmp -> code == 0)
			{
				printf("Information Reply");
			}
			break;
		case ICMP_ADDRESS:
			if(icmp -> code == 0)
			{
				printf("Address Mask Request");
			}
			break;
		case ICMP_ADDRESSREPLY:
			if(icmp -> code == 0)
			{
				printf("Address Mask Reply");
			}
			break;
	}

//	printf("type : %u ", icmp -> type);
//	printf("code : %u ", icmp -> code);
//	printf("checksum : 0x%x\n", icmp -> checksum);
	
	printf("\n");
}

void icmp_unreach(u_int8_t type)
{
	switch(type)
	{
		case ICMP_NET_UNREACH:
			printf("Network Unreachable\n");
			break;
		case ICMP_HOST_UNREACH:
			printf("Host Unreachable\n");
			break;
		case ICMP_PROT_UNREACH:
			printf("Protocol Unreachable\n");
			break;
		case ICMP_PORT_UNREACH:
			printf("Port Unreachable\n");
			break;
		case ICMP_FRAG_NEEDED:
			printf("Fragmentation Needed / DF set\n");
			break;
		case ICMP_SR_FAILED:
			printf("Source Route failed\n");
			break;
		case ICMP_NET_UNKNOWN:
			printf("Network Unknown\n");
			break;
		case ICMP_HOST_UNKNOWN:
			printf("Host Unknown\n");
			break;
		case ICMP_HOST_ISOLATED:
			printf("Host Isolated\n");
			break;
		case ICMP_NET_ANO:
			printf("Net Ano\n");
			break;
		case ICMP_HOST_ANO:
			printf("Host Ano\n");
			break;
		case ICMP_NET_UNR_TOS:
			printf("Network Unreachable Tos\n");
			break;
		case ICMP_HOST_UNR_TOS:
			printf("Host Unreachable Tos\n");
			break;
		case ICMP_PKT_FILTERED:
			printf("Packet Filtered\n");
			break;
		case ICMP_PREC_VIOLATION:
			printf("Precedence Violation\n");
			break;
		case ICMP_PREC_CUTOFF:
			printf("Precedence Cut Off\n");
			break;
	}
}

void icmp_redirect(u_int8_t type)
{
	switch(type)
	{
		case ICMP_REDIR_NET:
			printf("Redirect Net\n");
			break;
		case ICMP_REDIR_HOST:
			printf("Redirect Host\n");
			break;
		case ICMP_REDIR_NETTOS:
			printf("Redirect Net For TOS\n");
			break;
		case ICMP_REDIR_HOSTTOS:
			printf("Redirect Host For TOS\n");
			break;
	}
}

void icmp_time_exceeded(u_int8_t type)
{
	switch(type)
	{
		case ICMP_EXC_TTL:
			printf("TTL Count Exceeded\n");
			break;
		case ICMP_EXC_FRAGTIME:
			printf("Fragment Reass Time Exceeded\n");
			break;
	}
}
