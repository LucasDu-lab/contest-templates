#include <iostream>
#include <cassert>
//extra headers
using namespace std;
const int BUF_SZ = 1 << 15;

inline namespace Input {
    char buf[BUF_SZ];//buffer for reading from stdin
    int pos;
    int len;
    char next_char() {
        if (pos == len) {
            pos = 0;
            len = (int)fread(buf, 1, BUF_SZ, stdin);//if reading from file,change stdin to a FILE pointer (FILE*)
            //reads BUF_SZ bytes at a time from stdin to buf, each variable is one byte
            if (!len) { return EOF; }
        }
        return buf[pos++];
    }
    //adding #define int long long will make this function read in a long long, but remember to change the function's name

    int read_int() {
        int x;
        char ch;
        int sgn = 1;
        while (!isdigit(ch = next_char())) {
            if (ch == '-') { sgn *= -1; }
        }//process '-' sign
        x = ch - '0';
        while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
        return x * sgn;
    }
}  // namespace Input
inline namespace Output {
    char buf[BUF_SZ];
    int pos;

    void flush_out() {
        fwrite(buf, 1, pos, stdout);
        pos = 0;
    }

    void write_char(char c) {
        if (pos == BUF_SZ) { flush_out(); }
        buf[pos++] = c;
    }

    void write_int(int x) {//writes \n after each call, customize as needed
        static char num_buf[100];
        if (x < 0) {
            write_char('-');
            x *= -1;
        }
        int len = 0;
        for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
        write_char((char)('0' + x));
        while (len) { write_char(num_buf[--len]); }
        write_char('\n');// customize to write space or other characters as needed
    }

    // auto-flush output when program exits
    void init_output() { assert(atexit(flush_out) == 0); }
    void write_string(string &x){
        for(char c:x) write_char(c);
        write_char('\n');
    }
}
//note: mixing this with regular cin/cout or scanf/printf will cause undefined behavior