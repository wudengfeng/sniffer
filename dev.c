#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include "dev.h"

void getdev()
{
	char errbuf[PCAP_ERRBUF_SIZE];
	memset(errbuf, 0, sizeof(errbuf));

	pcap_if_t *alldevs;
	pcap_if_t *device;
	if(pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs : %s\n", errbuf);
		exit(EXIT_FAILURE);
	}
	if(alldevs == NULL)
	{
		fprintf(stderr, "No interfaces found !\n");
	}
	printf("device list : \n");
	int i = 0;
	for(device = alldevs; device != NULL; device = device -> next)
	{
		printf("%d. %s\t", i++, device -> name);
		if(device -> description)
		{
			printf("%s\n", device -> description);
		}
		else
		{
			printf("No Description\n");
		}
	}
	printf("\n");
	pcap_freealldevs(alldevs);
}
