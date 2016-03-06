#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include "parse_ip.h"
#include "parse_tcp.h"
#include "parse_udp.h"
#include "parse_icmp.h"

void parse_ip(const u_char * sp)
{
	struct iphdr *ip;
	ip = (struct iphdr *)sp;

	struct in_addr src;
	struct in_addr des;
	char srcip[16];
	char desip[16];

	/*
	printf("version : %u ", ip -> version);
	printf("headlen : %u ", ip -> ihl * 4);
	printf("tos : %u ", ip -> tos);
	printf("len : %u\n", ip -> tot_len);

	printf("id : %u ", ip -> id);
	printf("frag_off : %u \n", ip -> frag_off);

	printf("ttl : %u ", ip -> ttl);
	printf("protocol : ");
	switch(ip -> protocol)
	{
		case IPPROTO_TCP:
			printf("TCP ");
			break;
		case IPPROTO_UDP:
			printf("UDP ");
			break;
		case IPPROTO_ICMP:
			printf("ICMP ");
			break;
		case IPPROTO_IGMP:
			printf("IGMP ");
			break;
	}
	printf("check : 0x%x\n", ip -> check);
	*/
	src.s_addr = ip -> saddr;
	des.s_addr = ip -> daddr;
	inet_ntop(AF_INET, (void*)&src, srcip, 16);
	inet_ntop(AF_INET, (void*)&des, desip, 16);
//	printf("saddr : %s ", srcip);
//	printf("daddr : %s\n", desip);
	
	switch(ip -> protocol)
	{
		case IPPROTO_TCP:
			parse_tcp(sp + sizeof(struct iphdr), srcip, desip);
			break;
		case IPPROTO_UDP:
	//		parse_udp(sp + sizeof(struct iphdr));
			break;
		case IPPROTO_ICMP:
			parse_icmp(sp + sizeof(struct iphdr), srcip, desip);
			break;
		case IPPROTO_IGMP:
	//		parse_igmp(sp + sizeof(struct iphdr));
			break;
	}
}
