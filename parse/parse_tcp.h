#ifndef PARSE_TCP_H
#define PARSE_TCP_H

void print_flag(struct tcphdr *);
void parse_tcp(const u_char *, char *, char *);

#endif
