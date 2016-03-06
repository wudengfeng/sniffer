#ifndef SNIFFER_H
#define SNIFFER_H

#include <pcap.h>

//no_argument
//required_argument :
//optional_argument ::
const char *optstring="d:ghi:p:s:";
const struct option longopts[] = 
{
	{"destination", required_argument, NULL, 'd'},
	{"getdev", no_argument, NULL, 'g'},
	{"help", no_argument, NULL, 'h'},
	{"interface", required_argument, NULL, 'i'},
	{"protocol", required_argument, NULL, 'p'},
	{"source", required_argument, NULL, 's'}
};

int dflag = 0;
int gflag = 0;
int hflag = 0;
int iflag = 0;
int pflag = 0;
int sflag = 0;

static void dump_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

#endif
