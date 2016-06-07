#include <stdio.h>
#include <net/ethernet.h>
#include "parse_ethernet.h"
#include "parse_ip.h"
#include "parse_arp.h"

void parse_ethernet(const u_char *sp)
{
	int m = 0;
	u_char *p;
	u_int16_t type;
	struct ether_header *ethernet;
	ethernet = (struct ether_header *)sp;

	type = ntohs(ethernet -> ether_type);

	if(type == ETHERTYPE_IP)
	{
		parse_ip(sp + sizeof(struct ether_header));
	}
	else if(type == ETHERTYPE_ARP)
	{
		printf("Source MAC :");
		p = ethernet -> ether_dhost;
		m = 0;
		while(m < ETHER_ADDR_LEN - 1)
		{
			printf("%02x:", *p ++);
			m ++;
		}
		printf("%02x ", *p);

		printf("Destination MAC : ");
		p = ethernet -> ether_shost;
		m = 0;
		while(m < ETHER_ADDR_LEN -1)
		{
			printf("%02x:", *p ++);
			m ++;
		}
		printf("%02x\n", *p ++);
		parse_arp(sp + sizeof(struct ether_header));
	}
}
