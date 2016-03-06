objects = sniffer.o help.o dev.o parse_ethernet.o parse_ip.o parse_arp.o parse_tcp.o parse_icmp.o parse_udp.o
VPATH = parse
CFLAGS = -lpcap

sniffer : $(objects)
	cc $(CFLAGS) -o sniffer $(objects)
sniffer.o : help.h sniffer.h parse_ethernet.h
help.o : help.h
dev.o : dev.h
parse_ethernet.o : parse_ethernet.h parse_ip.h parse_arp.h
parse_ip.o : parse_ip.h parse_tcp.h parse_udp.h parse_icmp.h
parse_arp.o : parse_arp.h
parse_tcp.o : parse_tcp.h
parse_icmp.o : parse_icmp.h
parse_udp.o : parse_udp.h
.PHONY : clean
clean :
	rm -rf sniffer $(objects)
