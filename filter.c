#include <pcap.h>
#include <stdio.h>
#include "filter.h" 

void filte(pcap_t *pd, char *str, bpf_u_int32 net)
{
	struct bpf_program filter;
	pcap_compile(pd, &filter, str, 0, net);
	pcap_setfilter(pd, &filter);
}
