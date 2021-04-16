#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage: %s [IP ADDRESS | DOMAIN NAME]\n", argv[0]);
    exit(1);
  }

  /* struct in_addr {
   *   unsigned int s_addr;
   * };
   */
  struct in_addr addr;

  /* struct hostent {
   *   char *h_name;        // official domain name of host
   *   char **h_aliases;    // null-terminated array of domain names
   *   int  h_addrtype;     // host address type (AF_INET)
   *   int  h_length;       // length of an address, in bytes
   *   char **h_addr_list;  // null-terminated array of in_addr structs
   * };
   */
  struct hostent *hostp;

  /* We will use this to iterate over the h_aliases and h_addr_list.
   */
  char **pp;

  /* Try to get the hostp entry by address. */
  if (inet_aton(argv[1], &addr) != 0) {
    hostp = gethostbyaddr(&addr, sizeof(addr), AF_INET);
  } else {
    /* If that fails, we will try by hostname. */
    hostp = gethostbyname(argv[1]);
  }

  /* Exit if there is no entry. */
  if (hostp == NULL) {
    printf("No entry.\n");
    exit(0);
  }

  printf("official hostname: %s\n", hostp->h_name);

  // Iterate over the alises:
  for (pp = hostp->h_aliases; *pp != NULL; pp++) {
    printf("alias: %s\n", *pp);
  }

  // Iterate over the addresses:
  for (pp = hostp->h_addr_list; *pp != NULL; pp++) {
    addr.s_addr = ((struct in_addr *)*pp)->s_addr;
    printf("address: %s\n", inet_ntoa(addr));
  }
}
