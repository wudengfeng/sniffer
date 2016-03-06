#include <stdio.h>
#include <netinet/udp.h>
#include "parse_udp.h"

void parse_udp(const u_char *sp)
{
	struct udphdr *udp;
	udp = (struct udphdr *)sp;

	printf("source : %u ", ntohs(udp -> source));
	printf("dest : %u\n", ntohs(udp -> dest));

	printf("len : %u ", udp -> len);
	printf("check : 0x%x\n", udp -> check);
}
