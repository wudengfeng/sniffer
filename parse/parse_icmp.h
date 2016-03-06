#ifndef PARSE_ICMP_H
#define PARSE_ICMP_H

void parse_icmp(const u_char *, char *, char *);
void icmp_unreach(u_int8_t);
void icmp_redirect(u_int8_t);
void icmp_time_exceeded(u_int8_t);

#endif
