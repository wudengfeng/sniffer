#ifndef PARSE_TCP_H
#define PARSE_TCP_H

void print_flag(struct tcphdr *);
void parse_tcp(const u_char *, char *, char *);
int isKnowPort(int);

#define TCP_FTP 21
#define TCP_SSH 22
#define TCP_TELNET 23
#define TCP_SMTP 25
#define TCP_DNS 53
#define TCP_HTTP 80
#define TCP_MTA 102
#define TCP_POP3 109
#define TCP_RFC 110
#define TCP_IMAP 143
#define TCP_SNMP 161
#define TCP_HTTPS 443
#define TCP_IMAPSSL 993

#endif
