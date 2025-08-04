//Note: This is EXTREMELY fast (reads 10^7 integers in 0.1s), twice the speed of fread and fwrite.
//BUT, it is for fast input only
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include <cstdio>

char *pc;

void rd(int &x) {
  bool neg = false;
  x = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') neg = true;
    ch = *pc++;
  }
  if (neg) {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + ('0' - ch);
      ch = *pc++;
    }
  } else {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + (ch - '0');
      ch = *pc++;
    }
  }
}

int main() {
  int fd = 0;  // read from stdin
  // int fd = open("filename.in", O_RDONLY); // read from files
  struct stat state;
  fstat(fd, &state);  // gets input file size
  pc = (char *)mmap(NULL, state.st_size, PROT_READ, MAP_PRIVATE, fd, 0); //maps input file size to system memory
  int n, x, sum = 0;
  rd(n);
  while (n--) {
    rd(x);
    sum += x;
  }
  printf("%d\n", sum); //output to stdout
  // FILE* OUTPUT = fopen("filename.out","w");
  // fprintf(OUTPUT, "%d\n", sum); output to file
}