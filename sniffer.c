#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <pcap.h>
#include <net/ethernet.h>

#include "sniffer.h"
#include "help.h"
#include "filter.h"
#include "parse/parse_ethernet.h"

int i = 0;

void dump_packet(u_char *user, const struct pcap_pkthdr *h, const u_char *sp)
{
	int m = 0;
	unsigned char *buf = sp;

	/*
	while(m < (h -> len - 1))
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

	parse_ethernet(sp);
}

int main(int argc, char *argv[])
{
//	if(argc < 2)
//	{
//		printf("No Argument\n");
//		gethelp();
//		return 0;
//	}

	char *dev, *strfilter;
	char errbuf[PCAP_ERRBUF_SIZE];
	bpf_u_int32 net;
	bpf_u_int32 mask;
	static pcap_t *pd;
	pcap_handler callback;
	callback = dump_packet;

	int op;
	while((op = getopt_long(argc, argv, optstring, longopts, NULL)) != -1)
	{
		switch(op)
		{
			case 'd':
				printf("d : %s\n", optarg);
				dflag ++;
				break;
			case 'g':
				gflag ++;
				break;
			case 'h':
				hflag ++;
				break;
			case 'i':
				dev = optarg;
				iflag ++;
				break;
			case 'p':
				printf("p : %s\n", optarg);
				strfilter = optarg;
				pflag ++;
				break;
			case 's':
				printf("s : %s\n", optarg);
				sflag ++;
				break;
			default:
				return 0;
		}
	}

	if(gflag)
	{
		getdev();
		return 0;
	}
	if(hflag)
	{
		gethelp();
		return 0;
	}
	if(!iflag)
	{
		dev = pcap_lookupdev(errbuf);
	}
	
	pd = pcap_create(dev, errbuf);
	pcap_lookupnet(dev, &net, &mask, errbuf);
	pd = pcap_open_live(dev, 1500, 1, -1, errbuf);
	if(pflag)
	{
		filte(pd, strfilter, net);
	}
	pcap_loop(pd, -1, callback, NULL);
	return 0;
}
